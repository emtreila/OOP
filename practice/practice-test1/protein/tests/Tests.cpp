#include "Tests.h"

void Tests::testAddProtein() {
    Repo repo;

    assert(repo.addProtein(Protein("Enzyme", "Catalase", "Breaks down hydrogen peroxide")) == true);
    assert(repo.addProtein(Protein("Hormone", "Insulin", "Regulates blood sugar")) == true);
    assert(repo.addProtein(Protein("Structural", "Collagen", "Provides structural support")) == true);

    assert(repo.addProtein(Protein("Enzyme", "Catalase", "Breaks down hydrogen peroxide")) == false);
    assert(repo.addProtein(Protein("Hormone", "Insulin", "Regulates blood sugar")) == false);

    const auto &proteins = repo.getAll();
    assert(proteins.sizeOfVector() == 3);

    std::cout << "All addProtein tests passed!" << std::endl;
}

void Tests::testAddProteinService() {
    Repo repo;
    Service service(repo);

    assert(service.addProteinService("Human", "Hemoglobin", "MVHLTPEEKSAVTALWGKV") == true);
    assert(service.addProteinService("Bacteria", "Lactase", "MEKPLNYYPYY") == true);
    assert(service.addProteinService("Plant", "Rubisco", "MSPQTETKASVGFKAGV") == true);

    assert(service.addProteinService("Human", "Hemoglobin", "MVHLTPEEKSAVTALWGKV") == false);
    assert(service.addProteinService("Bacteria", "Lactase", "MEKPLNYYPYY") == false);

    const auto &proteins = repo.getAll();
    assert(proteins.sizeOfVector() == 3);

    std::cout << "All addProteinService tests passed!" << std::endl;
}


void Tests::testGetProteinsName() {
    Repo repo;
    Service service(repo);

    repo.addProtein(Protein("Human", "Hemoglobin", "MVHLTPEEKSAVTALWGKV"));
    repo.addProtein(Protein("Bacteria", "Hemoglobin", "MEKPLNYYPYY"));
    repo.addProtein(Protein("Plant", "Rubisco", "MSPQTETKASVGFKAGV"));
    repo.addProtein(Protein("Yeast", "Hemoglobin", "MKVIFLFFI"));
    repo.addProtein(Protein("Virus", "Capsid", "MNVLDNTRR"));

    auto result = service.getProteinsByName("Hemoglobin");
    assert(result.sizeOfVector() == 3);

    assert(result.getElement(0).getOrganism() == "Bacteria");
    assert(result.getElement(1).getOrganism() == "Human");
    assert(result.getElement(2).getOrganism() == "Yeast");


    assert(service.getProteinsByName("NonExistentProtein").sizeOfVector() == 0);

    std::cout << "All getProteinsByName tests passed!" << std::endl;
}

void Tests::runTests() {
    testAddProtein();
    testAddProteinService();
    testGetProteinsName();
}