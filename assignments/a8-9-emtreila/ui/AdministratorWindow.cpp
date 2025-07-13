#include "AdministratorWindow.h"
#include <QHeaderView>
#include <QLabel>
#include <QMessageBox>

AdministratorWindow::AdministratorWindow(Service &service, QWidget *parent) : QMainWindow(parent), service(service) {
    initUI();
    loadData();
}

void AdministratorWindow::initUI() {
    QWidget *centralWidget = new QWidget(this); // central widget that will hold the content
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // 1) Creating the table
    this->coatTable = new QTableWidget;
    this->coatTable->setColumnCount(5);
    QStringList headers = {"SIZE", "COLOUR", "PRICE", "QUANTITY", "PHOTO"};
    this->coatTable->setHorizontalHeaderLabels(headers);
    this->coatTable->horizontalHeader()->setStretchLastSection(true);

    // 2) Creating the input fields
    QHBoxLayout *formLayout = new QHBoxLayout;
    // the input fields for size, colour, price, quantity and photo
    this->sizeEdit = new QLineEdit;
    this->colourEdit = new QLineEdit;
    this->priceEdit = new QLineEdit;
    this->quantityEdit = new QLineEdit;
    this->photoEdit = new QLineEdit;

    formLayout->addWidget(new QLabel("Size:"));
    formLayout->addWidget(this->sizeEdit);
    formLayout->addWidget(new QLabel("Colour:"));
    formLayout->addWidget(this->colourEdit);
    formLayout->addWidget(new QLabel("Price:"));
    formLayout->addWidget(this->priceEdit);
    formLayout->addWidget(new QLabel("Quantity:"));
    formLayout->addWidget(this->quantityEdit);
    formLayout->addWidget(new QLabel("Photo:"));
    formLayout->addWidget(this->photoEdit);

    // 3) Creating the buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    // buttons to add/remove/update a coat
    this->addButton = new QPushButton("Add");
    this->removeButton = new QPushButton("Remove");
    this->updateButton = new QPushButton("Update");
    // connect the buttons to the functions
    buttonLayout->addWidget(this->addButton);
    buttonLayout->addWidget(this->removeButton);
    buttonLayout->addWidget(this->updateButton);
    connect(this->addButton, &QPushButton::clicked, this, &AdministratorWindow::addCoat);
    connect(this->removeButton, &QPushButton::clicked, this, &AdministratorWindow::removeCoat);
    connect(this->updateButton, &QPushButton::clicked, this, &AdministratorWindow::updateCoat);

    // 4) Setting the styles
    this->sizeEdit->setStyleSheet("background-color: pink; color: black;");
    this->colourEdit->setStyleSheet("background-color: pink; color: black;");
    this->priceEdit->setStyleSheet("background-color: pink; color: black;");
    this->quantityEdit->setStyleSheet("background-color: pink; color: black;");
    this->photoEdit->setStyleSheet("background-color: pink; color: black;");

    // 5) Adding everything to the main layout
    mainLayout->addWidget(this->coatTable);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(formLayout);

    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);
    setWindowTitle("Administrator - Trench Coat Shop");
    resize(1000, 600);
}

void AdministratorWindow::loadData() {
    this->coatTable->setRowCount(0);
    const auto &coats = this->service.getAllService();

    for (const auto &coat: coats) {
        int row = this->coatTable->rowCount();
        this->coatTable->insertRow(row);

        this->coatTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(coat.getSize())));
        this->coatTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(coat.getColour())));
        this->coatTable->setItem(row, 2, new QTableWidgetItem(QString::number(coat.getPrice())));
        this->coatTable->setItem(row, 3, new QTableWidgetItem(QString::number(coat.getQuantity())));
        this->coatTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(coat.getPhotograph())));
    }
}

void AdministratorWindow::addCoat() {
    try {
        this->service.addCoatService(
            this->sizeEdit->text().toStdString(),
            this->colourEdit->text().toStdString(),
            this->priceEdit->text().toDouble(),
            this->quantityEdit->text().toUInt(),
            this->photoEdit->text().toStdString()
        );
        loadData();
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void AdministratorWindow::removeCoat() {
    try {
        this->service.removeCoatService(
            this->sizeEdit->text().toStdString(),
            this->colourEdit->text().toStdString()
        );
        loadData();
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void AdministratorWindow::updateCoat() {
    try {
        TrenchCoat coat(
            this->sizeEdit->text().toStdString(),
            this->colourEdit->text().toStdString(),
            this->priceEdit->text().toDouble(),
            this->quantityEdit->text().toUInt(),
            this->photoEdit->text().toStdString()
        );
        this->service.updateCoatService(coat);
        loadData();
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}
