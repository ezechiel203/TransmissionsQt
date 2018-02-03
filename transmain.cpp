#include "transmain.h"
#include "transtabwidget.h"
#include "chambrepanel.h"
#include "ui_transmain.h"
#include "gestiontabwidget.h"
#include "exitformdialog.h"
#include "aboutformdialog.h"
#include "switchrooms.h"
#include "transdocument.h"
#include "choixsecteurdialog.h"
#include "clickableqlabel.h"
#include <secteur.h>
#include <lecturexml.h>
#include <QFontMetrics>
#include <QRect>
#include <ecriturexml.h>
#include <QFileDialog>
#include <QDebug>
#include <transprintpreview.h>
#include <transprintmarginsdialog.h>
#include <QPrintDialog>
#include <splashscreen.h>
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QToolButton>
#include <QWidgetAction>
#include <transprinterfactory.h>
#include <QStatusBar>
#include <QListWidget>
#include <QShortcut>

#define VERSION "v3.1.5"
#define YEARCPY "2018"
#define AUTHORFULL "Alexandre BETRY"
#define AUTHORMIN "A BETRY"
#define APPNAME "Transmissions IDE"
#define EMAIL "alexandre.betry@gmail.com"

Transmain::Transmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Transmain)
{

    sb = new QStatusBar(this);
    this->clearFormShow = true;
    ui->setupUi(this);



    this->setStatusBar(sb);
    ClickableQLabel* bottomLabel = new ClickableQLabel();
    sb->addPermanentWidget(bottomLabel);

    this->setWindowTitle(APPNAME);
    //Bottom line text :

    bottomLabel->setText(QString("%1 %2 ©%3 %4").arg(APPNAME,VERSION,YEARCPY,AUTHORMIN));
    bottomLabel->setStyleSheet("color : #808080;");

    ui->tabWidget->clear();
    this->gestionnaire = new GestionTabWidget(ui->tabWidget, this);

    //Insert Secteur actions in correct menu
    QList<QAction *> actions;
    for(int i=0 ; i<gestionnaire->getSect()->count() ; i++){
        QAction* act = new QAction(gestionnaire->getSect()->at(i)->getNom(),this);
        actions.append(act);
        act->setObjectName(gestionnaire->getSect()->at(i)->getNom());
        act->setToolTip("Secteur "+gestionnaire->getSect()->at(i)->getNom());
        QPixmap pix(32,32);
        pix.fill(Qt::transparent);
        QPainter paint(&pix);
        paint.setRenderHint(QPainter::Antialiasing);
        paint.setPen(QPen(QColor(0,0,0,0)));
        paint.setBrush(QBrush(gestionnaire->getSect()->at(i)->getBackgrounddColor()));
        paint.setOpacity(1);
        paint.drawRoundedRect(QRect(0,0,32,32),7,7);
        //paint.fillRect(QRectF(0,0,32,32),QBrush(gestionnaire->getSect()->at(i)->getFontColor()));
        paint.end();
        QIcon ic(pix);
        act->setIcon(ic);
        connect(act, &QAction::triggered, gestionnaire, &GestionTabWidget::changeCote);
    }
        ui->menuSecteur->addActions(actions);

// Connexions actions menu
    connect(ui->actionFermer,SIGNAL(triggered()),this,SLOT(close()));
    connect(this,SIGNAL(saveToggled(bool)),ui->actionEnregistrer,SLOT(setEnabled(bool)));
    connect(ui->actionEnregistrer_Sous, SIGNAL(triggered()),this, SLOT(saveUnderAction()));
    connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(openAction()));
    connect(ui->actionEnregistrer, SIGNAL(triggered()), this,SLOT(saveAction()));
    //lecture xml
    LectureXML lxml = LectureXML(gestionnaire);
    lxml.fillPanels();
    lxml.closeDelete();
    this->toggleSaveFalse();

