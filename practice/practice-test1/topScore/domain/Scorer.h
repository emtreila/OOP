#ifndef SCORER_H
#define SCORER_H
#include <string>


class Scorer {
private:
    std::string name;
    std::string nationality;
    std::string team;
    int goals;

public:
    Scorer();

    Scorer(const std::string &name, const std::string &nationality, const std::string &team, int goals);

    ~Scorer();

    Scorer(const Scorer &scorer);

    const std::string &getName() const;

    const std::string &getNationality() const;

    const std::string &getTeam() const;

    int getGoals() const;

    void setName(const std::string newName);

    void setNationality(const std::string newNationality);

    void setTeam(const std::string newTeam);

    void setGoals(int newGoals);

    bool operator==(const Scorer &scorer) const;
};


#endif //SCORER_H
