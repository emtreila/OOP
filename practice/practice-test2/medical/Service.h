#ifndef SERVICE_H
#define SERVICE_H
#include "Person.h"
#include "MedicalAnalysis.h"

class Service {
private:
    Person &person;

public:
    explicit Service(Person &person) : person(person) {
    };

    ~Service() = default;

    void addAnalysisService(MedicalAnalysis *a);

    std::vector<MedicalAnalysis *> getAllAnalysesService();

    bool isIllService(int month);

    void writeToFileService(const std::string &filename, const std::string &date1, const std::string &date2);
};


#endif //SERVICE_H