/*
    EcritureXML exml = EcritureXML(gestionnaire);
    exml.save();
    exml.closeDelete();
    */

    //On rajoute les menus options et a propos à la barre de menu
    QAction* options = ui->menuBar->addAction("Options");
    QAction* apropos = ui->menuBar->addAction("À propos");
    connect(options, SIGNAL(triggered()), this, SLOT(showOptions()));
    connect(apropos, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(bottomLabel, SIGNAL(clicked()),this, SLOT(showAbout()));
//Mise en forme de la barre de tache principale, de ses actions et notamment des fleches de changement
//de tab ; ajout de spacers
    ui->mainToolBar->setIconSize(QSize(32,32));
    ui->mainToolBar->addSeparator();


    //actions impression
    QAction* preview = ui->mainToolBar->addAction("");
    QAction* printFast  = ui->mainToolBar->addAction("");
    QAction* print = new QAction(this);//ui->mainToolBar->addAction("");
    QToolButton* printPlusButton = new QToolButton(this);
    printPlusButton->setPopupMode(QToolButton::InstantPopup);
    ui->mainToolBar->addWidget(printPlusButton);
    QMenu* printPlusMenu = new QMenu(this);
    QWidgetAction* printPlusAction = new QWidgetAction(printPlusMenu);
    TransPrinterFactory* fact = new TransPrinterFactory(this);
    printPlusAction->setDefaultWidget(fact);
    printPlusMenu->addAction(printPlusAction);
    printPlusButton->setMenu(printPlusMenu);
    connect(printPlusMenu, SIGNAL(aboutToShow()), fact, SLOT(updateCombo()));
    QIcon previewic, printFastic, printic, printPlusic;
    previewic.addFile(QStringLiteral(":/printpreview"), QSize(), QIcon::Normal, QIcon::Off);
    printFastic.addFile(QStringLiteral(":/printfast"), QSize(), QIcon::Normal, QIcon::Off);
    printic.addFile(QStringLiteral(":/print"), QSize(), QIcon::Normal, QIcon::Off);
    printPlusic.addFile(QStringLiteral(":/printplus"), QSize(), QIcon::Normal, QIcon::Off);
    preview->setIcon(previewic);
    printFast->setIcon(printFastic);
    print->setIcon(printic);
    printPlusButton->setIcon(printPlusic);
    preview->setToolTip("Prévisualiser");
    printFast->setToolTip("Impression rapide (1 exemplaire)");
    print->setToolTip("Impression personnalisée (1 ou plusieurs pages)");
    connect(printFast, SIGNAL(triggered()), this, SLOT(printFast()));
    connect(preview, SIGNAL(triggered()), this, SLOT(printPreview()));
    connect(print, SIGNAL(triggered()), this, SLOT(printOpts()));
    connect(ui->actionImprimer, SIGNAL(triggered()), this, SLOT(printOpts()));
    //action switchrooms
    ui->mainToolBar->addSeparator();
    QAction* switchrooms = ui->mainToolBar->addAction("");
    QIcon switchroomsic;
    switchroomsic.addFile(QStringLiteral(":/lit"), QSize(), QIcon::Normal, QIcon::Off);
    switchrooms->setIcon(switchroomsic);
    switchrooms->setToolTip("Mouvement interne au service");
    connect(switchrooms, SIGNAL(triggered()),this, SLOT(switchRoomsClicked()));

    //listWidget de sélection des secteurs
    ui->mainToolBar->addSeparator();
    QListWidget* lw = new QListWidget(this);
    QList<Secteur *>* sects = gestionnaire->getSect();
    for(int i=0; i < sects->count() ; i++)
    {
        QListWidgetItem* itm = new QListWidgetItem("Secteur " +sects->at(i)->getNom(), lw);
        QPixmap pix(12,12);
        pix.fill(Qt::transparent);
        QPainter paint(&pix);
        paint.setRenderHint(QPainter::Antialiasing);
        paint.setPen(QPen(QColor(0,0,0,0)));
        paint.setBrush(QBrush(sects->at(i)->getBackgrounddColor()));
        paint.setOpacity(1);
        paint.drawRoundedRect(QRect(0,0,12,12),4,4);
        //paint.fillRect(QRectF(0,0,32,32),QBrush(gestionnaire->getSect()->at(i)->getFontColor()));
        paint.end();
        QIcon ic(pix);
        itm->setIcon(ic);
       // lw->addItem(itm);

    }
    lw->setStyleSheet("QListWidget{ background-image: url(null);background-color : rgb(255,255,255,0);}"
                      "QListWidget::item{height : 17;border: 1px solid rgb(253,253,253,0);border-radius: 3px;color : rgb(80,80,80);}"
                      "QListWidget::item:hover{background-color: #B5E3FC;border: 1px;border-color: #E0E0E0;}");
    lw->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    lw->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    lw->setMaximumWidth(lw->sizeHintForColumn(0)+2);
    lw->setMaximumHeight(40);
    ui->mainToolBar->addWidget(lw);
    connect(lw, SIGNAL(currentRowChanged(int)), gestionnaire, SLOT(changeCoteInt(int)));

    //lw->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

   /* TODO : AJOUTER UN BOUTON PERMETTANT L'AJOUT DE CARACTERES SPECIAUX

     //Boutons de caractères spéciaux
    ui->mainToolBar->addSeparator();
    //QAction* stopChar = new QAction(this);
    QToolButton* stopCharButton = new QToolButton(this);
    stopCharButton->setText("Ω");
    stopCharButton->setStyleSheet("font: bold 20px");
    stopCharButton->setMinimumSize(32,32);
    ui->mainToolBar->addWidget(stopCharButton);

//*/
    //stopChar->setToolTip("Caractère spécial ↕");
/*
    //Spacer permettant de renvoyer les fleches à droite de la toolbar
    ui->mainToolBar->addSeparator();
    QWidget* spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->mainToolBar->addWidget(spacer);
    QAction* left = ui->mainToolBar->addAction("");
    QIcon leftic;
    leftic.addFile(QStringLiteral(":/left_arrow"), QSize(), QIcon::Normal, QIcon::Off);
    left->setIcon(leftic);
    QAction* right = ui->mainToolBar->addAction("");
    QIcon rightic;
    rightic.addFile(QStringLiteral(":/right_arrow"), QSize(), QIcon::Normal, QIcon::Off);
    right->setIcon(rightic);
    connect(left,SIGNAL(triggered()),ui->tabWidget,SLOT(setPreviousIndex()));
    connect(right,SIGNAL(triggered()),ui->tabWidget,SLOT(setNextIndex()));
    connect(ui->tabWidget,SIGNAL(firstIndexReached(bool)),left,SLOT(setEnabled(bool)));
    connect(ui->tabWidget,SIGNAL(lastIndexReached(bool)),right,SLOT(setEnabled(bool)));
    QWidget* spacer2 = new QWidget();
    spacer2->setMinimumWidth(15);
    ui->mainToolBar->addWidget(spacer2);*/







        //Spacer permettant de renvoyer les fleches à droite de la toolbar
        ui->mainToolBar->addSeparator();
        QWidget* spacer = new QWidget();
        spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->mainToolBar->addWidget(spacer);
        QLabel* helpIcon = new QLabel();
        helpIcon->setMinimumSize(40,40);
        ui->mainToolBar->addWidget(helpIcon);
        helpIcon->setToolTipDuration(15000);
        helpIcon->setStyleSheet("QPushButton {border : 0px; background-color : #FDFDFD;} QToolTip {min-width : 200 px; background-color : white;}");
        helpIcon->setToolTip("<html><b>Raccourcis clavier / accès rapide</b><br /><b>CTRL + <span style=\"font-size : 25px;\">→</span></b> : Chambre suivante<br /><b>CTRL + <span style=\"font-size : 25px;\">←</span></b> : Chambre précédente<br /><b>CTRL + <span style=\"font-size : 25px;\">↑</span></b> : Changer de secteur</html>");
        QPixmap leftic(":/info");
        QPixmap lefticScaled = leftic.scaled(QSize(40,40), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        helpIcon->setPixmap(lefticScaled);
        //leftic.addFile(QStringLiteral(":/info"), QSize(), QIcon::Normal, QIcon::Off);
        //helpIcon->setIcon(leftic);
        //helpIcon->setIconSize(QSize(40,40));
        QWidget* spacer2 = new QWidget();
        spacer2->setMinimumWidth(15);
        ui->mainToolBar->addWidget(spacer2);
       // this->helpButton = helpIcon;
        //connect(helpIcon,SIGNAL(clicked(bool)),this,SLOT(triggerToolTip(bool)));





    ui->mainToolBar->setStyleSheet("QPushButton {border : 0px; background-color : #FDFDFD;}"
                                   "QToolButton {border : 0px; background-color : #FDFDFD;}"
                                   "QPushButton:hover {background-color : #B5E3FC;}"
                                   "QToolButton:hover {background-color : #B5E3FC;}"
                                   "QPushButton:pressed {border : 1px static #E0E0E0 ; background-color : #DADADA;}"
                                   "QToolButton:pressed {border : 1px static #E0E0E0; background-color : #DADADA;}");
    //Reset des messages de la statusBar au changement d'onglet.
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), sb, SLOT(clearMessage()));
    //Efface les messages de la status bar qui auraitent pu être affichés pendant l'initialisation
    sb->clearMessage();

    //Mise en forme TabWidget

    ui->tabWidget->setStyleSheet("QTabWidget::tab-bar {min-width: 999999px;}");
    ui->tabWidget->tabBar()->setExpanding(true);

    //Mise en place de SHORTCUTS
    QKeySequence flecheD(Qt::CTRL+Qt::Key_Right);
    QKeySequence flecheG(Qt::CTRL+Qt::Key_Left);
    QKeySequence flecheH(Qt::CTRL+Qt::Key_Up);
    QKeySequence flecheB(Qt::CTRL+Qt::Key_Down);
    QKeySequence home(Qt::CTRL+Qt::Key_Home);
    QKeySequence end(Qt::CTRL+Qt::Key_End);

    QShortcut *goRight = new QShortcut(flecheD,ui->tabWidget,nullptr,nullptr,Qt::ApplicationShortcut);
    QShortcut *goLeft = new QShortcut(flecheG,ui->tabWidget,nullptr,nullptr,Qt::ApplicationShortcut);
    QShortcut *goFirst = new QShortcut(home,ui->tabWidget,nullptr,nullptr,Qt::ApplicationShortcut);
    QShortcut *goLast = new QShortcut(end,ui->tabWidget,nullptr,nullptr,Qt::ApplicationShortcut);
    QShortcut *nextCote = new QShortcut(flecheH,this,nullptr,nullptr,Qt::ApplicationShortcut);
    QShortcut *prevCote = new QShortcut(flecheB,this,nullptr,nullptr,Qt::ApplicationShortcut);

    connect(goRight,SIGNAL(activatedAmbiguously()),ui->tabWidget,SLOT(setNextIndex()));
    connect(goLeft,SIGNAL(activatedAmbiguously()),ui->tabWidget,SLOT(setPreviousIndex()));
    connect(goFirst,SIGNAL(activatedAmbiguously()),ui->tabWidget,SLOT(setFirst()));
    connect(goLast,SIGNAL(activatedAmbiguously()),ui->tabWidget,SLOT(setLast()));
    connect(goRight,SIGNAL(activated()),ui->tabWidget,SLOT(setNextIndex()));
    connect(goLeft,SIGNAL(activated()),ui->tabWidget,SLOT(setPreviousIndex()));
    connect(goFirst,SIGNAL(activated()),ui->tabWidget,SLOT(setFirst()));
    connect(goLast,SIGNAL(activated()),ui->tabWidget,SLOT(setLast()));
    connect(nextCote,SIGNAL(activated()),this,SLOT(chCote()));
    connect(prevCote,SIGNAL(activated()),this,SLOT(chCote()));


}

