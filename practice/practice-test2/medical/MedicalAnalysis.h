#ifndef MEDICALANALYSIS_H
#define MEDICALANALYSIS_H
#include <string>


class MedicalAnalysis {
protected:
    std::string date;

public:
    MedicalAnalysis();

    explicit MedicalAnalysis(const std::string &date);

    virtual ~MedicalAnalysis() = default;

    virtual bool isResultOk() = 0;

    virtual std::string toString() = 0;

    std::string getDate();
};


#endif //MEDICALANALYSIS_H
