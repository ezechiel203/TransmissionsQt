#include "switchrooms.h"
#include "ui_switchrooms.h"

#include <QStringListModel>
#include <QMessageBox>
#include <qgroupboxstyleimage.h>
#include <QDialogButtonBox>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

SwitchRooms::SwitchRooms(GestionTabWidget* gest, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SwitchRooms)
{
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->parent = dynamic_cast<Transmain*>(parent);
    this->gestionnaire = gest;
    ui->setupUi(this);
    // ui->ChambrePrise->hide();

    //ui->groupBox->setStyle(new QGroupBoxStyleImage(ui->groupBox->style()));
    //ui->groupBox_2->setStyle(new QGroupBoxStyleImage(ui->groupBox_2->style()));

    connect(ui->comboSectDep, SIGNAL(currentIndexChanged(int)), this, SLOT(sectDepChanged(int)));
    connect(ui->comboSectArr, SIGNAL(currentIndexChanged(int)), this, SLOT(sectArrChanged(int)));
    connect(ui->comboChDep, SIGNAL(currentIndexChanged(int)), this, SLOT(chDepChanged(int)));
    connect(ui->comboChArr, SIGNAL(currentIndexChanged(int)), this, SLOT(chArrChanged(int)));
    connect(ui->comboChDep, SIGNAL(currentIndexChanged(int)), this, SLOT(propagerChangement()));
    connect(ui->comboChArr, SIGNAL(currentIndexChanged(int)), this, SLOT(propagerChangement()));
    connect(ui->options, SIGNAL(currentIndexChanged(int)), this, SLOT(propagerChangement()));
    connect(ui->boutonValid, SIGNAL(clicked()),this, SLOT(validClicked()));
    connect(ui->boutonAnul, SIGNAL(clicked()),this, SLOT(close()));
    QStringListModel* secteursModel = new QStringListModel;

    chambres = new QList<QStringList>;
    this->chambresSecteursList = gestionnaire->getPanels();
    secteurs = gestionnaire->getSect();
    initSecteurModel(secteursModel);

    ui->comboSectDep->setModel(secteursModel);
    ui->comboSectArr->setModel(secteursModel);

    QStringList comboOptionsList;
    comboOptionsList << "Action :" << "Intervertir" << "Remplacer";
    QStringListModel* comboOptionListModel = new QStringListModel;
    comboOptionListModel->setStringList(comboOptionsList);
    ui->options->setModel(comboOptionListModel);
    ui->groupBox->setStyle(new QGroupBoxStyleImage(ui->groupBox->style()));
    ui->groupBox_2->setStyle(new QGroupBoxStyleImage(ui->groupBox_2->style()));
    ui->ChambrePrise->hide();
}

SwitchRooms::~SwitchRooms()
{
    delete ui;
}


//Initialise le modèle contenant les secteurs ; initialise une liste de chambres pour chaque secteur
void SwitchRooms::initSecteurModel(QStringListModel* secteursModel)
{
    QListIterator<Secteur*> lit(*secteurs);
    QStringList listsect;

    while(lit.hasNext())
    {
        Secteur* sect = lit.next();
        listsect << sect->getNom();
        chambres->append(sect->getChambres());
        chambresListModel.append(new QStringListModel());
        chambresListModel.last()->setStringList(chambres->last());
    }

    secteursModel->setStringList(listsect);
}

//SLOTS GERANT L'INTERACTION AVEC LES COMBOBOX

void SwitchRooms::propagerChangement()
{
    if(ui->labelChArr->text() == "")
    {
        ui->boutonValid->setEnabled(true);
        cache();
    }
    else if(ui->comboChDep->currentText() != ui->comboChArr->currentText())
    {
        ui->boutonValid->setEnabled(true);
        affiche();
        if(ui->options->currentIndex() == 0)
            ui->boutonValid->setEnabled(false);
    }
    else
    {
        ui->boutonValid->setEnabled(false);
        cache();
    }
}

void SwitchRooms::sectDepChanged(int index)
{
    ui->comboChDep->setModel(chambresListModel.at(index));
}

void SwitchRooms::sectArrChanged(int index)
{
    ui->comboChArr->setModel(chambresListModel.at(index));
}

void SwitchRooms::chDepChanged(int index)
{
    ui->labelChDep->setText(chambresSecteursList->at(ui->comboSectDep->currentIndex())->at(index)->getNomText());
}

void SwitchRooms::chArrChanged(int index)
{
    ui->labelChArr->setText(chambresSecteursList->at(ui->comboSectArr->currentIndex())->at(index)->getNomText());
}