Transmain::~Transmain()
{
    delete ui;
}


//Fonctions pour la fonctionnalité clearform et sa boite de dialogue
void Transmain::setClearFormShow(bool check)
{
    this->clearFormShow = check;
}

bool Transmain::getClearFormShow()
{
    return this->clearFormShow;
}

//Fonctions pour la gestion de l'activation des fonctionnalités d'enregistrement
void Transmain::setSave(bool check)
{
    if(this->save != check){
        this->save = !this->save;
        emit this->saveToggled(save);
    }

}

bool Transmain::getSave()
{
    return this->save;
}
void Transmain::printFast(QList<Secteur *> * sects)
{
    TransDocument doc(gestionnaire, this);
    doc.printDocument(sects);
}

void Transmain::showOptions()
{
    TransDocument doc(gestionnaire, this);
    TransPrintMarginsDialog* dlg = new TransPrintMarginsDialog(&doc,this, gestionnaire);
    dlg->exec();
    delete dlg;
}

GestionTabWidget* Transmain::getGestionnaire()
{
    return gestionnaire;
}

QString Transmain::getVersion()
{
    return VERSION;
}

QString Transmain::getYearcpy()
{
    return YEARCPY;
}

QString Transmain::getAuthorFull()
{
    return AUTHORFULL;
}

