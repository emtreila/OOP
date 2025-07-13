#include <ui_GUI.h>

#include "gui.h"
#include "Repo.h"
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);
    GUI w(nullptr, service);
    w.show();

    return a.exec();
}
