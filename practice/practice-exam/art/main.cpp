#include <QApplication>
#include <QPushButton>

#include "Service.h"
#include "userwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);

    auto users = service.getUsers();
    auto items = service.getItems();


    std::vector<userWindow *> windows;
    for (const auto &user: users) {
        auto *win = new userWindow(user, service);
        service.addObserver(*win);
        win->show();
        windows.push_back(win);
    }

    auto code = a.exec();
    return code;
}
