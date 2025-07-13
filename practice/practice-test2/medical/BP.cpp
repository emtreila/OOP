#include "BP.h"

BP::BP() {
    this->date = "2025.01.01";
    this->systolicValue = 0;
    this->diastolicValue = 0;
}

BP::BP(const std::string &date, int systolicValue, int diastolicValue) {
    this->date = date;
    this->systolicValue = systolicValue;
    this->diastolicValue = diastolicValue;
}

bool BP::isResultOk() {
    if (this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue >= 60 && this->diastolicValue <=
        79) {
        return true;
    }
    return false;
}

std::string BP::toString() {
    return "BP || Date: " + this->date + " | Systolic Value: " + std::to_string(this->systolicValue) +
           " | Diastolic Value: " +
           std::to_string(this->diastolicValue);
}
