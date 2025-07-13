#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

#include "MedicalAnalysis.h"


class Person {
private:
    std::string name;
    std::vector<MedicalAnalysis *> data;

public:
    Person();

    explicit Person(const std::string &name);

    ~Person();

    void addAnalysis(MedicalAnalysis *a);

    std::vector<MedicalAnalysis *> getAllAnalyses();

    std::vector<MedicalAnalysis *> getAnalysisByMonth(int month);

    bool isIll(int month);

    std::vector<MedicalAnalysis *> getAnalysesBetweenDates(const std::string &date1, const std::string &date2);

    void writeToFile(const std::string &filename, const std::string &date1, const std::string &date2);
};


#endif //PERSON_H
