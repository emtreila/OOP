#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QWidget>

#include "Service.h"


QT_BEGIN_NAMESPACE

namespace Ui {
    class personwindow;
}

QT_END_NAMESPACE

class personwindow : public QWidget, public Observer {
    Q_OBJECT

public:
    explicit personwindow(Service &service, const Person& person, const std::vector<Event>& events, QWidget* parent = nullptr);

    ~personwindow() override;

    void update();

private:
    Ui::personwindow *ui;
    Service &service;
    Person person;

private slots:
    void loadEventsData();
    void addEventGUI();
    void onEventSelected() const;
    void onGoingClicked() const;
};


#endif //PERSONWINDOW_H
