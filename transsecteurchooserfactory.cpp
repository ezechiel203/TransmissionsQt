#include "transsecteurchooserfactory.h"
#include "ui_transsecteurchooserfactory.h"

TransSecteurChooserFactory::TransSecteurChooserFactory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransSecteurChooserFactory)
{
    parentWindow = static_cast<TransPrintPreview *>(parent);
    mainWindow = parentWindow->getTransmain();
    gestionnaire = mainWindow->getGestionnaire();
    ui->setupUi(this);
    setupComboBox();
    updateCombo();
    //connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), parentWindow, SLOT(updateSecteurs()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), parentWindow->preview, SLOT(updatePreview()));
}

TransSecteurChooserFactory::~TransSecteurChooserFactory()
{
    delete ui;
}

void TransSecteurChooserFactory::setupComboBox()
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

void TransSecteurChooserFactory::updateCombo()
{
    ui->comboBox->setCurrentIndex(ui->comboBox->findData(gestionnaire->getCote()->getNom()));
}

QList<Secteur *>* TransSecteurChooserFactory::getSecteursToPrint()
{
    return comboListe.at(ui->comboBox->currentIndex());
}
