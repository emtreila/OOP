#ifndef SERVICE_H
#define SERVICE_H
#include "../repository/Repo.h"


class Service {
private:
    Repo &repo;

public:
    explicit  Service(Repo &repo): repo{repo} {
    }

    ~Service() = default;

    bool addSchoolService(const std::string &name, float address_long, float address_lat, int day, int month, int year, bool visited);

    bool removeSchoolService(const std::string &name, float address_long, float address_lat); // remove a school from the repository

    DynamicVector<School> getAllSchoolsName() const;

    School getSchoolService(int index);

    DynamicVector<School> getSchoolAfterDate(int day, int month, int year);

    DynamicVector<School> getVisitSchools(int day, int month, int year);
};


#endif //SERVICE_H
