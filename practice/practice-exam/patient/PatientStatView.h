//
// Created by mela on 14.06.2025.
//

#ifndef PATIENTSTATVIEW_H
#define PATIENTSTATVIEW_H
#include <QWidget>
#include "Service.h"

class PatientStatView : public QWidget {
    Q_OBJECT
    Service &service;

public:
    explicit PatientStatView(Service &srv, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};


#endif //PATIENTSTATVIEW_H
