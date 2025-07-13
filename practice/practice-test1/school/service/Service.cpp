#include "Service.h"

bool Service::addSchoolService(const std::string &name, float address_long, float address_lat, int day, int month, int year, bool visited) {
    School newSchool = School(name, address_long, address_lat, day, month, year, visited);
    return this->repo.addSchool(newSchool);
}

bool Service::removeSchoolService(const std::string &name, float address_long, float address_lat) {
    /**
     * Remove a school from the repository
     * @param name: the name of the school
     * @param address_long: the longitude of the school
     * @param address_lat: the latitude of the school
     * @return: true if the school was removed, false otherwise
     */
    return this->repo.removeSchool(name, address_long, address_lat);
}

DynamicVector<School> Service::getAllSchoolsName() const{
    const DynamicVector<School> &schools = this->repo.getAll();
    DynamicVector<School> sorted = DynamicVector<School>(schools.sizeOfVector());

    for (int i = 0; i < schools.sizeOfVector(); i++) {
        sorted.add(schools.getElement(i));
    }

    for (int i = 0; i < sorted.sizeOfVector(); i++) {
        for (int j = i + 1; j < sorted.sizeOfVector(); j++) {
            if (sorted.getElement(i).getName() > sorted.getElement(j).getName()) {
                School aux = sorted.getElement(i);
                sorted.setElement(i, sorted.getElement(j));
                sorted.setElement(j, aux);
            }
        }
    }
    return sorted;


}

School Service::getSchoolService(int index) {
    return this->repo.getSchool(index);
}


DynamicVector<School> Service::getSchoolAfterDate(int day, int month, int year) {
    DynamicVector<School> afterDate = DynamicVector<School>();
    const DynamicVector<School> &schools = this->repo.getAll();

    for (int i = 0; i < schools.sizeOfVector(); i++) {
        if (schools.getElement(i).getYear() > year) {
            afterDate.add(schools.getElement(i));
        } else if (schools.getElement(i).getYear() == year) {
            if (schools.getElement(i).getMonth() > month) {
                afterDate.add(schools.getElement(i));
            } else if (schools.getElement(i).getMonth() == month) {
                if (schools.getElement(i).getDay() > day) {
                    afterDate.add(schools.getElement(i));
                }
            }
        }
    }

    return afterDate;
}

DynamicVector<School> Service::getVisitSchools(int day, int month, int year) {
    /**
     * Get all schools that have to be visited
     * @param day: the day
     * @param month: the month
     * @param year: the year
     * @return: a dynamic vector with all schools that have to be visited
     */

    DynamicVector<School> visit = DynamicVector<School>();

    int size = this->repo.sizeOfRepo();

    for (int i = 0; i < size; i++) {
        School school = this->repo.getSchool(i);
        if (school.getYear() < year) {
            school.setVisited(true);
            this->repo.updateSchool(school);
        }
        else if (school.getYear() == year) {
            if (school.getMonth() < month) {
                school.setVisited(true);
                this->repo.updateSchool(school);
            }
            else if (school.getMonth() == month) {
                if (school.getDay() < day) {
                    school.setVisited(true);
                    this->repo.updateSchool(school);
                }
            }
        }
    }
    DynamicVector<School> after = getSchoolAfterDate(day, month, year);
    for (int i = 0; i < after.sizeOfVector(); i++) {
        if (after.getElement(i).getVisited() == false) {
            visit.add(after.getElement(i));
        }
    }

    return visit;

}

