#include <QMessageBox>

#include "repository/TextFileRepository.h"
#include "service/Service.h"
#include "ui/AdministratorWindow.h"
#include "ui/ModeWindow.h"
#include<QtWidgets/QApplication>

#include "ui/FormatDialog.h"
#include "ui/UserWindow.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    IRepository *repository = new TextFileRepository("D:/facultate/sem 2/OOP/a8-9-emtreila/coats_data.txt");
    Service service(repository);
    ModeWindow modeSelector;
    modeSelector.show();

    QObject::connect(&modeSelector, &ModeWindow::modeChosen, [&](const QString &mode) {
        if (mode == "Administrator") {
            auto *adminWindow = new AdministratorWindow(service);
            adminWindow->show();
        } else {
            FormatDialog formatDialog;
            formatDialog.exec();

            QString selectedFormat = formatDialog.getSelectedFormat();
            auto *w = new UserWindow(service, selectedFormat);
            w->show();
        }
    });

    return QApplication::exec();
}

// M,black,100,10,https://answear.ro/p/answear-lab-trenci-femei-culoarea-negru-de-tranzitie-cu-doua-randuri-de-nasturi-1359541
// L,blue,200,20,https://ro.factcool.com/product/2662299?gad_source=1
// S,red,300,30,https://www.trendyol.com/ro/passense/trenci-de-dama-cu-maneca-lunga-cu-rever-cu-nasturi-in-fata-cu-centura-in-talie-din-gabardina-p-886486311
// XL,green,400,40,https://gate.shop/ro/palton-624-0003-445
// XXL,yellow,500,50,https://answear.ro/p/answear-lab-palton-de-lana-femei-culoarea-galben-de-tranzitie-1479180
// XXS,orange,600,60,https://www.bonprix.ro/trenci-cu-parte-inferioara-i-maneci-detaabile/p-3409814619/903663/
// S,purple,700,70,https://answear.ro/p/medicine-palton-femei-culoarea-violet-de-tranzitie-cu-doua-randuri-de-nasturi-1336058
// M,pink,800,80,https://www.zalando.ro/lauren-ralph-lauren-double-breasted-cotton-blend-trench-coat-trenci-rose-mauve-l4221u0dv-j11.html
// XS,brown,900,90,https://www.zalando.ro/mango-trenci-kaki-m9121u1pv-n11.html
// L,white,1000,100,https://answear.ro/p/guess-trenci-femei-culoarea-bej-de-tranzitie-cu-doua-randuri-de-nasturi-w5rl15-wgym2-1478292
