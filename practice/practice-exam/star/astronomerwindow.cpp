#include "astronomerwindow.h"

#include "AstronomerTableModel.h"
#include "ui_astronomerWindow.h"
#include<QMessageBox>

astronomerWindow::astronomerWindow(const Astronomer &astronomer, Service &service, QWidget *parent) : QWidget(parent),
    ui(new Ui::astronomerWindow), service(service) {
    ui->setupUi(this);
    this->astronomer = astronomer;
    this->setWindowTitle(QString::fromStdString(this->astronomer.getName()));
    model = new AstronomerTableModel(service, this, 0, astronomer.getName());
    ui->tableView->setModel(model);
    loadData();
    ui->tableView->resizeColumnsToContents();

    connect(ui->constellationCheckBox, &QCheckBox::toggled, this, &astronomerWindow::loadData);
    connect(ui->addButton, &QPushButton::clicked, this, &astronomerWindow::addStar);
}

astronomerWindow::~astronomerWindow() {
    delete ui;
}

void astronomerWindow::loadData() {
    bool onlyStudied = ui->constellationCheckBox->isChecked();


    delete model;
    model = new AstronomerTableModel(
        service,
        this,
        onlyStudied ? 1 : 0, // 0 for all stars, 1 for only studied stars
        astronomer.getName(),
        astronomer.getConstelation()
    );
    ui->tableView->setModel(model);
    model->refresh();
    ui->tableView->resizeColumnsToContents();
}

void astronomerWindow::addStar() {
    if (ui->nameLine->text().isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please fill in all fields.");
        return;
    }
    for (const auto &star: this->service.getAllStars()) {
        if (star.getName() == ui->nameLine->text().toStdString()) {
            QMessageBox::warning(this, "Input Error", "Star with this name already exists.");
            return;
        }
    }
    Star newStar(
        ui->nameLine->text().toStdString(),
        this->astronomer.getConstelation(),
        ui->RALine->text().toInt(),
        ui->decLine->text().toInt(),
        ui->diameterLine->text().toInt()
    );
    this->service.addStar(newStar);
    emit starAdded();
}
