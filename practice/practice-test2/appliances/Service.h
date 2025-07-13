#ifndef SERVICE_H
#define SERVICE_H
#include <vector>

#include "Appliance.h"


class Service {
private:
    std::vector<Appliance*> data;
    std::vector<Appliance*> dataWithConsumedElectricityLessThan;
public:

    Service() = default;

    ~Service();

    void addAppliance(Appliance *a);

    std::vector<Appliance*> getAllAppliances() const;

    std::vector<Appliance*> getAllWithConsumedElectricityLessThan(double maxElectricity);

     void writeToFile(const std::string &filename) const;
};


#endif //SERVICE_H
