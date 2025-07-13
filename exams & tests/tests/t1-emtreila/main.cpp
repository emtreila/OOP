#include "repository/Repo.h"
#include "service/Service.h"
#include "ui/Ui.h"
#include "tests/Tests.h"

int main() {
    Repo repository;
    Service service(repository);
    Ui ui(service);

    service.addSchoolService("Avram_Iancu", 46.77, 23.60, 15, 04, 2022);
    service.addSchoolService("George_Cosbuc", 46.77, 23.58, 18, 04, 2022);
    service.addSchoolService("Alexandru_Vaida_Voievod", 46.77, 23.63, 23, 04, 2022);
    service.addSchoolService("Romulus_Guga", 46.53, 24.57, 04, 05, 2022);
    service.addSchoolService("Colegiul_Transilvania", 46.54, 24.57, 03, 05, 2022);

    Tests::runTests();
    ui.run();
}
