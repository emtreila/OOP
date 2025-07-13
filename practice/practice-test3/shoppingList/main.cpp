#include "gui.h"
#include "Repo.h"
#include "Service.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);
    GUI gui(nullptr, service);
    gui.show();
    return a.exec();
}
