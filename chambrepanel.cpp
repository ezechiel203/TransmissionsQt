#include "chambrepanel.h"
#include "ui_chambrepanel.h"
#include <iostream>
#include <QAbstractSpinBox>
#include <QDate>
#include <QRegExp>
#include <QCalendarWidget>
#include <QMenu>
#include <QWidgetAction>
#include <qgroupboxstyleimage.h>
#include <QToolTip>
#include <QStatusBar>
#include <QElapsedTimer>

ChambrePanel::ChambrePanel(QString titre, GestionTabWidget* gestionnaire, Transmain *parent, TransDocument *lengthChk):
    ui(new Ui::ChambrePanel)
{
    ui->setupUi(this);
    this->parent = parent;
    this->tabWidget = gestionnaire->getTabWidget();

    //On donne la référence de la chambre aux enfants
    ui->atcdText->setChambre(this);
    ui->nomText->setChambre(this);
    ui->allergiesText->setChambre(this);
    ui->examText->setChambre(this);
    ui->motifEntreeText->setChambre(this);
    ui->perosText->setChambre(this);
    ui->reaBigText->setChambre(this);
    ui->reaText->setChambre(this);
    ui->sortieMainText->setChambre(this);
    ui->sortieSubText->setChambre(this);
    ui->svMainText->setChambre(this);
    ui->svSubText->setChambre(this);
    ui->misc->setChambre(this);


    //On rajoute une petite flêche à droite des noms de groupbox via un appel à qgroupboxstyleimage
    ui->groupBoxNom->setStyle(new QGroupBoxStyleImage(ui->groupBoxNom->style()));
    ui->groupBox_2->setStyle(new QGroupBoxStyleImage(ui->groupBox_2->style()));
    ui->groupBox_3->setStyle(new QGroupBoxStyleImage(ui->groupBox_3->style()));
    ui->groupBox_4->setStyle(new QGroupBoxStyleImage(ui->groupBox_4->style()));
    ui->groupBox_5->setStyle(new QGroupBoxStyleImage(ui->groupBox_5->style()));
    ui->groupBox_6->setStyle(new QGroupBoxStyleImage(ui->groupBox_6->style()));
    ui->groupBox_7->setStyle(new QGroupBoxStyleImage(ui->groupBox_7->style()));
    ui->groupBox_8->setStyle(new QGroupBoxStyleImage(ui->groupBox_8->style()));
    ui->allergiesCheck->setStyle(new QGroupBoxStyleImage(ui->allergiesCheck->style()));


//Connexion du bouton reset à showClearFormDialog
    connect(ui->resetChambrePanel,SIGNAL(clicked()),this,SLOT(showClearFormDialog()));


//Mise en page d'oxydeb
    ui->oxyDeb->setRange(0,15);
    ui->oxyDeb->setDecimals(1);
    ui->oxyDeb->setSingleStep(.5);
    ui->oxyDeb->setWrapping(true);
    connect(ui->oxyDeb,SIGNAL(valueChanged(double)),this, SLOT(oxyDebUpdated()));

//Mise en forme des composants sondeves


//Mise en page du combobox allergies
    QStringList sondeVesOptsList;
    sondeVesOptsList << "motif :"<< "à demeure"<< "sur globe"<< "hématurie"<< "lavages"<< "cystocath"<< "arrêt le" << "CDD";
    ui->sondeVesCombo->addItems(sondeVesOptsList);

//date d'entrée
    //ui->dateEdit->setDate(QDate());

    this->setTitre(titre);

    this->connectToSaveButton();
    this->connectInterfaceParts();

//ui->chartoolbutton/*
    /*
    ui->charToolButton->setPopupMode(QToolButton::InstantPopup);
    QMenu* toolMenu2 = new QMenu(ui->charToolButton);
    QWidgetAction* toolAction2 = new QWidgetAction(toolMenu2);
    CaractSpeciauxWidget *charWid = new CaractSpeciauxWidget(toolMenu2);
    //cal->setGridVisible(true);
    toolAction2->setDefaultWidget(charWid);
    toolMenu2->addAction(toolAction2);
    ui->charToolButton->setMenu(toolMenu2);
*/

//Mise à 0 de la date
    ui->boutonCalendrier->setPopupMode(QToolButton::InstantPopup);
    QMenu* toolMenu = new QMenu(ui->boutonCalendrier);
    QWidgetAction* toolAction = new QWidgetAction(toolMenu);
    QCalendarWidget* cal = new QCalendarWidget(toolMenu);
    //cal->setGridVisible(true);
    cal->setStyleSheet("/* navigation bar */"
                       "QCalendarWidget QWidget#qt_calendar_navigationbar { background-color: #FDFDFD; }"
                       "QCalendarWidget QToolButton {"
                       "color: black;"
                       "background-color: #FDFDFD;"
                       "min-width : 10px;"
           "            }"

                       "QCalendarWidget QToolButton#qt_calendar_monthbutton {"
                       "color: #606060;"
                       "background-color: #FDFDFD;"
                       "padding-left : 30px;"
                       "min-width : 80px;"
           "            }"
                       "QCalendarWidget QToolButton#qt_calendar_yearbutton {"
                       "color: #606060;"
                       "background-color: #FDFDFD;"
                       "padding-right : 30px;"
                       "min-width : 60px;"
           "            }"
                      " QCalendarWidget QComboBox {"
                    "   color: black;"
                       "width:200px;"
                       "background-color: #FDFDFD;}"
                       "QCalendarWidget QSpinBox { "
                       "color: black; "
                       "background-color: #FDFDFD; "
                       "selection-background-color: #B5E3FC;"
                       "selection-color: rgb(60,60,60);}"
                       "QCalendarWidget QWidget { alternate-background-color: #FDFDFD; "
                       "selection-background-color: #B5E3FC;"
                       "selection-color: rgb(60,60,60);}");
    toolAction->setDefaultWidget(cal);
    toolMenu->addAction(toolAction);
    ui->boutonCalendrier->setMenu(toolMenu);
    dureeSejourUpdate();


    cal->setDateRange(QDate::currentDate().addDays(-92), QDate::currentDate());
    connect(cal,SIGNAL(clicked(QDate)),toolMenu,SLOT(hide()));
    connect(cal,SIGNAL(clicked(QDate)),ui->dateEntree,SLOT(setDate(QDate)));


    connect(ui->dateEntree, SIGNAL(dateChanged()), this, SLOT(dureeSejourUpdate()));
    connect(ui->boutonToday, SIGNAL(clicked()), this, SLOT(setDateToday()));
    connect(this, SIGNAL(dateUpdate(QDate)), ui->dateEntree, SLOT(setDate(QDate)));


    connect(ui->nomText, SIGNAL(editingFinished()), this, SLOT(dateEditReminder()));
    connect(ui->dateEntree, SIGNAL(dateChanged()), this, SLOT(dateEditReminder()));

    connect(ui->razDate, SIGNAL(clicked()), this, SLOT(eraseDate()));
    connect(ui->dateEntree, SIGNAL(dateChanged()), this, SLOT(razDateToggle()));

    connect(ui->allergiesCheck, SIGNAL(pressed()), ui->atcdText,SLOT(repaint()));
    connect(ui->allergiesText, SIGNAL(cursorPositionChanged()), ui->atcdText, SLOT(repaint()));

    //Gestion de la longueur des textes
    if(lengthChk == 0)
        lengthChecker = new TransDocument(gestionnaire, this);
    else
        lengthChecker = lengthChk;

    //misc
    ui->misc->setLengthChecker(lengthChecker);
    ui->misc->setSize(TransDocument::MISC);

    //motifentree
    ui->motifEntreeText->setLengthChecker(lengthChecker);

    //Antécédents
    ui->atcdText->setPartner(ui->allergiesText);
    ui->atcdText->setAllergiesCheck(ui->allergiesCheck);
    ui->atcdText->setLengthChecker(lengthChecker);


    //Reasub
    ui->reaBigText->setLengthChecker(lengthChecker);

    //exams/soins
    ui->examText->setLengthChecker(lengthChecker);

    //Per os
    ui->perosText->setLengthChecker(lengthChecker);


    //SV sub
    ui->svSubText->setLengthChecker(lengthChecker);

    //sortie sub
    ui->sortieSubText->setLengthChecker(lengthChecker);

    //allergies
    ui->allergiesText->setPartner(ui->atcdText);
    ui->allergiesText->setAllergiesCheck(ui->allergiesCheck);
    ui->allergiesText->setLengthChecker(lengthChecker);

    //reatext
    ui->reaText->setLengthChecker(lengthChecker);
    ui->reaText->setSize(TransDocument::REASMALL);

    //sortiemain
    ui->sortieMainText->setLengthChecker(lengthChecker);
    ui->sortieMainText->setSize(TransDocument::SMALL);

    //svmain
    ui->svMainText->setLengthChecker(lengthChecker);
    ui->svMainText->setSize(TransDocument::SMALL);

    dlg=0;

}

