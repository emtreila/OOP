#ifndef FORMATDIALOG_H
#define FORMATDIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE

namespace Ui {
    class FormatDialog;
}

QT_END_NAMESPACE

class FormatDialog : public QDialog {
    Q_OBJECT

public:
    explicit FormatDialog(QWidget *parent = nullptr);

    ~FormatDialog() override;

    QString getSelectedFormat() const;

private:
    Ui::FormatDialog *ui;
};


#endif //FORMATDIALOG_H
