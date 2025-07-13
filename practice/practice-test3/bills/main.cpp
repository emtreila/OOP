#include "GUI.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service{repo};
    GUI w(nullptr, service);
    w.show();

    return a.exec();
}
