#include "repository/Repo.h"
#include "service/Service.h"
#include "ui/Ui.h"
#include "tests/Tests.h"

int main() {
    Repo repository;
    Service service(repository);
    Ui ui(service);

    service.addProteinService("Human", "Protein1", "AABBCC");
    service.addProteinService("Human", "Protein2", "AABBCC");
    service.addProteinService("Mouse", "Protein2", "AABBCC");
    service.addProteinService("Ecoli", "Protein4", "AABBCC");
    service.addProteinService("Ecoli", "Protein5", "AABBCC");

    Tests::runTests();
    //ui.run();
}