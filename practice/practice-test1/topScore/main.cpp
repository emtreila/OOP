#include "repository/Repo.h"
#include "service/Service.h"
#include "ui/Ui.h"
#include "tests/Tests.h"

int main() {
    Repo repository;
    Service service(repository);
    Ui ui(service);

    repository.addScorer(Scorer("Nora_Mork", "NOR", "Larvik", 83));
    repository.addScorer(Scorer("Isabelle_Gullden", "SWE", "CSM_Bucurest", 80));
    repository.addScorer(Scorer("Cristina_Neagu", "ROU", "Buducnost", 63));
    repository.addScorer(Scorer("Allison_Ekaterina", "RUS", "Rostov_Don", 80));
    repository.addScorer(Scorer("Amanda_Kurtovic", "NOR", "Larvik", 70));

    //ui.run();
    Tests::runTests();
}