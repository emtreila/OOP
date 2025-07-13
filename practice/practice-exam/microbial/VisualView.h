#ifndef VISUALVIEW_H
#define VISUALVIEW_H

#include <QWidget>
#include "Service.h"
#include "Biologist.h"

class VisualView : public QWidget {
    Q_OBJECT
    Service& service;
    Biologist biologist;

public:
    VisualView(const Biologist& bio, Service& srv, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
};

#endif // VISUALVIEW_H



