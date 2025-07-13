#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QWidget>
#include <QMap>
#include <QString>
#include "../service/Service.h"

class ChartWindow : public QWidget {
    Q_OBJECT

private:
    QMap<QString, int> sizeData;

public:
    explicit ChartWindow(Service& service, QWidget* parent = nullptr);
    void paintEvent(QPaintEvent* event) override;
};

#endif // CHARTWINDOW_H
