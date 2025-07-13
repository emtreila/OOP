#ifndef MODEWINDOW_H
#define MODEWINDOW_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class ModeWindow : public QWidget {
    Q_OBJECT

private:
    QComboBox *modeCombo;
    QPushButton *okButton;

public:
    explicit ModeWindow(QWidget *parent = nullptr);

signals:
    void modeChosen(const QString &mode);

private slots:
    void onAccept();
};

#endif // MODEWINDOW_H