ChambrePanel::~ChambrePanel()
{
    delete ui;
}

Transmain *ChambrePanel::getTransmain()
{
    return parent;
}

//SLOT POUR LA RECUPERATION DU CLIC SUR CLEARFORMBUTTON
void ChambrePanel::showClearFormDialog()
{
    //si l'objet n'a pas été créé, on le crée et on connecte son retour à clearFormDialogReturn
    if(dlg == 0)
    {
        this->dlg = new ClearFormDialog(parent);
        dlg->setStyleSheet("QPushButton {height:25px; width : 80 px;}");
        connect(dlg,SIGNAL(accepted(bool)),this,SLOT(clearFormDialogReturn(bool)));
    }
    if(parent->getClearFormShow())
        dlg->exec();
    else
    {
        this->ClearForm();
    }
}

void ChambrePanel::clearFormDialogReturn(bool chk)
{
    this->ClearForm();
    parent->setClearFormShow(!chk);
}

//SLOT pour la gestion de l'activation des checkboxes
void ChambrePanel::sondeVesChecked()
{
    ui->sondeVesCombo->setEnabled(ui->sondeVesCheck->isChecked());
    if(!ui->sondeVesCombo->isEnabled())
        ui->sondeVesCombo->setCurrentIndex(0);
    miseEnPage();
}

