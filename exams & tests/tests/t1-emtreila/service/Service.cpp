#include "Service.h"

#include <cmath>

bool Service::addSchoolService(const std::string &name, float address_long, float address_lat, int day, int month,
                               int year) {
    /**
     * Adds a new school
     * @param name = the school name
     * @param address_long = the longitude of the address
     * @param address_lat = the altitude of the address
     * @param day = the day
     * @param month = the month
     * @param year = the year
     * return = True if the school was added successfully, False otherwise
     */
    School newSchool = School(name, address_long, address_lat, day, month, year);
    return this->repo.addSchool(newSchool);
}


DynamicVector<School> Service::getAllSchoolsName() const {
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

// School Service::closestSchools(float address_long, float address_lat, School closest[3], const DynamicVector<School>& schools) {
//     float dmin = 0, d;
//     for (int i =0; i<repo.sizeOfRepo(); i++) {
//         School schooli = repo.getSchool(i);
//         if (schooli.getName() != "/") {
//             for (int j = i+1; j<repo.sizeOfRepo();j++) {
//                 School schoolj = repo.getSchool(j);
//                 if (schoolj.getName() != "/") {
//                     d = std::sqrt((schooli.getAlt()+schoolj.getAlt())*(schooli.getAlt()+schoolj.getAlt()) + (schooli.getLong()+schoolj.getLong())*(schooli.getLong()+schoolj.getLong()));
//                     if (dmin > d) {
//                         dmin = d;
//                         closest[0] = schooli;
//                         closest[1] = schoolj;
//                     }
//                 }
//
//             }
//         }
//
//     }
//     return *closest;
// }
