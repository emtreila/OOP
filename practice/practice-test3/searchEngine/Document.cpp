#include "Document.h"

Document::Document() {
    this->name = "";
    this->keywords = "";
    this->content = "";
}

Document::Document(const std::string &name, const std::string &keywords, const std::string &content) {
    this->name = name;
    this->keywords = keywords;
    this->content = content;
}

std::string Document::getName() {
    return this->name;
}

std::string Document::getKeywords() {
    return this->keywords;
}


std::string Document::toString() {
    return this->name + " " + this->keywords;
}
