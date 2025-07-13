#ifndef TEXTFILEREPOSITORY_H
#define TEXTFILEREPOSITORY_H
#include "FileRepository.h"


class TextFileRepository : virtual public FileRepository {
public:
    TextFileRepository(const std::string &filename);

    ~TextFileRepository() override = default;

    void readFromFile() override;

    void writeToFile() override;
};


#endif //TEXTFILEREPOSITORY_H
