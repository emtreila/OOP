//
// Created by mela on 29.05.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_GUI.h" resolved

#include "gui.h"

#include "Service.h"
#include "ui_GUI.h"


GUI::GUI(QWidget *parent, Service &service) :
    QWidget(parent), ui(new Ui::GUI), service(service) {
    ui->setupUi(this);
    loadData();
    connect(ui->priorityButton, &QPushButton::clicked, this, &GUI::loadPriority);
}

GUI::~GUI() {
    delete ui;
}

void GUI::loadData() {
    ui->taskList->clear();
    std::vector<Task> tasks = this->service.getAllService();
    for (auto task: tasks) {
        QListWidgetItem *item = new QListWidgetItem(task.toString().c_str());
        ui->taskList->addItem(item);
    }
}

void GUI::loadPriority() {
    ui->taskList->clear();
    std::vector<Task> tasks = this->service.getFiltered();
    for (auto task: tasks) {
        QListWidgetItem *item = new QListWidgetItem(task.toString().c_str());
        ui->taskList->addItem(item);
    }
}

// void GUI::populate_by_priority() {
//     ui->priorityListWidget->clear();
//     int priority = std::stoi(ui->priorityLineEdit->text().toStdString());
//     int total = 0;
//     for (auto it : this->service.getAll()) {
//         if (it.getPriority() == priority) {
//             QString itemStr = QString::fromStdString(it.toString());
//             ui->priorityListWidget->addItem(itemStr);
//             total += it.getDuration();
//         }
//     }
//
//     ui->taskListWidget->clear();
//     for (auto it : this->service.getAll()) {
//         QString itemStr = QString::fromStdString(it.toString());
//         QListWidgetItem* item = new QListWidgetItem(itemStr);
//         if (it.getPriority() == priority) {
//             item->setBackground(Qt::blue);
//         }
//         ui->taskListWidget->addItem(item);
//     }
//     if (total == 0) {
//         QErrorMessage *err = new QErrorMessage();
//         err->showMessage("No tasks with this priority");
//     }
//     ui->totalLineEdit->setText(QString::fromStdString(std::to_string(total)));
// }