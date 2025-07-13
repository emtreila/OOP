#include <fstream>
#include <QApplication>
#include "Service.h"
#include "personwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repo repo;
    Service service(repo);

    auto people = service.getAllPeopleService();
    auto events = service.getAllEventsService();

    std::vector<personwindow*> windows;
    for (const auto& person : people) {
        auto* win = new personwindow(service, person, events);
        win->show();
        windows.push_back(win);
    }
    auto code = a.exec();
    std::ofstream file("attendees.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open file!");
    }
    for (auto event : events) {
        for (const auto &attendee : event.getAttendees()) {
            file << event.getName() << ";" << attendee << "\n";
        }
    }

    file.close();
    return code;
}
