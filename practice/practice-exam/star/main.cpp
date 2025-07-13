#include <iostream>
#include <QApplication>

#include "astronomerwindow.h"
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);

    auto astronomers = service.getAllAstronomers();
    auto stars = service.getAllStars();

    std::vector<astronomerWindow *> windows;
    for (const auto &astronomer: astronomers) {
        auto *win = new astronomerWindow(astronomer, service);
        win->show();
        windows.push_back(win);
    }

    for (astronomerWindow *sender: windows) {
        for (astronomerWindow *receiver: windows) {
            QObject::connect(sender, &astronomerWindow::starAdded, receiver, &astronomerWindow::loadData);
        }
    }


    auto code = a.exec();
    return code;
}