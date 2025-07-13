//
// Created by mela on 28.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(QWidget *parent, Service &service) : QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    loadData();
    connect(ui->veggieList, &QListWidget::itemClicked, this, &GUI::showVegetablesForFamily);
    connect(ui->searchButton, &QPushButton::clicked, this, &GUI::highlightFamily);
}

GUI::~GUI() {
    delete ui;
}

void GUI::loadData() {
    ui->veggieList->clear();
    auto veggies = this->service.getAllService();
    std::vector<std::string> veggieFamilies;
    for (auto veg: veggies) {
        if (std::find(veggieFamilies.begin(), veggieFamilies.end(), veg.getFamily()) == veggieFamilies.end()) {
            veggieFamilies.push_back(veg.getFamily());
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(veg.getFamily()));
            ui->veggieList->addItem(item);
        }
    }
}

void GUI::showVegetablesForFamily() {
    auto selectedItem = ui->veggieList->currentItem();
    if (!selectedItem) {
        return;
    }

    std::string selectedFamily = selectedItem->text().toStdString();
    auto veggies = this->service.getAllService();

    ui->displayList->clear();

    for (auto &veg: veggies) {
        if (veg.getFamily() == selectedFamily) {
            QString text = QString::fromStdString(veg.getName() + " – parts: " + veg.getParts());
            ui->displayList->addItem(new QListWidgetItem(text));
        }
    }
}

void GUI::highlightFamily() {
    ui->veggieList->clear();
    std::vector<std::string> veggieFamilies;

    std::string veggiename = ui->vegFamLine->text().toStdString();
    auto veggies = this->service.getAllService();
    for (auto &veg: veggies) {
        if (std::find(veggieFamilies.begin(), veggieFamilies.end(), veg.getFamily()) == veggieFamilies.end()) {
            veggieFamilies.push_back(veg.getFamily());
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(veg.getFamily()));
            if (veg.getName() == veggiename) {
                item->setBackground(Qt::green);
            }
            ui->veggieList->addItem(item);
        }
    }
    ui->partLine->setText(QString::fromStdString(this->service.getVegetableByName(veggiename).getParts()));
}
