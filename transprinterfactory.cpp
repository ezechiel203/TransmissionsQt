#include "transprinterfactory.h"
#include "ui_transprinterfactory.h"
#include <QDebug>

TransPrinterFactory::TransPrinterFactory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransPrinterFactory)
{
    mainWindow = static_cast<Transmain *>(parent);
    gestionnaire = mainWindow->getGestionnaire();
    ui->setupUi(this);
    connect(ui->printFast, SIGNAL(clicked()), this, SLOT(printFast()));
    connect(ui->print, SIGNAL(clicked()), this, SLOT(printOpts()));
    setupComboBox();
    updateCombo();
}

TransPrinterFactory::~TransPrinterFactory()
{
    delete ui;
}

void TransPrinterFactory::setupComboBox()
{
    QList<Secteur *>* sects = gestionnaire->getSect();
    for(int i = 0 ; i< sects->count() ; i++)
    {
        QList<Secteur *>* temp = new QList<Secteur *>;
        temp->append(sects->at(i));
        comboListe.append(temp);
        ui->comboBox->addItem("Secteur "+sects->at(i)->getNom()+" (chambres "+sects->at(i)->getChambres().at(0)+" à "+sects->at(i)->getChambres().last()+" )", sects->at(i)->getNom());
    }
    ui->comboBox->addItem("Tous les secteurs");
    comboListe.append(sects);
}

void TransPrinterFactory::updateCombo()
{
    ui->comboBox->setCurrentIndex(ui->comboBox->findData(gestionnaire->getCote()->getNom()));
}

void TransPrinterFactory::printFast()
{
    mainWindow->printFast(comboListe.at(ui->comboBox->currentIndex()));
}

void TransPrinterFactory::printOpts()
{
    mainWindow->printOpts(comboListe.at(ui->comboBox->currentIndex()));
}
