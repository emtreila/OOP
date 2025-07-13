
#include "Service.h"

#include <algorithm>

std::vector<Weather> Service::getAllService() {
    return this->repo.getAll();
}

std::vector<Weather> Service::getFilterd() {
    auto data = this->repo.getAll();
    std::sort(data.begin(), data.end(),
             [](Weather &a, Weather &b) {
                 if (a.getStart() == b.getStart()) {
                     return a.getEnd() < b.getEnd();
                 }
                 return a.getStart() < b.getStart();
             });
    return data;
}