void SwitchRooms::validClicked()
{
    parent->toggleSaveTrue();
    ChambrePanel* crempla = gestionnaire->getPanels()->at(ui->comboSectDep->currentIndex())->at(ui->comboChDep->currentIndex());
    ChambrePanel* carempla = gestionnaire->getPanels()->at(ui->comboSectArr->currentIndex())->at(ui->comboChArr->currentIndex());

    if(ui->options->currentIndex() == 1)
    {
        //intervertir
        QMessageBox* box = new QMessageBox(QMessageBox::Warning,
                                       tr("Attention"),
                                       "<b>"+crempla->getNomText()+"</b> va être transféré <b>"+ carempla->getTitre()+"</b><br/><b>"+carempla->getNomText()+"</b> va être transféré <b>"+crempla->getTitre()+"</b><br/><br/>Continuer ?",
                                       QMessageBox::Yes| QMessageBox::Cancel,
                                       this);
                //new QMessageBox::warning(this, tr("Attention"),
                             //                         "<b>"+crempla->getNomText()+"</b> va être transféré <b>"+ carempla->getTitre()+"</b><br/><b>"+carempla->getNomText()+"</b> va être transféré <b>"+crempla->getTitre()+"</b>.<br/><br/>Continuer ?",
                               //                       QMessageBox::Yes | QMessageBox::Cancel,
                                 //                     QMessageBox::Cancel);
        box->button(QMessageBox::Yes)->setText("Oui");
        box->button(QMessageBox::Cancel)->setText("Annuler");
        if( box->exec() == QMessageBox::Yes )
        {
            QString titreDep = crempla->getTitre();
            QString objNameDep = crempla->objectName();

            QString titreArr = carempla->getTitre();
            QString objNameArr = carempla->objectName();

            gestionnaire->getPanels()->at(ui->comboSectArr->currentIndex())->replace(ui->comboChArr->currentIndex(), crempla);
            gestionnaire->getPanels()->at(ui->comboSectDep->currentIndex())->replace(ui->comboChDep->currentIndex(), carempla);
            gestionnaire->getPanels()->at(ui->comboSectArr->currentIndex())->at(ui->comboChArr->currentIndex())->setTitre(titreArr);
            gestionnaire->getPanels()->at(ui->comboSectArr->currentIndex())->at(ui->comboChArr->currentIndex())->setObjectName(objNameArr);
            gestionnaire->getPanels()->at(ui->comboSectDep->currentIndex())->at(ui->comboChDep->currentIndex())->setTitre(titreDep);
            gestionnaire->getPanels()->at(ui->comboSectDep->currentIndex())->at(ui->comboChDep->currentIndex())->setObjectName(objNameDep);
            gestionnaire->setSecteurTabs(gestionnaire->getSect()->at(ui->comboSectArr->currentIndex()));
            this->close();
        }
    }
    else
    {
        //Remplacer

        QMessageBox* box = new QMessageBox(QMessageBox::Warning,
                                       tr("Attention"),
                                       "<b>"+crempla->getNomText()+"</b> va être transféré <b>"+ carempla->getTitre()+"</b><br/><b>"+carempla->getNomText()+"</b> va sortir et son dossier ne pourra pas être récupéré.<br/><br/>Continuer ?",
                                       QMessageBox::Yes| QMessageBox::Cancel,
                                       this);

        box->button(QMessageBox::Yes)->setText("Oui");
        box->button(QMessageBox::Cancel)->setText("Annuler");
        if(box->exec() == QMessageBox::Yes )
        {
            QString titreDep = crempla->getTitre();
            QString objNameDep = crempla->objectName();

            QString titreArr = carempla->getTitre();
            QString objNameArr = carempla->objectName();

            gestionnaire->getPanels()->at(ui->comboSectArr->currentIndex())->replace(ui->comboChArr->currentIndex(), crempla);
            gestionnaire->getPanels()->at(ui->comboSectDep->currentIndex())->replace(ui->comboChDep->currentIndex(), new ChambrePanel(titreDep,gestionnaire, parent,0));
            gestionnaire->getPanels()->at(ui->comboSectArr->currentIndex())->at(ui->comboChArr->currentIndex())->setTitre(titreArr);
            gestionnaire->getPanels()->at(ui->comboSectArr->currentIndex())->at(ui->comboChArr->currentIndex())->setObjectName(objNameArr);
            gestionnaire->getPanels()->at(ui->comboSectDep->currentIndex())->at(ui->comboChDep->currentIndex())->setObjectName(objNameDep);
            delete carempla;
            gestionnaire->setSecteurTabs(gestionnaire->getSect()->at(ui->comboSectArr->currentIndex()));
            this->close();
        }
    }
}

void SwitchRooms::affiche()
{
    if(ui->ChambrePrise->isHidden())
    {
        ui->ChambrePrise->show();
        QGraphicsOpacityEffect* fade_effect = new QGraphicsOpacityEffect(ui->ChambrePrise);
        ui->ChambrePrise->setGraphicsEffect(fade_effect);
        QPropertyAnimation *animation = new QPropertyAnimation(fade_effect, "opacity");
        animation->setEasingCurve(QEasingCurve::OutCirc);
        animation->setDuration(500);
        animation->setStartValue(0.01);
        animation->setEndValue(1.0);
        animation->start();
    }
}

void SwitchRooms::cache()
{
    /*
        QGraphicsOpacityEffect* fade_effect = new QGraphicsOpacityEffect(ui->ChambrePrise);
        ui->ChambrePrise->setGraphicsEffect(fade_effect);
        QPropertyAnimation *animation = new QPropertyAnimation(fade_effect, "opacity");
        animation->setEasingCurve(QEasingCurve::OutCirc);
        animation->setDuration(375);
        animation->setStartValue(1);
        animation->setEndValue(0.01);
        animation->start();
        connect(animation, SIGNAL(finished()), ui->ChambrePrise, SLOT(hide()));
        */
    ui->ChambrePrise->hide();
}
