#ifndef PROTEIN_H
#define PROTEIN_H
#include <string>


class Protein {
private:
    std::string organism;
    std::string name;
    std::string sequence;

public:
    Protein();

    Protein(const std::string &organism,
            const std::string &name,
            const std::string &sequence);

    ~Protein();

    Protein(const Protein &protein);

    const std::string &getName() const;

    const std::string &getOrganism() const;

    const std::string &getSequence() const;

    void setName(const std::string &newName);

    void setOrganism(const std::string &newOrganism);

    void setSequence(const std::string &newSequence);

    bool operator==(const Protein &Protein) const;
};


#endif //PROTEIN_H
