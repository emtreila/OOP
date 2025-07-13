#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QComboBox>

#include "../service/Service.h"
#include "../formatter/Formatter.h"

class UserWindow : public QWidget {
    Q_OBJECT

private:
    Service &service;
    Formatter *formatter = nullptr;
    std::vector<TrenchCoat> basket;
    int totalPrice = 0;

    QTableWidget *coatTable;
    QTableWidget *basketTable;
    QLineEdit *sizeEdit;
    QPushButton *filterButton;
    QPushButton *nextButton;
    QPushButton *addToBasketButton;
    QPushButton *saveButton;
    QLineEdit *filenameEdit;
    QPushButton *openFileButton;
    QPushButton *chartButton;


    int currentIndex = 0;
    std::vector<TrenchCoat> filtered;
    QString selectedFormat;

    void initUI();

    void loadFiltered();

    void showCurrentCoat();

    void updateBasket();

public:
    explicit UserWindow(Service &service, const QString &format, QWidget *parent = nullptr);

    ~UserWindow();

private slots:
    void onFilterClicked();

    void onNextClicked();

    void onAddClicked();

    void onSaveClicked();

    void onOpenFileClicked();
};

#endif // USERWINDOW_H
