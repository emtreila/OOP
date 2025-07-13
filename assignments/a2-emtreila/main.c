#include "repository/Repo.h"
#include "service/Service.h"
#include "ui/Ui.h"
#include "tests/test_estate.h"
#include "tests/test_repo.h"
#include "tests/test_service.h"

int main() {
    runEstateTests();
    runRepoTests();
    runServiceTests();
    EstateRepo estate_repo = createRepository();
    EstateService estate_service = createService(estate_repo);
    EstateUi estate_ui = createUi(estate_service);

    run(&estate_ui);
    destroyService(&estate_service);
    return 0;
}
