#include "BMI.h"

BMI::BMI() {
    this->date = "2025.01.01";
    this->value = 0;
}

BMI::BMI(const std::string &date, const double value) {
    this->date = date;
    this->value = value;
}

bool BMI::isResultOk() {
    if (value >= 18.5 && value <=25) {
        return true;
    }
    return false;
}

std::string BMI::toString() {
    return "BMI || Date: " + this->date + " | Value: " + std::to_string(value);
}
