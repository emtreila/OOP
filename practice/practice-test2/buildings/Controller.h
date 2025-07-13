#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>

#include "Building.h"


class Controller {
private:
    std::vector<Building*> data;
public:
    Controller() = default;

    ~Controller();

    void addBuilding(Building *building);

    std::vector<Building *> getAllBuildings();

    std::vector<Building *> getAllBuildingsToBeRestored() const;

    std::vector<Building *> getAllBuildingsToBeDemolished() const;

    void writeToFile(const std::string &filename, std::vector<Building *> buildings) const;
};


#endif //CONTROLLER_H
