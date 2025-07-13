#ifndef IDEA_H
#define IDEA_H
#include <string>


class Idea {
private:
    std::string title;
    std::string description;
    std::string status;
    std::string creator;
    int duration;

public:
    Idea();

    explicit Idea(const std::string &title, const std::string &description, const std::string &status,
                  const std::string &creator, int duration);

    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getDescription() const;

    void setDescription(const std::string &description);

    const std::string &getStatus() const;

    void setStatus(const std::string &status);

    const std::string &getCreator() const;

    void setCreator(const std::string &creator);

    int getDuration() const;

    void setDuration(int duration);

    std::string toString() const;

    std::string toDevelopString() const;

    Idea &operator=(const Idea &other);
};


#endif //IDEA_H
