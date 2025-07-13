#ifndef ASTRONOMERWINDOW_H
#define ASTRONOMERWINDOW_H

#include <QWidget>

#include "Astronomer.h"
#include "Service.h"
#include "AstronomerTableModel.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class astronomerWindow;
}

QT_END_NAMESPACE

class astronomerWindow : public QWidget {
    Q_OBJECT

public:
    explicit astronomerWindow(const Astronomer &astronomer, Service &service, QWidget *parent = nullptr);

    ~astronomerWindow() override;

    void loadData();

private:
    Ui::astronomerWindow *ui;
    Service &service;
    Astronomer astronomer;
    AstronomerTableModel *model;

private slots:
    void addStar();

signals:
    void starAdded();
};


#endif //ASTRONOMERWINDOW_H
