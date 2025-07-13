#include "HTMLFormatter.h"

std::string HTMLFormatter::format(const std::vector<TrenchCoat> &shoppingBag) {
    std::string formatted;
    formatted.append("<!DOCTYPE html>\n");
    formatted.append("<html>\n");
    formatted.append("<head>\n");
    formatted.append("\t<title>Shopping bag</title>\n");
    formatted.append("</head>\n");
    formatted.append("<body>\n");
    formatted.append("<table border=\"1\">\n");
    formatted.append("\t<tr>\n");
    formatted.append("\t\t<td>Size</td>\n");
    formatted.append("\t\t<td>Colour</td>\n");
    formatted.append("\t\t<td>Price</td>\n");
    formatted.append("\t\t<td>Quantity</td>\n");
    formatted.append("\t\t<td>Photograph</td>\n");
    formatted.append("\t</tr>\n");

    for (const auto &i: shoppingBag) {
        const auto &size = i.getSize();
        const auto &colour = i.getColour();
        auto price = std::to_string(i.getPrice());
        auto quantity = std::to_string(i.getQuantity());
        const auto &photo = i.getPhotograph();

        formatted.append("\t<tr>\n");
        formatted.append("\t\t<td>" + size + "</td>\n");
        formatted.append("\t\t<td>" + colour + "</td>\n");
        formatted.append("\t\t<td>" + price + "</td>\n");
        formatted.append("\t\t<td>" + quantity + "</td>\n");
        formatted.append("\t\t<td>" + photo + "</td>\n");
        formatted.append("\t</tr>\n");
    }

    formatted.append("</table>\n");
    formatted.append("</body>\n");
    formatted.append("</html>");

    return formatted;
}
