#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    int id;
    std::string name;
    std::string type; // "collector" or "administrator"

public:
    User();

    explicit User(const std::string &name, int id, const std::string &type);

    int getId() const;

    const std::string &getName() const;

    const std::string &getType() const;

    void setId(int id);

    void setName(const std::string &name);

    void setType(const std::string &type);
};

#endif // USER_H
