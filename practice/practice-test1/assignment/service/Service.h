#ifndef SERVICE_H
#define SERVICE_H
#include "../repository/Repo.h"

class Service {
private:
    Repo &repo;
public:
    Service(Repo &repo): repo(repo) {
    }

    ~Service() = default;

    bool addAssignmentService(int id, std::string name, std::string solution);

    const DynamicVector<Assignment> &getAssignments() const;

};


#endif //SERVICE_H
