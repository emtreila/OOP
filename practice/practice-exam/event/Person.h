#ifndef PERSON_H
#define PERSON_H
#include <string>


class Person {
private:
    std::string name;
    double longitude;
    double latitude;
    bool status;

public:
    Person();

    explicit Person(const std::string &name, double longitude, double latitude, bool status);

    const std::string &getName() const;

    void setName(const std::string &name);

    double getLongitude() const;

    void setLongitude(double longitude);

    double getLatitude() const;

    void setLatitude(double latitude);

    bool getStatus() const;

    void setStatus(bool status);

    std::string getLocation(double lat, double lon) const;
};


#endif //PERSON_H