QString Transmain::getAuthorMin()
{
    return AUTHORMIN;
}

QString Transmain::getAppName()
{
    return APPNAME;
}

QString Transmain::getAuthorMail()
{
    return EMAIL;
}

void Transmain::toggleSaveTrue()
{
    this->gestionnaire->updateTimeInBeds();
    if(!this->save){
        this->save = true;
        emit this->saveToggled(save);
    }
}

void Transmain::toggleSaveFalse()
{
    if(this->save){
        this->save = false;
        emit this->saveToggled(save);
    }
}

void Transmain::saveAction()
{
    EcritureXML exml = EcritureXML(gestionnaire);
    exml.save();
    exml.closeDelete();
    gestionnaire->getCote()->setLastEditEpoch(QString::number(QDateTime::currentMSecsSinceEpoch()));
    this->toggleSaveFalse();
}

void Transmain::saveUnderAction()
{
    QString saveFile = QFileDialog::getSaveFileName(this, tr("Enregistrer"),"transmissions.sav", tr("Fichiers de sauvegarde Transmission (*.sav);;Tous les fichiers"));
    if(saveFile != "")
    {
        EcritureXML exml = EcritureXML(saveFile,gestionnaire);
        exml.save();
        exml.closeDelete();
        this->toggleSaveFalse();
    }
}

