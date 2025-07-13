#include "UserWindow.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>

#include "ChartWindow.h"
#include "../formatter/CSVFormatter.h"
#include "../formatter/HTMLFormatter.h"

UserWindow::UserWindow(Service &service, const QString &format, QWidget *parent)
    : QWidget(parent), service(service), selectedFormat(format) {
    initUI();
}

UserWindow::~UserWindow() {
    delete this->formatter;
}

void UserWindow::initUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // 1) Filter and Next buttons
    this->sizeEdit = new QLineEdit;
    this->filterButton = new QPushButton("Filter by Size");
    this->nextButton = new QPushButton("Next");
    this->addToBasketButton = new QPushButton("Add to Basket");

    // 2) Coat table
    this->coatTable = new QTableWidget(1, 5);
    QStringList headers = {"Size", "Colour", "Price", "Quantity", "Photo"};
    this->coatTable->setHorizontalHeaderLabels(headers);
    this->coatTable->horizontalHeader()->setStretchLastSection(true);

    QHBoxLayout *filterLayout = new QHBoxLayout;
    filterLayout->addWidget(new QLabel("Size:"));
    filterLayout->addWidget(this->sizeEdit);
    filterLayout->addWidget(this->filterButton);
    filterLayout->addWidget(this->nextButton);
    filterLayout->addWidget(this->addToBasketButton);

    // 3) Shopping basket table
    this->basketTable = new QTableWidget(0, 5);
    this->basketTable->setHorizontalHeaderLabels(headers);

    this->filenameEdit = new QLineEdit;
    this->saveButton = new QPushButton("Save Basket");
    this->openFileButton = new QPushButton("Open File");

    QHBoxLayout *saveLayout = new QHBoxLayout;
    saveLayout->addWidget(new QLabel("Filename:"));
    saveLayout->addWidget(this->filenameEdit);
    saveLayout->addWidget(this->saveButton);
    saveLayout->addWidget(this->openFileButton);

    mainLayout->addLayout(filterLayout);
    mainLayout->addWidget(this->coatTable);
    mainLayout->addWidget(new QLabel("Shopping Basket"));
    mainLayout->addWidget(this->basketTable);
    mainLayout->addLayout(saveLayout);

    setLayout(mainLayout);
    setWindowTitle("User - Trench Coat Shop");
    resize(1000, 700);

    connect(this->filterButton, &QPushButton::clicked, this, &UserWindow::onFilterClicked);
    connect(this->nextButton, &QPushButton::clicked, this, &UserWindow::onNextClicked);
    connect(this->addToBasketButton, &QPushButton::clicked, this, &UserWindow::onAddClicked);
    connect(this->saveButton, &QPushButton::clicked, this, &UserWindow::onSaveClicked);
    connect(this->openFileButton, &QPushButton::clicked, this, &UserWindow::onOpenFileClicked);

    chartButton = new QPushButton("Show Chart");
    mainLayout->addWidget(chartButton);

    connect(chartButton, &QPushButton::clicked, this, [this]() {
        auto *chart = new ChartWindow(service);
        chart->show();
    });
}

void UserWindow::loadFiltered() {
    this->filtered.clear();
    this->currentIndex = 0;

    std::string size = this->sizeEdit->text().toStdString();
    for (const auto &coat: this->service.getAllService()) {
        if (size.empty() || coat.getSize() == size) {
            filtered.push_back(coat);
        }
    }

    if (this->filtered.empty()) {
        QMessageBox::information(this, "Info", "No trench coats found.");
        this->coatTable->clearContents();
    } else {
        showCurrentCoat();
    }
}

void UserWindow::showCurrentCoat() {
    if (this->filtered.empty()) return;

    const auto &c = this->filtered[this->currentIndex];
    this->coatTable->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(c.getSize())));
    this->coatTable->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(c.getColour())));
    this->coatTable->setItem(0, 2, new QTableWidgetItem(QString::number(c.getPrice())));
    this->coatTable->setItem(0, 3, new QTableWidgetItem(QString::number(c.getQuantity())));
    this->coatTable->setItem(0, 4, new QTableWidgetItem(QString::fromStdString(c.getPhotograph())));

    std::string command = "start " + c.getPhotograph();
    system(command.c_str());
}

void UserWindow::updateBasket() {
    this->basketTable->setRowCount(0);
    for (const auto &c: basket) {
        int row = this->basketTable->rowCount();
        this->basketTable->insertRow(row);
        this->basketTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(c.getSize())));
        this->basketTable->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(c.getColour())));
        this->basketTable->setItem(row, 2, new QTableWidgetItem(QString::number(c.getPrice())));
        this->basketTable->setItem(row, 3, new QTableWidgetItem(QString::number(c.getQuantity())));
        this->basketTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(c.getPhotograph())));
    }
}

void UserWindow::onFilterClicked() {
    loadFiltered();
}

void UserWindow::onNextClicked() {
    if (this->filtered.empty()) return;
    this->currentIndex = (this->currentIndex + 1) % this->filtered.size(); // loop back to start
    showCurrentCoat();
}

void UserWindow::onAddClicked() {
    if (this->filtered.empty()) return;

    const auto &coat = this->filtered[this->currentIndex];
    try {
        this->service.removeCoatService(coat.getSize(), coat.getColour());
        this->basket.push_back(coat);
        this->totalPrice += coat.getPrice();
        updateBasket();
        loadFiltered(); // reload after removing
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

    std::string filename = this->filenameEdit->text().toStdString();
    if (filename.empty()) {
        QMessageBox::warning(this, "Error", "Filename cannot be empty.");
        return;
    }

    auto content = this->formatter->format(this->basket);
    this->formatter->save(filename, content);
}

void UserWindow::onOpenFileClicked() {
    std::string command = "start " + this->filenameEdit->text().toStdString();
    system(command.c_str());
}
