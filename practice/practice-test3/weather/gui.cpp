//
// Created by mela on 29.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"
#include <QErrorMessage>

GUI::GUI(QWidget *parent, Service &service): QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    populate_list();
    connect(ui->precipitationLineEdit, &QLineEdit::textChanged, this, &GUI::filter);
    connect(this->ui->pushButton, &QPushButton::clicked, this, &GUI::filterDescription);
}

GUI::~GUI() {
    delete ui;
}

void GUI::populate_list() {
    ui->weatherList->clear();
    std::vector<Weather> data = this->service.getAllService();
    for (auto weather: data) {
        QListWidgetItem *item = new QListWidgetItem(weather.toString().c_str());
        ui->weatherList->addItem(item);
    }
}

void GUI::filter() {
    this->ui->weatherList->clear();
    for (auto w: this->service.getAllService()) {
        if (w.getPrecipitation() < this->ui->precipitationLineEdit->text().toInt())
            this->ui->weatherList->addItem(QString::fromStdString(w.toString()));
    }
}

void GUI::filterDescription() {
    int total = 0;
    this->ui->filteredListWidget->clear();
    for (auto w: this->service.getFilterd()) {
        this->ui->filteredListWidget->addItem(QString::fromStdString(w.toString()));
        total += w.getEnd() - w.getStart();
    }
    this->ui->totalLineEdit->setText(QString::fromStdString(std::to_string(total)));
    if (total == 0) {
        QErrorMessage *error = new QErrorMessage();
        error->showMessage("No items found");
    }
}
