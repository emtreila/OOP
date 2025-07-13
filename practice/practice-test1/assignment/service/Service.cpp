#include "Service.h"

bool Service::addAssignmentService(int id, std::string name, std::string solution) {
    if (this->repo.addAssignment(id, name, solution)) {
        return true;
    }
    return false;
}

const DynamicVector<Assignment> &Service::getAssignments() const {
    return this->repo.getAll();
}

