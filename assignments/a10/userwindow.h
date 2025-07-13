#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>

#include "formatter/Formatter.h"
#include "service/Service.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class UserWindow;
}

QT_END_NAMESPACE

class UserWindow : public QWidget {
    Q_OBJECT

public:
    explicit UserWindow(Service &service, const QString &format, QWidget *parent = nullptr);

    ~UserWindow() override;

private:
    Ui::UserWindow *ui;
    Service &service;
    Formatter *formatter = nullptr;
    std::vector<TrenchCoat> basket;
    int totalPrice = 0;
    int currentIndex = 0;
    std::vector<TrenchCoat> filtered;
    QString selectedFormat;

private slots:
    void loadFiltered();

    void showCurrentCoat();

    void onFilterClicked();

    void onNextClicked();

    void onAddClicked();

    void onSaveClicked();

    void onOpenFileClicked();

    void onShowBasketClicked();
};


#endif //USERWINDOW_H
