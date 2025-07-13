//
// Created by mela on 25.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(QWidget *parent, Service &service) : QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    loadData();
    connect(this->ui->allCarsButton, &QPushButton::clicked, this, &GUI::loadData);
    connect(this->ui->manufacterButton, &QPushButton::clicked, this, &GUI::manufactureCars);
}

GUI::~GUI() {
    delete ui;
}

void GUI::loadData() {
    this->ui->carList->clear();
    std::vector<Car> cars = this->service.getAllService();
    for (auto car : cars) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(car.toString().c_str()));
        item->setForeground(QBrush(QColor(QString::fromStdString(car.getColor()))));
        this->ui->carList->addItem(item);
    }
}

void GUI::manufactureCars() {
    std::string manufacturer = this->ui->nameLine->text().toStdString();
    std::vector<Car> cars = this->service.getCarsByManufacturer(manufacturer); // get cars by manufacturer
    this->ui->carList->clear(); // clear the list widget before adding new items
    for (auto car : cars) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(car.toString().c_str()));
        item->setForeground(QBrush(QColor(QString::fromStdString(car.getColor()))));
        this->ui->carList->addItem(item);
    }
    int nrOfCars = cars.size(); // get the number of cars
    this->ui->nrCarsLine->setText(QString::number(nrOfCars)); // set the number of cars in the line edit
}