void ChambrePanel::oxyChecked()
{
    ui->oxyDeb->setEnabled(ui->OxyCheck->isChecked());
    if(!ui->oxyDeb->isEnabled())
        ui->oxyDeb->setValue(0.);
    miseEnPage();
}

void ChambrePanel::aerosolChecked()
{
    miseEnPage();
}

void ChambrePanel::pansementsChecked()
{
    miseEnPage();
}

void ChambrePanel::reaChecked()
{
    ui->reaText->setEnabled(ui->reaCheck->isChecked());
    if(! ui->reaText->isEnabled())
        ui->reaText->setText("");
    miseEnPage();
}

void ChambrePanel::allergiesChecked()
{
    ui->allergiesText->setEnabled(ui->allergiesCheck->isChecked());
    if(ui->allergiesCheck->isChecked()){
        connect(ui->allergiesCheck, SIGNAL(pressed()),ui->allergiesText,SLOT(repaint()));
        connect(ui->atcdText, SIGNAL(cursorPositionChanged()), ui->allergiesText, SLOT(repaint()));
    }
    else{
        disconnect(ui->allergiesCheck, SIGNAL(pressed()),ui->allergiesText,SLOT(repaint()));
        disconnect(ui->atcdText, SIGNAL(cursorPositionChanged()), ui->allergiesText, SLOT(repaint()));
    }
    if(! ui->allergiesText->isEnabled())
        ui->allergiesText->setText("");
    miseEnPage();
    ui->allergiesText->repaint();
    ui->atcdText->check_uncheck();
    ui->atcdText->repaint();
}

