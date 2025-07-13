#include "TurboEngine.h"

TurboEngine::TurboEngine() {
    this->basePrice = 0;
}

TurboEngine::TurboEngine(double basePrice){
    this->basePrice = basePrice;
}

double TurboEngine::getPrice() {
    return this->basePrice + 100;
}

std::string TurboEngine::toString() {
    return "Turbo engine | Base price: " + std::to_string(this->basePrice);
}
