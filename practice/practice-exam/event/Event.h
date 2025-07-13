#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <vector>

#include "Person.h"


class Event {
private:
    std::string organizer;
    std::string name;
    std::string description;
    double longitude;
    double latitude;
    std::string date;
    std::vector<std::string> attendees;

public:
    Event();

    explicit Event(const std::string &organizer, const std::string &name, const std::string &description,
                   double longitude, double latitude, const std::string &date, std::vector<std::string> attendees);

    const std::string &getOrganizer() const;

    void setOrganizer(const std::string &organizer);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    double getLongitude() const;

    void setLongitude(double longitude);

    double getLatitude() const;

    void setLatitude(double latitude);

    const std::string &getDate() const;

    void setDate(const std::string &date);

    std::string toString() const;

    std::vector<std::string> getAttendees();

    void addAttendee(const std::string &personName);

    bool isAttending(const std::string &personName) const;
};


#endif //EVENT_H