void ChambrePanel::switchActiveInterfaceParts()
{
    sondeVesChecked();
    oxyChecked();
    allergiesChecked();
    aerosolChecked();
    reaChecked();
}

//MISE EN PAGE DES CHAMPS

void ChambrePanel::miseEnPage()
{
    //Fonctionnement premier --> Renvoi des entrées manuelles de SVMain vers SVSub si case cochée. Maintenant on préfèrera conserver cela en fin de ligne
/*
    if(!ui->svMainText->toPlainText().isEmpty())
        if(!(ui->svMainText->toPlainText().startsWith("SV") || ui->svMainText->toPlainText().startsWith("O2") || ui->svMainText->toPlainText().startsWith("Aérosols")))
            if(!ui->svSubText->toPlainText().contains(ui->svMainText->toPlainText()))
                ui->svSubText->setText(ui->svMainText->toPlainText()+" "+ui->svSubText->toPlainText());
    */

    QRegExp patternSV("^.*\\b(SV|à.demeure|sur.globe|hématurie|lavages|cystocath|arrêt le|CDD|O2|[0-9]*.+[0-9]+L|Aérosols)\\s*");
    patternSV.setCaseSensitivity(Qt::CaseInsensitive);
    QString Clean = ui->svMainText->toPlainText().remove(patternSV);

    QString SV2 = "";
    if (ui->sondeVesCheck->isChecked() && !ui->svMainText->toPlainText().contains(ui->sondeVesCombo->currentText())) {
        if (ui->sondeVesCombo->currentIndex() != 0) {
            ui->svMainText->setText("SV "+ui->sondeVesCombo->currentText()+" "+Clean);
        } else {
            ui->svMainText->setText("SV "+Clean);
        }
    }

    //gestion oxygene et aérosols
    if (ui->OxyCheck->isChecked()) {
        if (ui->oxyDeb->value() == 0.) {
            SV2 = "O2 ";
        } else {
            SV2 = "O2 " + QString::number(ui->oxyDeb->value()) + "L ";
        }
    }
    if (ui->AerosolsCheck->isChecked()) {
        SV2 += "Aérosols ";
    }

    QString clean2 = ui->svSubText->toPlainText().remove(patternSV);
    if (ui->sondeVesCheck->isChecked()) {
        ui->svSubText->setText(SV2 + clean2);
    } else {
        ui->svMainText->setText(SV2+Clean);
        ui->svSubText->setText(clean2);
    }

    //Gestion Pansements

    if (ui->pansementsCheck->isChecked())
    {
        QString Psmt = "";
        if(!this->getExamText().contains("Psmt")){
            Psmt = "<b>Psmt</b> "+this->getExamText();
            this->setExamText(Psmt);
        }
        else{
            this->setExamText(this->getExamText().replace(QRegularExpression("^(p|Psmt)( .*$)"),"<b>\\1</b> \\2"));
        }

    }

    else{
        QRegExp pattern("^.*\\b(Psmt)\\s*");
        pattern.setCaseSensitivity(Qt::CaseInsensitive);
        QString clean = this->getExamText().remove(pattern);
        this->setExamText(clean);
    }
}

void ChambrePanel::dureeSejourUpdate()
{
    if(ui->dateEntree->text() == "")
        ui->dureeSejour->setText("...");
    else{
        ui->dureeSejour->setText("J"+QString::number(ui->dateEntree->getnumDate().daysTo(QDate::currentDate())+1));
    }

}

void ChambrePanel::toCaps()
{
    QLineEdit* le;
    le = qobject_cast<QLineEdit*>(QObject::sender());
    le->setText(le->text().toUpper());

}

