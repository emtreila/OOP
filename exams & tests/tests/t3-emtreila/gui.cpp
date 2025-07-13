#include "gui.h"
#include "ui_GUI.h"
#include <QMessageBox>


GUI::GUI(QWidget *parent, Service &service) : QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    loadData();
    connect(ui->searchEdit, &QLineEdit::textChanged, this, &GUI::filterDocuments);
    connect(ui->bestmatchButton, &QPushButton::clicked, this, &GUI::showBestMatch);
}

GUI::~GUI() {
    delete ui;
}

void GUI::loadData() {
    ui->docList->clear();
    auto documents = service.getAllService();

    for (auto document: documents) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(document.toString().c_str()));
        ui->docList->addItem(item);
    }
}

void GUI::filterDocuments(const QString &text) {
    ui->docList->clear();
    std::string search = text.toStdString();

    auto documents = service.getAllService();
    for (auto &doc: documents) {
        if (doc.getName().find(search) != std::string::npos || doc.getKeywords().find(search) != std::string::npos) {
            QString itemText = QString::fromStdString(doc.toString());
            ui->docList->addItem(new QListWidgetItem(itemText));
        }
    }
}

void GUI::showBestMatch() {
    std::string search = ui->searchEdit->text().toStdString();
    auto documents = service.getAllService();
    Document bestMatch;
    double maxScore = -1;
    for (auto doc: documents) {
        double score = this->service.getScore(doc, search);
        if (score > maxScore) {
            maxScore = score;
            bestMatch = doc;
        }
    }
    QMessageBox::information(this, "Best Match", QString::fromStdString(bestMatch.toString3()));
}
