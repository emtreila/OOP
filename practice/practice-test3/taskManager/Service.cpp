//
// Created by mela on 29.05.2025.
//

#include "Service.h"

#include <algorithm>

std::vector<Task> Service::getAllService() {
    return this->repo.getAll();
}

std::vector<Task> Service::getFiltered() {
    auto data = this->repo.getAll();
    std::sort(data.begin(), data.end(),
              [](Task &a, Task &b) {
                  if (a.getPriority() == b.getPriority()) {
                      return a.getDuration() > b.getDuration();
                  }
                  return a.getPriority() > b.getPriority();
              });
    return data;
}



