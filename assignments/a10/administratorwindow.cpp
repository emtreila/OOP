#include "administratorwindow.h"
#include "ui_AdministratorWindow.h"
#include <QMessageBox>
#include <QShortcut>

AdministratorWindow::AdministratorWindow(Service &service, QWidget *parent) : service(service), QWidget(parent),
                                                                              ui(new Ui::AdministratorWindow) {
    ui->setupUi(this);
    loadData();
    connect(ui->addButton, &QPushButton::clicked, this, &AdministratorWindow::addCoat);
    connect(ui->removeButton, &QPushButton::clicked, this, &AdministratorWindow::removeCoat);
    connect(ui->updateButton, &QPushButton::clicked, this, &AdministratorWindow::updateCoat);
    connect(ui->undoButton, &QPushButton::clicked, this, &AdministratorWindow::undoAction);
    connect(ui->redoButton, &QPushButton::clicked, this, &AdministratorWindow::redoAction);
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this, SLOT(undoAction()));
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this, SLOT(redoAction()));

}

AdministratorWindow::~AdministratorWindow() {
    delete ui;
}

void AdministratorWindow::loadData() {
    ui->coatTable->clear();

    const auto &coats = this->service.getAllService();

    for (auto coat: coats) {
        QListWidgetItem *item = new QListWidgetItem(coat.toString().c_str());
        ui->coatTable->addItem(item);
    }
}

void AdministratorWindow::addCoat() {
    try {
        this->service.addCoatService(
            ui->sizeEdit->text().toStdString(),
            ui->colourEdit->text().toStdString(),
            ui->priceEdit->text().toDouble(),
            ui->quantityEdit->text().toUInt(),
            ui->photoEdit->text().toStdString()
        );
        loadData();
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void AdministratorWindow::removeCoat() {
    try {
        this->service.removeCoatService(
            ui->sizeEdit->text().toStdString(),
            ui->colourEdit->text().toStdString()
        );
        loadData();
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void AdministratorWindow::updateCoat() {
    try {
        TrenchCoat coat(
            ui->sizeEdit->text().toStdString(),
            ui->colourEdit->text().toStdString(),
            ui->priceEdit->text().toDouble(),
            ui->quantityEdit->text().toUInt(),
            ui->photoEdit->text().toStdString()
        );
        this->service.updateCoatService(coat);
        loadData();
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void AdministratorWindow::undoAction() {
    service.undo();
    loadData();
}

void AdministratorWindow::redoAction() {
    service.redo();
    loadData();
}
