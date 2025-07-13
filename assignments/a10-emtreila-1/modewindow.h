#ifndef MODEWINDOW_H
#define MODEWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui {
    class ModeWindow;
}

QT_END_NAMESPACE

class ModeWindow : public QWidget {
    Q_OBJECT

public:
    explicit ModeWindow(QWidget *parent = nullptr);

    ~ModeWindow() override;

private:
    Ui::ModeWindow *ui;

private slots:
    void onAccept();

signals:
    void modeChosen(const QString &mode);
};


#endif //MODEWINDOW_H