void ChambrePanel::dateEditReminder()
{
    if(ui->nomText->text() != "" && ui->dateEntree->text() == "")
    {
       // ui->boutonCalendrier->setStyleSheet("QToolButton, #qt_calendar_navigationbar{background-color : #FFD3DA; color: #000000}");
       // ui->boutonToday->setStyleSheet("background-color : #FFD3DA;");
        parent->sb->setStyleSheet("background-color : #FFFF4A; color : #892535");
        parent->sb->showMessage("Ne pas oublier la date d'entrée dans le service");
    }
    else
    {
//        ui->boutonCalendrier->setStyleSheet("");
//        ui->boutonToday->setStyleSheet("");
        parent->sb->setStyleSheet("");
        parent->sb->clearMessage();

        /*
        QPalette p = ui->frame_3->palette();
        ui->frame_4->setPalette(p);
        */
    }


}

void ChambrePanel::oxyDebUpdated()
{
    if(ui->oxyDeb->value() >= 1.5)
    {
        if(ui->oxyDeb->value() == 1.5)
            ui->oxyDeb->setValue(2.);
        ui->oxyDeb->setSingleStep(1);
        ui->oxyDeb->setDecimals(0);
    }

    if(ui->oxyDeb->value() <= 1)
    {
        if(ui->oxyDeb->value() == 0.5)
            ui->oxyDeb->setDecimals(1);
        else
            ui->oxyDeb->setDecimals(0);
        ui->oxyDeb->setSingleStep(.5);
    }

}

void ChambrePanel::setDateToday()
{
    emit dateUpdate(QDate::currentDate());
}

void ChambrePanel::eraseDate()
{
    setDate("");
}

void ChambrePanel::razDateToggle()
{
    ui->razDate->setEnabled(ui->dateEntree->text() != "");
}

//SLOTS

// GETTERS AND SETTERS
QString ChambrePanel::getTitre(){
    return ui->titre->text();
}

void ChambrePanel::setTitre(QString str){
    ui->titre->setText(str);
}

QString ChambrePanel::getMisc()
{
    return ui->misc->toPlainText();
}

void ChambrePanel::setMisc(QString texte)
{
    ui->misc->setText(texte);
}

bool ChambrePanel::getAerosolsCheck()
{
    return ui->AerosolsCheck->isChecked();
}

void ChambrePanel::setAerosolsCheck(bool checked)
{
    ui->AerosolsCheck->setChecked(checked);
}

void ChambrePanel::setAerosolsCheck(QString checked)
{
    if(checked == "true")
        ui->AerosolsCheck->setChecked(true);
    else
        ui->AerosolsCheck->setChecked(false);
}

bool ChambrePanel::getOxyCheck()
{
    return ui->OxyCheck->isChecked();
}

void ChambrePanel::setOxyCheck(bool checked)
{
    ui->OxyCheck->setChecked(checked);
}

void ChambrePanel::setOxyCheck(QString checked)
{
    if(checked == "true")
        ui->OxyCheck->setChecked(true);
    else
        ui->OxyCheck->setChecked(false);
}

bool ChambrePanel::getAllergiesCheck()
{
    return ui->allergiesCheck->isChecked();
}

void ChambrePanel::setAllergiesCheck(bool checked)
{
    ui->allergiesCheck->setChecked(checked);
}

void ChambrePanel::setAllergiesCheck(QString checked)
{
    if(checked == "true")
        ui->allergiesCheck->setChecked(true);
    else
        ui->allergiesCheck->setChecked(false);
}

bool ChambrePanel::getReaChecked()
{
  return ui->reaCheck->isChecked();
}

void ChambrePanel::setReaChecked(bool checked)
{
    ui->reaCheck->setChecked(checked);
}

void ChambrePanel::setReaChecked(QString checked)
{
    if(checked == "true")
        ui->reaCheck->setChecked(true);
    else
        ui->reaCheck->setChecked(false);
}

bool ChambrePanel::getSondeVesCheck()
{
    return ui->sondeVesCheck->isChecked();
}

