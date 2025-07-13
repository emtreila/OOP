#include "MedicalAnalysis.h"

MedicalAnalysis::MedicalAnalysis() {
    this->date = "2025.01.01";
}

MedicalAnalysis::MedicalAnalysis(const std::string &date) {
    this->date = date;
}

std::string MedicalAnalysis::getDate() {
    return this->date;
}

