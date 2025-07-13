//
// Created by mela on 16.06.2025.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userWindow.h" resolved

#include "userwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include "ui_userWindow.h"


userWindow::userWindow(const User &user, Service &service, QWidget *parent) : QWidget(parent), ui(new Ui::userWindow),
                                                                              service(service) {
    ui->setupUi(this);
    this->user = user;
    this->setWindowTitle(QString::fromStdString(user.getName()));
    loadData();

    std::vector<std::string> categoryList = service.getCategory();
    for (const auto &cat: categoryList)
        ui->categoryComboBox->addItem(QString::fromStdString(cat));

    connect(ui->categoryComboBox, &QComboBox::currentTextChanged,
            this, &userWindow::filterByCategory);
    this->filterByCategory();
    if (user.getType() != "administrator") {
        ui->lineEditName->hide();
        ui->lineEditCategory->hide();
        ui->lineEditPrice->hide();
        ui->buttonAddItem->hide();
    }

    connect(ui->buttonAddItem, &QPushButton::clicked, this, &userWindow::handleAddItem);
    connect(ui->itemList, &QListWidget::itemSelectionChanged, this, &userWindow::showOffersForSelectedItem);
}

userWindow::~userWindow() {
    delete ui;
}

void userWindow::update() {
    loadData();
}

void userWindow::loadData() {
    ui->itemList->clear();
    auto items = this->service.getItems();

    for (const auto &i: items) {
        QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(i.toString()));

        ui->itemList->addItem(item);
    }
}

void userWindow::filterByCategory() {
    ui->itemList->clear();
    std::string selectedCategory = ui->categoryComboBox->currentText().toStdString();

    auto items = this->service.getItems();
    for (const auto &i: items) {
        if (i.getCategory() == selectedCategory) {
            QListWidgetItem *item = new QListWidgetItem(QString::fromStdString(i.toString()));
            ui->itemList->addItem(item);
        }
    }
}

void userWindow::handleAddItem() {
    if (user.getType() != "administrator") {
        QMessageBox::warning(this, "Access Denied", "Only administrators can add items.");
        return;
    }

    std::string name = ui->lineEditName->text().toStdString();
    std::string category = ui->lineEditCategory->text().toStdString();
    int price = ui->lineEditPrice->text().toInt();

    if (name.empty() || price <= 0) {
        QMessageBox::warning(this, "Input Error", "Name and category must not be empty.");
        return;
    }

    Item item(name, category, price);
    service.addItem(item);

}

void userWindow::showOffersForSelectedItem() {
    // Step 1: Clear the list that shows the offers
    ui->offerList->clear();

    // Step 2: Get the currently selected item in the itemList
    QList<QListWidgetItem *> selectedItems = ui->itemList->selectedItems();
    if (selectedItems.empty())
        return; // no item selected, nothing to show

    // Step 3: Extract the item name (assumed to be the first part of the text)
    QString selectedText = selectedItems[0]->text();
    QString namePart = selectedText.section('|', 0, 0).trimmed(); // e.g., "Phone"
    std::string selectedName = namePart.toStdString();

    // Step 4: Find the item in the list of all items
    std::vector<Item> allItems = service.getItems();
    for (const Item &item: allItems) {
        if (item.getName() == selectedName) {
            // Step 5: Get the list of offers
            std::vector<std::tuple<int, std::string, int> > offers = item.getOffers();

            // Step 6: Sort the offers descending by date (YYYY-MM-DD format)
            std::sort(offers.begin(), offers.end(),
                      [](const std::tuple<int, std::string, int> &a,
                         const std::tuple<int, std::string, int> &b) {
                          return std::get<1>(a) > std::get<1>(b); // later date first
                      });

            // Step 7: Show each offer in the offerList widget
            for (const auto &offer: offers) {
                int userId = std::get<0>(offer);
                std::string date = std::get<1>(offer);
                int sum = std::get<2>(offer);

                QString offerText = "User ID: " + QString::number(userId) +
                                    " | Date: " + QString::fromStdString(date) +
                                    " | Offered: " + QString::number(sum);

                ui->offerList->addItem(offerText);
            }

            break; // item found, no need to continue searching
        }
    }
}
