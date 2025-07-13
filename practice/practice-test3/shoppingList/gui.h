//
// Created by mela on 29.05.2025.
//

#ifndef GUI_H
#define GUI_H

#include <QWidget>

#include "Service.h"


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget {
Q_OBJECT

public:
    explicit GUI(QWidget *parent, Service &service);
    ~GUI() override;

private:
    Ui::GUI *ui;
    Service &service;
private slots:
    void loadAll();
    // void search_bar();
    // void filter();
};


#endif //GUI_H
