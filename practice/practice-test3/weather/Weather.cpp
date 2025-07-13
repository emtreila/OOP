//
// Created by mela on 29.05.2025.
//

#include "Weather.h"

Weather::Weather() {
    this->start = 0;
    this->end = 0;
    this->temperature = 0;
    this->precipitation = 0;
    this->description = "";
}

Weather::Weather(int start, int end, int temperature, int precipitation, std::string description) {
    this->start = start;
    this->end = end;
    this->temperature = temperature;
    this->precipitation = precipitation;
    this->description = description;
}

int Weather::getPrecipitation() {
    return this->precipitation;
}

std::string Weather::toString() {
    return std::to_string(this->start) + " - " + std::to_string(this->end) + " | " + std::to_string(this->temperature) +
           " | " + std::to_string(this->precipitation) + " | " + this->description;
}


int Weather::getStart() {
    return this->start;
}

int Weather::getEnd() {
    return this->end;
}

std::string Weather::getDescription() {
    return this->description;
}
