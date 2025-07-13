//
// Created by mela on 24.05.2025.
//

#include "Service.h"

#include <cmath>

std::vector<Equation> Service::getAllService() {
    return this->repo.getAll();
}

bool Service::realSol(Equation &eq) {
    double delta = eq.getB() * eq.getB() - 4 * eq.getA() * eq.getC();
    return delta >= 0;
}

void Service::addEquation(const Equation &eq) {
    this->repo.add(eq);
}

std::string Service::solutions(Equation &eq) {
    double delta = eq.getB() * eq.getB() - 4 * eq.getA() * eq.getC();
    if (delta > 0) {
        return "x1= -" + std::to_string(-eq.getB()) + "+ rad(" + std::to_string(delta) + ") / (2 *" +
                           std::to_string(eq.getA()) + ")" + "  x2= -" + std::to_string(-eq.getB()) + "- rad(" +
                           std::to_string(delta) + ")" + "/ (2 *" + std::to_string(eq.getA()) + ")";
    } else if (delta == 0) {
        return "x1= -" + std::to_string(-eq.getB()) + "+ rad(" + std::to_string(delta) + ") / (2 *" +
                           std::to_string(eq.getA()) + ")";
    } else {
        return "x1= -" + std::to_string(-eq.getB()) + "+ i*rad(" + std::to_string(delta) + ") / (2 *" +
                          std::to_string(eq.getA()) + ")" + "  x2= -" + std::to_string(-eq.getB()) + "- i*rad(" +
                          std::to_string(delta) + ")" + "/ (2 *" + std::to_string(eq.getA()) + ")";
    }
}
