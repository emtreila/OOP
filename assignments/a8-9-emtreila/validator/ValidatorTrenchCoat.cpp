#include "ValidatorTrenchCoat.h"


void ValidatorTrenchCoat::validateTrenchCoat(const TrenchCoat &coat) {
    std::string errors;
    if (coat.getSize().empty()) {
        errors += "Size cannot be empty!\n";
    }
    if (coat.getColour().empty()) {
        errors += "Colour cannot be empty!\n";
    }
    if (coat.getPrice() <= 0) {
        errors += "Price must be positive!\n";
    }
    if (coat.getPrice() > 10000) {
        errors += "Price cannot be greater than 10000!\n";
    }
    if (coat.getQuantity() < 0) {
        errors += "Quantity cannot be negative!\n";
    }
    if (coat.getQuantity() > 1000) {
        errors += "Quantity cannot be greater than 1000!\n";
    }
    if (coat.getPhotograph().empty()) {
        errors += "Photograph cannot be empty!\n";
    }

    if (!errors.empty()) {
        throw ValidatorException(errors.c_str());
    }
}

void ValidatorTrenchCoat::validateSize(const std::string &size) {
    std::string errors;
    if (size.empty()) {
        errors += "Size cannot be empty!";
    }
    if (!errors.empty()) {
        throw ValidatorException(errors.c_str());
    }
}

void ValidatorTrenchCoat::validateColour(const std::string &colour) {
    std::string errors;
    if (colour.empty()) {
        errors += "Colour cannot be empty!";
    }
    if (!errors.empty()) {
        throw ValidatorException(errors.c_str());
    }
}
