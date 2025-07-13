#include "formatdialog.h"
#include "ui_FormatDialog.h"


FormatDialog::FormatDialog(QWidget *parent) : QDialog(parent), ui(new Ui::FormatDialog) {
    ui->setupUi(this);
    connect(ui->okButton2, &QPushButton::clicked, this, &QDialog::accept);

}

FormatDialog::~FormatDialog() {
    delete ui;
}

QString FormatDialog::getSelectedFormat() const {
    return ui->formatCombo->currentText();
}
