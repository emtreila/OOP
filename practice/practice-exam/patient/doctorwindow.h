#ifndef DOCTORWINDOW_H
#define DOCTORWINDOW_H

#include <QWidget>

#include "Service.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class doctorWindow;
}

QT_END_NAMESPACE

class doctorWindow : public QWidget,
                     public Observer {
    Q_OBJECT

public:
    explicit doctorWindow(const Doctor &doctor, Service &service, QWidget *parent = nullptr);

    ~doctorWindow() override;

    void update() override;

private:
    Ui::doctorWindow *ui;
    Service &service;
    Doctor doctor;

private slots:
    void loadData();

    void addPatient();

    void openPatientView();
};


#endif //DOCTORWINDOW_H
