//
// Created by mela on 24.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>

GUI::GUI(QWidget *parent, Service &service) :
    QWidget(parent), service(service),ui(new Ui::GUI) {
    ui->setupUi(this);
    loadData();
    connect(ui->addButton, &QPushButton::clicked, this, &GUI::addEquation);
    connect(ui->computeSolButton, &QPushButton::clicked, this, &GUI::solutions);
}

GUI::~GUI() {
    delete ui;
}

void GUI::loadData() {
    ui->equationList->clear();
    std::vector<Equation> equations = this->service.getAllService();

    for (auto eq: equations) {
        QListWidgetItem *item = new QListWidgetItem(eq.toString().c_str());
        if (this->service.realSol(eq)) {
            item->setBackground(QBrush(Qt::green));
        }
        ui->equationList->addItem(item);
    }
}

void GUI::addEquation() {
    int a = ui->aLine->text().toInt();
    int b = ui->bInput->text().toInt();
    int c = ui->cLine->text().toInt();
    Equation eq(a, b, c);
    this->service.addEquation(eq);
    loadData();
}
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "Equation.h"

Equation GUI::parseEquation(const std::string &equationString) {

    // Step 1: Normalize the string by inserting '+' before '-' (to simplify splitting terms)
    std::string normalized;
    for (size_t i = 0; i < equationString.length(); ++i) {
        if (equationString[i] == '-' && i > 0 && equationString[i - 1] != '^') {
            normalized += '+';
        }
        normalized += equationString[i];
    }

    // Step 2: Remove all spaces
    normalized.erase(std::remove_if(normalized.begin(), normalized.end(), ::isspace), normalized.end());

    // Step 3: Split the normalized string into terms using '+' as delimiter
    std::stringstream ss(normalized);
    std::string term;

    double a = 0, b = 0, c = 0;

    while (std::getline(ss, term, '+')) {
        if (term.empty()) continue;

        // Step 4: Identify term type and extract coefficient
        if (term.find("x^2") != std::string::npos) {
            // Coefficient of x^2
            std::string coef = term.substr(0, term.find("x^2"));
            if (coef.empty() || coef == "+") a = 1;
            else if (coef == "-") a = -1;
            else a = std::stod(coef);

        } else if (term.find("x") != std::string::npos) {
            // Coefficient of x
            std::string coef = term.substr(0, term.find("x"));
            if (coef.empty() || coef == "+") b = 1;
            else if (coef == "-") b = -1;
            else b = std::stod(coef);

        } else {
            // Constant term
            c = std::stod(term);
        }
    }

    return Equation(a, b, c);
}

void GUI::solutions() {
    QListWidgetItem* selected = ui->equationList->currentItem();

    QString text = selected->text();
    Equation eq = parseEquation(text.toStdString());
    std::string sol = this->service.solutions(eq);
    ui->solutionLine->setText(QString::fromStdString(sol));
}