void Transmain::openAction()
{
    QString openFile = QFileDialog::getOpenFileName(this, tr("Ouvrir"),"", tr("Fichiers de sauvegarde Transmission (*.sav);;Tous les fichiers"));
    if(openFile != "")
    {
        LectureXML lxml = LectureXML(openFile,gestionnaire);
        lxml.fillPanels();
        lxml.closeDelete();
        this->toggleSaveFalse();
    }
}

void Transmain::showAbout()
{
    AboutFormDialog* dlg = new AboutFormDialog(this);
    dlg->exec();
}

void Transmain::switchRoomsClicked()
{
    SwitchRooms* sr = new SwitchRooms(this->gestionnaire,this);
    sr->exec();
    delete sr;
}

void Transmain::printPreview()
{
    TransDocument doc(gestionnaire, this);
    TransPrintPreview* prev = new TransPrintPreview(&doc, this);
    prev->setWindowFlags(prev->windowFlags()&~(Qt::WindowContextHelpButtonHint));
    prev->setWindowFlags(prev->windowFlags() | Qt::WindowStaysOnTopHint | Qt::WindowMaximizeButtonHint);
    QDesktopWidget widget;
    QRect mainScreenSize = widget.availableGeometry(-1);
    prev->setMinimumSize(mainScreenSize.width()*0.5,mainScreenSize.height()-40);
    prev->showMaximized();
    prev->exec();
}

void Transmain::chCote()
{
    gestionnaire->cycleCote();
}

void Transmain::printOpts(QList<Secteur *>* sects)
{
    TransDocument doc(gestionnaire, this);
    QPrintDialog* dlg = new QPrintDialog(doc.getPrinter(), this);
    if (dlg->exec() == QDialog::Accepted) {
            doc.printDocument(dlg->printer(), sects);
        }
    delete dlg;
}

void Transmain::closeEvent(QCloseEvent* evt)
{
    if(this->getSave()){
        ExitFormDialog* exit = new ExitFormDialog();
        connect(exit, SIGNAL(acceptedclick()), this, SLOT(saveAction()));
        exit->exec();
        if(exit->getCloseAfter())
            evt->accept();
        else
            evt->ignore();
        delete exit;
    }
    else
        evt->accept();
   // gestionnaire->cycleCote();
}
