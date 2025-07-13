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

    bool addSchool(const School &school); // add school

    int sizeOfRepo();

    const DynamicVector<School> &getAll();

    School getSchool(int index);
};


#endif //REPO_H
