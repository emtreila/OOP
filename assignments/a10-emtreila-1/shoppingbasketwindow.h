#ifndef SHOPPINGBASKETWINDOW_H
#define SHOPPINGBASKETWINDOW_H

#include <QWidget>

#include "domain/TrenchCoat.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class ShoppingBasketWindow;
}

QT_END_NAMESPACE

class ShoppingBasketWindow : public QWidget {
    Q_OBJECT

public:
    explicit ShoppingBasketWindow(Service& service, QWidget *parent = nullptr);
    ~ShoppingBasketWindow() override;

private:
    Ui::ShoppingBasketWindow *ui;
    Service& service;

};


#endif //SHOPPINGBASKETWINDOW_H
