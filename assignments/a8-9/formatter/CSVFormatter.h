#ifndef CSVFORMATTER_H
#define CSVFORMATTER_H
#include "Formatter.h"


class CSVFormatter : public virtual Formatter {
public:
    std::string format(const std::vector<TrenchCoat> &shoppingBag) override;
};


#endif //CSVFORMATTER_H
