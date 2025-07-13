#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QWidget>

#include "service//Service.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class AdministratorWindow;
}

QT_END_NAMESPACE

class AdministratorWindow : public QWidget {
    Q_OBJECT

public:
    explicit AdministratorWindow(Service &service, QWidget *parent = nullptr);

    ~AdministratorWindow() override;

private:
    Ui::AdministratorWindow *ui;
    Service &service;

    void loadData();

private slots:
    void addCoat();

    void removeCoat();

    void updateCoat();

    void undoAction();

    void redoAction();
};


#endif //ADMINISTRATORWINDOW_H
