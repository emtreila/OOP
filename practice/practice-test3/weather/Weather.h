//
// Created by mela on 29.05.2025.
//

#ifndef WEATHER_H
#define WEATHER_H
#include <string>


class Weather {
private:
    int start, end, temperature, precipitation;
    std::string description;

public:
    Weather();

    explicit Weather(int start, int end, int temperature, int precipitation, std::string description);

    int getPrecipitation();

    std::string toString();

    int getStart();

    int getEnd();

    std::string getDescription();

    ~Weather() = default;
};


#endif //WEATHER_H
