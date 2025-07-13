#include "Repo.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

Repo::Repo() {
    readItemsFromFile();
    readUsersFromFile();
}

void Repo::readUsersFromFile() {
    std::ifstream file("data_user.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open user file!");
    }
    this->data_users.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, idstr, type;
        if (std::getline(ss, idstr, ';') &&
            std::getline(ss, name, ';') &&
            std::getline(ss, type, ';')) {
            int id = std::stoi(idstr);
            User user(name, id, type);
            data_users.push_back(user);
        }
    }
}

void Repo::readItemsFromFile() {
    std::ifstream file("data_item.txt");
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open item file!");
    }
    this->data_items.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, category, priceStr, offersStr;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, category, ';') &&
            std::getline(ss, priceStr, ';')) {

            // Try to get offersStr — even if it's missing, that's OK
            std::getline(ss, offersStr); // safe even if it's empty

            int price = std::stoi(priceStr);
            std::vector<std::tuple<int, std::string, int>> offerList;

            std::stringstream offersStream(offersStr);
            std::string offer;
            while (std::getline(offersStream, offer, '|')) {
                std::stringstream offerStream(offer);
                std::string userIdStr, date, sumStr;
                if (std::getline(offerStream, userIdStr, ',') &&
                    std::getline(offerStream, date, ',') &&
                    std::getline(offerStream, sumStr, ',')) {

                    int userId = std::stoi(userIdStr);
                    int sum = std::stoi(sumStr);
                    offerList.emplace_back(userId, date, sum);
                    }
            }

            Item item(name, category, price);
            for (const auto& offer : offerList) {
                item.addOffer(std::get<0>(offer), std::get<1>(offer), std::get<2>(offer));
            }

            data_items.push_back(item);  // ✅ will now add even if no offers
            }

    }
}

const std::vector<Item> &Repo::getItems() const {
    return data_items;
}

const std::vector<User> &Repo::getUsers() const {
    return data_users;
}

void Repo::addItem(const Item &item) {
    data_items.push_back(item);
    std::ofstream file("data_item.txt", std::ios::app);
    if (!file.is_open()) {
        throw std::runtime_error("Couldn't open item file for writing!");
    }
    file << item.getName() << ";"
            << item.getCategory() << ";"
            << item.getCurrentPrice() << ";";
}
