#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>


class Document {
private:
    std::string name;
    std::string keywords;
    std::string content;

public:
    Document();

    explicit Document(const std::string &name, const std::string &keywords, const std::string &content);

    ~Document() = default;

    std::string getName();

    std::string getKeywords();

    std::string toString();

    std::string toString3();
};


#endif //DOCUMENT_H
