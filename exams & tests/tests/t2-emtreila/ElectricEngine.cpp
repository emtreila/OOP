#include "ElectricEngine.h"

ElectricEngine::ElectricEngine() {
    this->basePrice = 0;
    this->autonomy = 0;
}

ElectricEngine::ElectricEngine(double basePrice, int autonomy){
    this->basePrice = basePrice;
    this->autonomy = autonomy;
}

double ElectricEngine::getPrice() {
    return this->basePrice + autonomy*0.01;
}

std::string ElectricEngine::toString() {
    return "Electric engine | Base price: " + std::to_string(this->basePrice) +
           " | Autonomy: " + std::to_string(this->autonomy) + " km";

}
