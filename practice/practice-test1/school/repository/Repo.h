#ifndef REPO_H
#define REPO_H
#include "../DynamicVector.h"
#include "../domain/School.h"


class Repo {
private:
    DynamicVector<School> schools;

public:
    Repo();

    ~Repo();

    bool addSchool(const School &school);

    bool removeSchool(const std::string &name, float address_long, float address_lat); // remove a school

    bool updateSchool(const School &school);

    int sizeOfRepo();

    const DynamicVector<School> &getAll();

    School findSchool(const std::string &name, float address_long, float address_lat);

    School getSchool(int index);


};


#endif //REPO_H
