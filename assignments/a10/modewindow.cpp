#include "modewindow.h"
#include "ui_ModeWindow.h"


ModeWindow::ModeWindow(QWidget *parent) : QWidget(parent), ui(new Ui::ModeWindow) {
    ui->setupUi(this);
    connect(ui->okButton, &QPushButton::clicked, this, &ModeWindow::onAccept);
}

ModeWindow::~ModeWindow() {
    delete ui;
}

void ModeWindow::onAccept() {
    emit modeChosen(ui->modeCombo->currentText());
    close();
}
