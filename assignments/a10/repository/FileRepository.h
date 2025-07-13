#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H
#include "MemoryRepository.h"


class FileRepository : public MemoryRepository {
protected:
    std::string filename;

    virtual void readFromFile() = 0;

    virtual void writeToFile() = 0;

public:
    FileRepository(const std::string &filename);

    ~FileRepository() override = default;

    // adds a coat to the repository
    void addCoat(const TrenchCoat &coat) override;

    // removes a coat from the repository
    void removeCoat(const std::string &size, const std::string &colour) override;

    // updates a coat from the repository
    void updateCoat(const TrenchCoat &coat) override;
};


#endif //FILEREPOSITORY_H