void ChambrePanel::setSondeVesCheck(bool checked)
{
    ui->sondeVesCheck->setChecked(checked);
}

void ChambrePanel::setSondeVesCheck(QString checked)
{
    if(checked == "true")
        ui->sondeVesCheck->setChecked(true);
    else
        ui->sondeVesCheck->setChecked(false);
}

bool ChambrePanel::getPansementsCheck()
{
    return ui->pansementsCheck->isChecked();
}

void ChambrePanel::setPansementsCheck(bool checked)
{
    ui->pansementsCheck->setChecked(checked);
    miseEnPage();
}

QString ChambrePanel::getOxyDeb()
{
    return QString::number(ui->oxyDeb->value());
}

void ChambrePanel::setOxyDeb(double debit)
{
    ui->oxyDeb->setValue(debit);
}

void ChambrePanel::setOxyDeb(QString debit)
{
    ui->oxyDeb->setValue(debit.toDouble());
}



QString ChambrePanel::getAllergiesText()
{
    return ui->allergiesText->toPlainText();
}

void ChambrePanel::setAllergiesText(QString allergies)
{
    ui->allergiesText->setText(allergies);
}

QString ChambrePanel::getReaText()
{
    return ui->reaText->toPlainText();
}

void ChambrePanel::setReaText(QString rea)
{
    ui->reaText->setText(rea);
}

QString ChambrePanel::getSondeVesCombo()
{
    return ui->sondeVesCombo->currentText();
}

int ChambrePanel::getSondeVesComboIndex()
{
    return ui->sondeVesCombo->currentIndex();
}

void ChambrePanel::setSondeVesCombo(QString sondeVes)
{
    ui->sondeVesCombo->setCurrentIndex(sondeVes.toInt());
}

QString ChambrePanel::getNomText()
{
    return ui->nomText->text();
}

void ChambrePanel::setNomText(QString nom)
{
    ui->nomText->setText(nom);
}

QString ChambrePanel::getAtcdText()
{
    return ui->atcdText->toPlainText();
}

void ChambrePanel::setAtcdText(QString atcd)
{
    ui->atcdText->setText(atcd);
}

QString ChambrePanel::getExamText()
{
    return ui->examText->toPlainText();
}

void ChambrePanel::setExamText(QString exam)
{
    ui->examText->setText(exam);
}

QString ChambrePanel::getMotifEntreeText()
{
    return ui->motifEntreeText->toPlainText();
}

void ChambrePanel::setMotifEntreeText(QString motifEntree)
{
    ui->motifEntreeText->setText(motifEntree);
}

QString ChambrePanel::getReaBigText()
{
    return ui->reaBigText->toPlainText();
}

void ChambrePanel::setReaBigText(QString reaBig)
{
    ui->reaBigText->setText(reaBig);
}

QString ChambrePanel::getPerosText()
{
    return ui->perosText->toPlainText();
}

void ChambrePanel::setPerosText(QString peros)
{
    ui->perosText->setText(peros);
}

QString ChambrePanel::getSortieMainText()
{
    return ui->sortieMainText->toPlainText();
}

void ChambrePanel::setSortieMainText(QString text)
{
    ui->sortieMainText->setText(text);
}

QString ChambrePanel::getSortieSubText()
{
    return ui->sortieSubText->toPlainText();
}

void ChambrePanel::setSortieSubText(QString text)
{
    ui->sortieSubText->setText(text);
}

QString ChambrePanel::getSvMainText()
{
    return ui->svMainText->toPlainText();
}

void ChambrePanel::setSvMainText(QString text)
{
    ui->svMainText->setText(text);
}

QString ChambrePanel::getSvSubText()
{
    return ui->svSubText->toPlainText();
}

void ChambrePanel::setSvSubText(QString text)
{
    ui->svSubText->setText(text);
}

QString ChambrePanel::getDate()
{
    return ui->dateEntree->getDate();
}

