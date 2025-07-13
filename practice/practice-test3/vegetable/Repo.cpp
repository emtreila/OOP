//
// Created by mela on 28.05.2025.
//

#include "Repo.h"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

Repo::Repo() {
    readFile();
}

void Repo::readFile() {
    /*
     * Reads data from a file named "data.txt" and populates the data vector with Vegetable objects.
     * Also sorts the vector based on the family of the vegetables.
     */
    std::ifstream file; // Open a file stream
    file.open("data.txt"); // Specify the file to open

    if (!file.is_open()) { // Check if the file was opened successfully
        throw std::runtime_error("Couldn't open file!");
    }
    this->data = std::vector<Vegetable>(); // Initialize the data vector to hold Vegetable objects
    std::string line;
    while (std::getline(file, line)) { // Read each line from the file
        std::stringstream ss(line);
        std::string f, n, p;

        // Split the line into family, name, and parts using ';' as a delimiter
        if (std::getline(ss, f, ';') &&
            std::getline(ss, n, ';') &&
            std::getline(ss, p, ';')) {
            std::string family = f;
            std::string name = n;
            std::string parts = p;


            Vegetable veggie(family, name, parts); // Create a Vegetable object with the parsed data
            this->data.push_back(veggie); // Add the Vegetable object to the data vector
            }
    }
    // Sort the data vector based on the family of the vegetables
    std::sort(data.begin(), data.end(),
              [](Vegetable &a, Vegetable &b) {
                  return a.getFamily() < b.getFamily(); // Compare the family names of the vegetables
              });
}

std::vector<Vegetable> Repo::getAll() {
    return this->data;
}
