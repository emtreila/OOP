#include "shoppingbasketwindow.h"

#include "shoppingbasketmodel.h"
#include "ui_ShoppingBasketWindow.h"


ShoppingBasketWindow::ShoppingBasketWindow(Service& service, QWidget *parent)
    : QWidget(parent), ui(new Ui::ShoppingBasketWindow), service(service) {
    ui->setupUi(this);

    auto *model = new ShoppingBasketModel(service, this);

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
}

ShoppingBasketWindow::~ShoppingBasketWindow() {
    delete ui;
}