void ChambrePanel::setDate(QString date)
{
    if(date == "")
    {
        ui->dateEntree->setDate(date);
    }
    else
    {
    QString date0, date1;
    date0 = date.right(2);
    date0.prepend("20");
    date1 = date.left(6)+date0;
    ui->dateEntree->setDate(date1);
    }
}

void ChambrePanel::setDureeSejour(QString duree)
{
    ui->dureeSejourLabel->setText(duree);
}

QString ChambrePanel::getDureeSejour()
{
    return ui->dureeSejour->text();
}

void ChambrePanel::setNextTab()
{
    this->tabWidget->setNextIndex();
}

void ChambrePanel::setPrevTab()
{
    this->tabWidget->setPreviousIndex();
}

TransTabWidget* ChambrePanel::getTabWidget()
{
    return this->tabWidget;
}

void ChambrePanel::ClearForm()
{
    setMisc("");
    setAerosolsCheck(false);
    setOxyCheck(false);
    setAllergiesCheck(false);
    setReaChecked(false);
    setSondeVesCheck(false);
    setOxyDeb(false);
    setPansementsCheck(false);
    setAllergiesText("");
    setReaText("");
    ui->sondeVesCombo->setCurrentIndex(0);
    setNomText("");
    setAtcdText("");
    setExamText("");
    setMotifEntreeText("");
    setReaBigText("");
    setPerosText("");
    setSortieMainText("Sortie");
    setSortieSubText("");
    setSvMainText("");
    setSvSubText("");
    setDureeSejour("Séjour dans le service :");
    setDate("");
}

//CONNECTIONS

void ChambrePanel::connectToSaveButton()
{
    connect(ui->misc, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->AerosolsCheck, SIGNAL(clicked()),parent, SLOT(toggleSaveTrue()));
    connect(ui->allergiesCheck, SIGNAL(clicked()),parent, SLOT(toggleSaveTrue()));
    connect(ui->OxyCheck, SIGNAL(clicked()),parent, SLOT(toggleSaveTrue()));
    connect(ui->reaCheck, SIGNAL(clicked()),parent, SLOT(toggleSaveTrue()));
    connect(ui->sondeVesCheck, SIGNAL(clicked()),parent, SLOT(toggleSaveTrue()));
    connect(ui->reaText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->allergiesText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->nomText, SIGNAL(textChanged(QString)),parent, SLOT(toggleSaveTrue()));
    connect(ui->motifEntreeText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->atcdText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->reaBigText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->examText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->sortieMainText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->sortieSubText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->svMainText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->svSubText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->perosText, SIGNAL(textChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->dateEntree, SIGNAL(dateChanged()),parent, SLOT(toggleSaveTrue()));
    connect(ui->pansementsCheck, SIGNAL(clicked()),parent, SLOT(toggleSaveTrue()));

}

void ChambrePanel::connectInterfaceParts()
{
    connect(ui->sondeVesCheck, SIGNAL(toggled(bool)),this,SLOT(sondeVesChecked()));
    connect(ui->OxyCheck,SIGNAL(toggled(bool)),this,SLOT(oxyChecked()));
    connect(ui->reaCheck,SIGNAL(toggled(bool)),this,SLOT(reaChecked()));
    connect(ui->AerosolsCheck,SIGNAL(toggled(bool)),this,SLOT(aerosolChecked()));
    connect(ui->allergiesCheck,SIGNAL(toggled(bool)),this,SLOT(allergiesChecked()));
    connect(ui->sondeVesCombo,SIGNAL(currentIndexChanged(int)),this,SLOT(miseEnPage()));
    connect(ui->oxyDeb,SIGNAL(valueChanged(double)),this,SLOT(miseEnPage()));
    connect(ui->pansementsCheck,SIGNAL(toggled(bool)),this,SLOT(miseEnPage()));
}

void ChambrePanel::disconnectFromSaveButton()
{

}

//CONNECTIONS
