#ifndef APPLIANCE_H
#define APPLIANCE_H
#include <string>


class Appliance {
protected:
    std::string id;

public:
    Appliance();

    explicit Appliance(const std::string &id);

    virtual ~Appliance() = default;

    std::string getID() const;

    virtual double consumedElectricity() = 0;

    virtual std::string toString() = 0;
};


#endif //APPLIANCE_H
