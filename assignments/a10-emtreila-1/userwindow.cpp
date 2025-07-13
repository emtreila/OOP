#include "userwindow.h"

#include <QMessageBox>

#include "shoppingbasketwindow.h"
#include "ui_UserWindow.h"
#include "formatter/CSVFormatter.h"
#include "formatter/HTMLFormatter.h"


UserWindow::UserWindow(Service &service, const QString &format, QWidget *parent)
    : QWidget(parent), ui(new Ui::UserWindow), service(service), selectedFormat(format) {
    ui->setupUi(this);

    connect(ui->filterButton, &QPushButton::clicked, this, &UserWindow::onFilterClicked);
    connect(ui->nextButton, &QPushButton::clicked, this, &UserWindow::onNextClicked);
    connect(ui->addToBasketButton, &QPushButton::clicked, this, &UserWindow::onAddClicked);
    connect(ui->saveButton, &QPushButton::clicked, this, &UserWindow::onSaveClicked);
    connect(ui->openFileButton, &QPushButton::clicked, this, &UserWindow::onOpenFileClicked);
    connect(ui->basketButton, &QPushButton::clicked, this, &UserWindow::onShowBasketClicked);
}

UserWindow::~UserWindow() {
    delete ui;
}

void UserWindow::loadFiltered() {
    this->filtered.clear();
    this->currentIndex = 0;

    std::string size = ui->sizeEdit->text().toStdString();
    for (const auto &coat: this->service.getAllService()) {
        if (size.empty() || coat.getSize() == size) {
            filtered.push_back(coat);
        }
    }

    if (this->filtered.empty()) {
        QMessageBox::information(this, "Info", "No trench coats found.");
        ui->coatTable->clearContents();
    } else {
        showCurrentCoat();
    }
}

void UserWindow::showCurrentCoat() {
    if (this->filtered.empty()) return;

    ui->coatTable->setRowCount(1);
    ui->coatTable->setColumnCount(5);
    QStringList headers = {"Size", "Colour", "Price", "Quantity", "Photo"};
    ui->coatTable->setHorizontalHeaderLabels(headers);
    ui->coatTable->horizontalHeader()->setStretchLastSection(true);


    ui->coatTable->clearContents();

    const auto &c = this->filtered[this->currentIndex];
    ui->coatTable->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(c.getSize())));
    ui->coatTable->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(c.getColour())));
    ui->coatTable->setItem(0, 2, new QTableWidgetItem(QString::number(c.getPrice())));
    ui->coatTable->setItem(0, 3, new QTableWidgetItem(QString::number(c.getQuantity())));
    ui->coatTable->setItem(0, 4, new QTableWidgetItem(QString::fromStdString(c.getPhotograph())));

    std::string command = "start " + c.getPhotograph();
    system(command.c_str());
}


void UserWindow::onFilterClicked() {
    loadFiltered();
}

void UserWindow::onNextClicked() {
    if (this->filtered.empty()) return;
    this->currentIndex = (this->currentIndex + 1) % this->filtered.size();
    showCurrentCoat();
}

void UserWindow::onAddClicked() {
    if (this->filtered.empty()) return;

    const auto &coat = this->filtered[this->currentIndex];
    try {
        this->service.removeCoatService(coat.getSize(), coat.getColour());
        this->basket.push_back(coat);
        this->totalPrice += coat.getPrice();
        loadFiltered();
        QMessageBox::information(this, "Info", "Coat added to basket. Total: " + QString::number(this->totalPrice));
    } catch (const std::exception &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void UserWindow::onSaveClicked() {
    delete this->formatter;
    if (this->selectedFormat == "CSV")
        this->formatter = new CSVFormatter();
    else
        this->formatter = new HTMLFormatter();

    std::string filename = ui->filenameEdit->text().toStdString();
    if (filename.empty()) {
        QMessageBox::warning(this, "Error", "Filename cannot be empty.");
        return;
    }

    auto content = this->formatter->format(this->basket);
    this->formatter->save(filename, content);
}

void UserWindow::onOpenFileClicked() {
    std::string command = "start " + ui->filenameEdit->text().toStdString();
    system(command.c_str());
}

void UserWindow::onShowBasketClicked() {
    auto *basketWindow = new ShoppingBasketWindow(this->service, nullptr);
    basketWindow->show();
}
