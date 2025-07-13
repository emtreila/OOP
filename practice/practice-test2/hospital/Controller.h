#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>

#include "HospitalDepartment.h"


class Controller {
private:
    std::vector<HospitalDepartment*> data;
public:

    Controller() = default;

    ~Controller();

    void addDepartment(HospitalDepartment* department);

    std::vector<HospitalDepartment*> getAllDepartments();

    std::vector<HospitalDepartment*> getAllEfficientDepartments();

    void writeToFile(const std::string& filename);
};


#endif //CONTROLLER_H
