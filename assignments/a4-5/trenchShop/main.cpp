#include <iostream>

#include "repository/Repo.h"
#include "service/Service.h"
#include "tests/Tests.h"
#include "ui/Ui.h"

void runApp() {
    Repo repository;
    Service service(repository);
    Ui ui(service);

    service.addCoatService("M", "black", 100, 10,
                           "https://answear.ro/p/answear-lab-trenci-femei-culoarea-negru-de-tranzitie-cu-doua-randuri-de-nasturi-1359541");
    service.addCoatService("L", "blue", 200, 20, "https://ro.factcool.com/product/2662299?gad_source=1");
    service.addCoatService("S", "red", 300, 30,
                           "https://www.trendyol.com/ro/passense/trenci-de-dama-cu-maneca-lunga-cu-rever-cu-nasturi-in-fata-cu-centura-in-talie-din-gabardina-p-886486311");
    service.addCoatService("XL", "green", 400, 40, "https://gate.shop/ro/palton-624-0003-445");
    service.addCoatService("XXL", "yellow", 500, 50,
                           "https://answear.ro/p/answear-lab-palton-de-lana-femei-culoarea-galben-de-tranzitie-1479180");
    service.addCoatService("XXS", "orange", 600, 60,
                           "https://www.bonprix.ro/trenci-cu-parte-inferioara-i-maneci-detaabile/p-3409814619/903663/");
    service.addCoatService("S", "purple", 700, 70,
                           "https://answear.ro/p/medicine-palton-femei-culoarea-violet-de-tranzitie-cu-doua-randuri-de-nasturi-1336058");
    service.addCoatService("M", "pink", 800, 80,
                           "https://www.zalando.ro/lauren-ralph-lauren-double-breasted-cotton-blend-trench-coat-trenci-rose-mauve-l4221u0dv-j11.html");
    service.addCoatService("XS", "brown", 900, 90, "https://www.zalando.ro/mango-trenci-kaki-m9121u1pv-n11.html");
    service.addCoatService("L", "white", 1000, 100,
                           "https://answear.ro/p/guess-trenci-femei-culoarea-bej-de-tranzitie-cu-doua-randuri-de-nasturi-w5rl15-wgym2-1478292");

    ui.run();
}

void runTests() {
    Tests::runTests();
}


int main() {
    runTests();
    //runApp();

    return 0;
}
