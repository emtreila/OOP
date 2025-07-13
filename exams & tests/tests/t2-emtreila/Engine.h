#ifndef ENGINE_H
#define ENGINE_H
#include <string>


class Engine {
protected:
    double basePrice;

public:
    Engine();

    Engine(double basePrice);

    virtual ~Engine() = default;

    double getPrice() const;

    virtual std::string toString() = 0;
};


#endif //ENGINE_H
