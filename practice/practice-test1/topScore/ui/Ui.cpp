#include "Ui.h"

void Ui::showMenu() {
    std::cout << "MENU\n";
    std::cout << "0. EXIT \n";
    std::cout << "1. Add a new scorer.\n";
    std::cout << "2. See all players.\n";
    std::cout << "3. See all players who play for a team.\n";
}

void Ui::addScorerUi(const std::string &name, const std::string &nationality, const std::string &team, int goals) {
    if (this->service.addScorerService(name, nationality, team, goals)) {
        std::cout << "Player added successfully!\n";
    } else {
        std::cout << "Player already exists!\n";
    }
}


void Ui::run() {
    int option;
    std::string name, nationality, team;
    int goals;

    while (true) {
        showMenu();
        std::cout << "Choose an option: ";
        std::cin >> option;


        if (option == 0) {
            std::cout << "Bye, bye!";
            return;
        } else if (option == 1) {
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << "Nationality: ";
            std::cin >> nationality;
            std::cout << "Team: ";
            std::cin >> team;
            std::cout << "Goals: ";
            std::cin >> goals;
            addScorerUi(name, nationality, team, goals);
        } else if (option == 2) {
            const DynamicVector<Scorer> &players = this->service.getAllService();

            for (int i = 0; i < players.sizeOfVector(); i++) {
                Scorer s = players.getElement(i);
                std::cout << "Name: " << s.getName() << ", Nationality: " << s.getNationality() << ", Team: " << s.
                        getTeam() << ", Goals: " << s.getGoals() <<
                        "\n";
            }
        } else if (option == 3) {
            std::cout << "Team: ";
            std::cin >> team;

            DynamicVector<Scorer> players = this->service.getPlayersByTeamService(team);
            for (int i = 0; i < players.sizeOfVector(); i++) {
                Scorer s = players.getElement(i);
                std::cout << "Name: " << s.getName() << ", Nationality: " << s.getNationality() << ", Team: " << s.
                        getTeam() << ", Goals: " << s.getGoals() <<
                        "\n";
            }
        } else {
            std::cout << "Invalid option!\n";
        }
    }
}
