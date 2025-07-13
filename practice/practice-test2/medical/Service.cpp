#include "Service.h"

void Service::addAnalysisService(MedicalAnalysis *a) {
    this->person.addAnalysis(a);
}

std::vector<MedicalAnalysis *> Service::getAllAnalysesService() {
    return this->person.getAllAnalyses();
}

bool Service::isIllService(int month) {
    return this->person.isIll(month);
}

void Service::writeToFileService(const std::string &filename, const std::string &date1, const std::string &date2) {
    this->person.writeToFile(filename, date1, date2);
}