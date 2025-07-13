#ifndef RESEARCHERWINDOW_H
#define RESEARCHERWINDOW_H

#include <QWidget>
#include "IdeaTableModel.h"
#include "Service.h"
#include <fstream>
#include<QMessageBox>
#include "ui_researcherWindow.h"

QT_BEGIN_NAMESPACE

namespace Ui {
    class researcherWindow;
}

QT_END_NAMESPACE

class researcherWindow : public QWidget {
    Q_OBJECT

public:
    explicit researcherWindow(const Researcher &researcher, Service &service, QWidget *parent = nullptr);

    ~researcherWindow() override;

    void loadData();

private:
    Ui::researcherWindow *ui;
    Service &service;
    Researcher researcher;
    IdeaTableModel *model;

private slots:
    void addIdea();

    void approveIdea();

    void developIdea();

    void saveAcceptedIdeas();

    void saveEachIdea();

signals:
    void ideaAdded();
};


#endif //RESEARCHERWINDOW_H
