#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>

#include "Observer.h"
#include <algorithm>

class Observable {
private:
    std::vector<Observer *> observers;

public:
    virtual ~Observable() = default;

    void addObserver(Observer &obs);

    void removeObserver(Observer &obs);

    void notify();
};


#endif //OBSERVABLE_H
