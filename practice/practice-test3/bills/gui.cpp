//
// Created by mela on 24.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include <QMessageBox>
#include "Bills.h"
#include "ui_GUI.h"


GUI::GUI(QWidget *parent, Service &service) :
    QWidget(parent),service{service}, ui(new Ui::GUI){
    ui->setupUi(this);
    loadData();
    connect(ui->allButton,&QPushButton::clicked,this,loadData);
    connect(ui->paidButton,&QPushButton::clicked,this,paidBills);
    connect(ui->unpaidButton,&QPushButton::clicked,this,unpaidBills);
    connect(ui->totalButton,QPushButton::clicked,this,totalByCompany);
}

GUI::~GUI() {
    delete ui;
}

void GUI::loadData() {
    ui->billsList->clear();
    std::vector<Bills> bills = this->service.getDataService();
    for (auto bill: bills) {
        QListWidgetItem *item = new QListWidgetItem(bill.toString().c_str());
        if (bill.getIsPaid() == false) {
            item->setBackground(QBrush(Qt::red));
        }
        ui->billsList->addItem(item);
    }
}

void GUI::paidBills() {
    ui->billsList->clear();
    std::vector<Bills> allBills = this->service.getDataService();

    for (auto bill: allBills) {
        if (bill.getIsPaid()) {
            QListWidgetItem *item = new QListWidgetItem(bill.toString().c_str());
            ui->billsList->addItem(item);
        }
    }
}

void GUI::unpaidBills() {
    ui->billsList->clear();
    std::vector<Bills> allBills = this->service.getDataService();

    for (auto bill: allBills) {
        if (!bill.getIsPaid()) {
            QListWidgetItem *item = new QListWidgetItem(bill.toString().c_str());
            item->setBackground(QBrush(Qt::red));
            ui->billsList->addItem(item);
        }
    }
}

void GUI::totalByCompany() {
    try {
        std::string companyName=ui->companyLine->text().toStdString();
        double total = this->service.totalByCompanyService(companyName);
        ui->totalLine->setText(std::to_string(total).c_str());
    }catch (std::invalid_argument& e) {
        QMessageBox mb;
        mb.setText(e.what());
        mb.exec();
    }
}


