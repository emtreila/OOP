#ifndef VALIDATORTRENCHCOAT_H
#define VALIDATORTRENCHCOAT_H
#include "../domain/TrenchCoat.h"
#include "ValidatorException.h"


class ValidatorTrenchCoat {
public:
    static void validateTrenchCoat(const TrenchCoat &coat);

    static void validateSize(const std::string &size);

    static void validateColour(const std::string &colour);
};


#endif //VALIDATORTRENCHCOAT_H
