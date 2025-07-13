#include "Formatter.h"

void Formatter::save(const std::string &filename, const std::string &s) {
    std::ofstream of(filename);
    if (!of.is_open()) {
        throw std::runtime_error("The file is not open!");
    }

    of << s;
    of.close();
}
