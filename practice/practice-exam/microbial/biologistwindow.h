#ifndef BIOLOGISTWINDOW_H
#define BIOLOGISTWINDOW_H

#include <QWidget>

#include "BacteriaTableModel.h"
#include "Service.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class biologistWindow;
}

QT_END_NAMESPACE

class biologistWindow : public QWidget {
    Q_OBJECT

public:
    explicit biologistWindow(const Biologist &biologist, Service &service, QWidget *parent = nullptr);

    ~biologistWindow() override;

    void loadData();

private:
    Ui::biologistWindow *ui;
    Service &service;
    Biologist biologist;
    BacteriaTableModel *model;
    BacteriaTableModel *filteredModel;

private slots:
    void addBacteria();

    void showDisease(const QModelIndex &index);

    void addDisease();

    void openVisualView();


    void filterBySpecies();

signals:
    void bacteriaAdded();
};


#endif //BIOLOGISTWINDOW_H
