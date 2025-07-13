#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QMainWindow>
#include <QTableWidget> // -> for displaying the table with the coats
#include <QLineEdit> // -> for the input fields (size, colour, price, quantity, photo)
#include <QPushButton>
#include <QVBoxLayout> // -> for the main layout
#include <QWidget>

#include "../service/Service.h"

class AdministratorWindow : public QMainWindow {
    Q_OBJECT

private:
    Service &service;

    QTableWidget *coatTable;
    QLineEdit *sizeEdit;
    QLineEdit *colourEdit;
    QLineEdit *priceEdit;
    QLineEdit *quantityEdit;
    QLineEdit *photoEdit;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *updateButton;

    void initUI();

    void loadData();

public:
    explicit AdministratorWindow(Service &service, QWidget *parent = nullptr);

private slots: // -> event handlers
    void addCoat(); // = when we press the add button, the coat will be added to the table with the function addCoat()
    void removeCoat();

    void updateCoat();
};

#endif // ADMINISTRATORWINDOW_H
