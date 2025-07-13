#ifndef FORMATDIALOG_H
#define FORMATDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class FormatDialog : public QDialog {
    Q_OBJECT

private:
    QComboBox *formatCombo;

public:
    explicit FormatDialog(QWidget *parent = nullptr);

    QString getSelectedFormat() const;
};

#endif // FORMATDIALOG_H
