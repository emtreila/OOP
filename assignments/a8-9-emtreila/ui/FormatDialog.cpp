#include "FormatDialog.h"

FormatDialog::FormatDialog(QWidget *parent): QDialog(parent) {
    setWindowTitle("Select File Format");
    this->formatCombo = new QComboBox;
    this->formatCombo->addItems({"CSV", "HTML"});

    auto *okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(this->formatCombo);
    layout->addWidget(okButton);
    setLayout(layout);

    resize(250, 100);
}

QString FormatDialog::getSelectedFormat() const {
    return this->formatCombo->currentText();
}
