//
// Created by mela on 24.05.2025.
//

#ifndef EQUATION_H
#define EQUATION_H
#include <string>


class Equation {
private:
    int a;
    int b;
    int c;

public:
    Equation();

    explicit Equation(int a, int b, int c);

    ~Equation() = default;

    int getA();

    int getB();

    int getC();

    std::string toString();
};


#endif //EQUATION_H
