#include <QApplication>
#include <QPushButton>

#include "biologistwindow.h"
#include "Service.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);

    auto biologists = service.getAllBiologistsService();
    auto bacteriums = service.getAllBacteriaService();

    std::vector<biologistWindow *> windows;
    for (const auto &bio: biologists) {
        auto *win = new biologistWindow(bio, service);
        win->show();
        windows.push_back(win);
    }

    for (biologistWindow *sender: windows) {
        for (biologistWindow *receiver: windows) {
            QObject::connect(sender, &biologistWindow::bacteriaAdded, receiver, &biologistWindow::loadData);
        }
    }

    auto code = a.exec();
    return code;
}
