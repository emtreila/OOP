#include "CSVFormatter.h"

std::string CSVFormatter::format(const std::vector<TrenchCoat> &shoppingBag) {
    std::string formatted = "Size,Colour,Price,Quantity,Photograph\n";

    for (const auto &i: shoppingBag) {
        const auto &size = i.getSize();
        const auto &colour = i.getColour();
        auto price = std::to_string(i.getPrice());
        auto quantity = std::to_string(i.getQuantity());
        const auto &photo = i.getPhotograph();

        formatted.append(size);
        formatted.append(",");
        formatted.append(colour);
        formatted.append(",");
        formatted.append(price);
        formatted.append(",");
        formatted.append(quantity);
        formatted.append(",");
        formatted.append(photo);
        formatted.append("\n");
    }
    return formatted;
}
