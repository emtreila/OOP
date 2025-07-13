//
// Created by mela on 16.06.2025.
//

#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>

#include "Observer.h"
#include "Service.h"
#include "User.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class userWindow;
}

QT_END_NAMESPACE

class userWindow : public QWidget,
                   public Observer {
    Q_OBJECT

public:
    explicit userWindow(const User &user, Service &service, QWidget *parent = nullptr);

    ~userWindow() override;

    void update() override;

private:
    Ui::userWindow *ui;
    Service &service;
    User user;

private slots:
     void loadData();

    void filterByCategory();

    void handleAddItem();

    void showOffersForSelectedItem();

    //
    // void addItem();

};


#endif //USERWINDOW_H
