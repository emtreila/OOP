//
// Created by mela on 29.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"
#include "ui_GUI.h"


GUI::GUI(QWidget *parent, Service &service) :
    QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    loadAll();
    // connect(ui->lineEdit, &QLineEdit::textChanged, this, &GUI::search_bar);
    // connect(ui->itemsButton, &QPushButton::clicked, this, &GUI::filter);
}

GUI::~GUI() {
    delete ui;
}

void GUI::loadAll() {
    ui->itemsList->clear();
    auto data = this->service.getAllService();
    for (auto &item: data) {
        QListWidgetItem *listItem = new QListWidgetItem(QString::fromStdString(item.toString().c_str()));
        ui->itemsList->addItem(listItem);
    }
}

// void GUI::search_bar() {
//     ui->shoppingListWidget->clear();
//     std::string searchStr = this->ui->lineEdit->text().toStdString();
//     for (auto it: this->service.getAll()) {
//         if (it.getName().find(searchStr) != std::string::npos || it.getCategory().find(searchStr) != std::string::npos)
//             ui->shoppingListWidget->addItem(QString::fromStdString(it.toString()));
//     }
// }
//
// void GUI::filter() {
//     this->ui->categoryListWidget->clear();
//     std::string categ = this->ui->categoryLineEdit->text().toStdString();
//     std::vector<Item> list = this->service.getAll();
//     for (int i = 0 ; i < list.size(); i++)
//         for (int j = 0; j < list.size() - i - 1; j++) {
//             if (list[i].getQuantity() < list[j].getQuantity())
//                 std::swap(list[i], list[j]);
//         }
//     for (auto it: list) {
//         if (categ == it.getCategory())
//             ui->categoryListWidget->addItem(QString::fromStdString(it.toString()));
//     }
// }