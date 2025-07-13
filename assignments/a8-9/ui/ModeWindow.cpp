#include "ModeWindow.h"

ModeWindow::ModeWindow(QWidget *parent) : QWidget(parent) {
    auto *layout = new QVBoxLayout;

    this->modeCombo = new QComboBox;
    this->modeCombo->addItem("Administrator");
    this->modeCombo->addItem("User");

    this->okButton = new QPushButton("OK");

    layout->addWidget(this->modeCombo);
    layout->addWidget(this->okButton);

    setLayout(layout);
    setWindowTitle("Choose mode");
    resize(300, 100);

    connect(this->okButton, &QPushButton::clicked, this, &ModeWindow::onAccept);
}

void ModeWindow::onAccept() {
    emit modeChosen(this->modeCombo->currentText()); // emit the signal with the selected mode and close the window
    close();
}
