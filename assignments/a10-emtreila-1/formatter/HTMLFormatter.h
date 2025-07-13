#ifndef HTMLFORMATTER_H
#define HTMLFORMATTER_H
#include "Formatter.h"


class HTMLFormatter : public virtual Formatter{
public:
    std::string format(const std::vector<TrenchCoat> &shoppingBag) override;
};


#endif //HTMLFORMATTER_H
