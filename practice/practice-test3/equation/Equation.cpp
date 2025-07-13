//
// Created by mela on 24.05.2025.
//

#include "Equation.h"

Equation::Equation() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
}

Equation::Equation(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

int Equation::getA() {
    return this->a;
}

int Equation::getB() {
    return this->b;
}

int Equation::getC() {
    return this->c;
}

std::string Equation::toString() {
    return std::to_string(a) + "*x^2 + " + std::to_string(b) + "*x + " + std::to_string(c);
}


