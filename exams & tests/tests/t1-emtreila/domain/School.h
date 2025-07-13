#ifndef SCHOOL_H
#define SCHOOL_H
#include <string>

class School {
private:
    std::string name;
    float address_long;
    float address_lat;
    int day;
    int month;
    int year;

public:
    School();

    School(const std::string &name,
           float address_long,
           float address_lat,
           int day,
           int month,
           int year
    );

    ~School();

    School(const School &s);

    const std::string &getName();

    float getLong() const;

    float getAlt() const;

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setName(const std::string &newName);

    void setLong(float newLong);

    void setAlt(float newAlt);

    void setDay(int newDay);

    void setMonth(int newMonth);

    void setYear(int newYear);

    bool operator==(const School &school) const;
};


#endif //SCHOOL_H
