#ifndef SERVICE_H
#define SERVICE_H
#include "../repository/Repo.h"


class Service {
private:
    Repo &repo;

public:
    explicit Service(Repo &repo): repo{repo} {
    }

    ~Service() = default;

    // function to add a school
    bool addSchoolService(const std::string &name, float address_long, float address_lat, int day, int month, int year);

    DynamicVector<School> getAllSchoolsName() const;

    //School closestSchools(float address_long, float address_lat, School closest[3], const DynamicVector<School>& schools);

    School getSchoolService(int index);
};


#endif //SERVICE_H
