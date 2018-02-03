#include "transprintpreview.h"

#include <QToolBar>
#include <QStackedLayout>
#include <QAction>
#include <QIcon>
#include <transprintmarginsdialog.h>
#include <QPrintDialog>
#include <QToolButton>
#include <QWidgetAction>
#include <QMenu>

TransPrintPreview::TransPrintPreview(TransDocument* doc, QWidget *parent) :
    QDialog(parent)
{
    document = doc;
    mainWindow = static_cast<Transmain *>(parent);

    //Creating QPrintPreviewWidget
    preview = new QPrintPreviewWidget(document->getPrinter(), this);

    //creating toolbar
    QToolBar* toolBar = new QToolBar("mainToolBar",this);
    toolBar->setIconSize(QSize(32,32));

    //creating actions
    QAction* zoomIn = toolBar->addAction("");
    QAction* zoomOut = toolBar->addAction("");
    QAction* zoom100 = toolBar->addAction("");
    toolBar->addSeparator();
    QToolButton* sectEdit = new QToolButton(this);
    sectEdit->setPopupMode(QToolButton::InstantPopup);
    toolBar->addWidget(sectEdit);
    toolBar->addSeparator();
    QAction* print = toolBar->addAction("");
    QAction* printOpts = toolBar->addAction("");
    toolBar->addSeparator();
    QAction* options = toolBar->addAction("");
    QIcon zoomInic, zoomOutic, zoom100ic, sectEditic,printic, printOptsic, optionsic;
    zoomInic.addFile(QStringLiteral(":/zoomin"), QSize(), QIcon::Normal, QIcon::Off);
    zoomOutic.addFile(QStringLiteral(":/zoomout"), QSize(), QIcon::Normal, QIcon::Off);
    zoom100ic.addFile(QStringLiteral(":/zoom100"), QSize(), QIcon::Normal, QIcon::Off);
    sectEditic.addFile(QStringLiteral(":/filecfg"), QSize(), QIcon::Normal, QIcon::Off);
    printic.addFile(QStringLiteral(":/printfast"), QSize(), QIcon::Normal, QIcon::Off);
    printOptsic.addFile(QStringLiteral(":/print"), QSize(), QIcon::Normal, QIcon::Off);
    optionsic.addFile(QStringLiteral(":/options"), QSize(), QIcon::Normal, QIcon::Off);
    zoomIn->setIcon(zoomInic);
    zoomOut->setIcon(zoomOutic);
    zoom100->setIcon(zoom100ic);
    sectEdit->setIcon(sectEditic);
    print->setIcon(printic);
    printOpts->setIcon(printOptsic);
    options->setIcon(optionsic);
    zoomIn->setToolTip("Zoom +10%");
    zoomOut->setToolTip("Dézoom -10%");
    zoom100->setToolTip("Zoom 100%");
    sectEdit->setToolTip("Secteur(s) à afficher / imprimer");
    print->setToolTip("Imprimer");
    printOpts->setToolTip("Imptession personnalisée");
    options->setToolTip("Options d'impression");

    QMenu* printPlusMenu = new QMenu(this);
    QWidgetAction* printPlusAction = new QWidgetAction(printPlusMenu);
    fact = new TransSecteurChooserFactory(this);
    printPlusAction->setDefaultWidget(fact);
    printPlusMenu->addAction(printPlusAction);
    sectEdit->setMenu(printPlusMenu);
    //connect(printPlusMenu, SIGNAL(aboutToShow()), fact, SLOT(updateCombo()));

    connect(zoomIn, SIGNAL(triggered()), this, SLOT(zoomIn()));
    connect(zoomOut, SIGNAL(triggered()), this, SLOT(zoomOut()));
    connect(zoom100, SIGNAL(triggered()),this,SLOT(fullScreenZoom()));
    connect(print, SIGNAL(triggered()), preview, SLOT(print()));
    connect(printOpts,SIGNAL(triggered()), this, SLOT(showPrintOpts()));
    connect(options, SIGNAL(triggered()), this, SLOT(showOptions()));

    QVBoxLayout* l = new QVBoxLayout(this);
    l->addWidget(toolBar);
    l->addWidget(preview);
    this->setLayout(l);
    preview->setZoomMode(QPrintPreviewWidget::FitInView);
    connect(this->preview,SIGNAL(paintRequested(QPrinter*)), this, SLOT(emitRepaint(QPrinter*)));
    connect(this,SIGNAL(repaint(QPrinter*,QList<Secteur*>*)), doc, SLOT(refresh(QPrinter*,QList<Secteur*>*)));
    //this->setWindowFlags(this->windowFlags()&Qt::WindowMinimizeButtonHint);
   toolBar->setStyleSheet("QPushButton {border : 0px; background-color : #FDFDFD;}"
                                   "QToolButton {border : 0px; background-color : #FDFDFD;}"
                                   "QPushButton:hover {background-color : #B5E3FC;}"
                                   "QToolButton:hover {background-color : #B5E3FC;}"
                                   "QPushButton:pressed {border : 1px static #E0E0E0 ; background-color : #DADADA;}"
                                   "QToolButton:pressed {border : 1px static #E0E0E0; background-color : #DADADA;}");
}

TransPrintPreview::~TransPrintPreview()
{
    // delete ui;
}

Transmain *TransPrintPreview::getTransmain()
{
    return mainWindow;
}

void TransPrintPreview::showOptions()
{
    TransPrintMarginsDialog* dlg = new TransPrintMarginsDialog(document,this, document->getGestionnaire());
    connect(dlg, SIGNAL(finish_update()), preview, SLOT(updatePreview()));
    dlg->exec();
}

void TransPrintPreview::fullScreenZoom()
{
    preview->fitToWidth();
    preview->fitInView();
}

void TransPrintPreview::zoomIn()
{
    if(preview->zoomFactor()< 5)
        preview->zoomIn();
}

void TransPrintPreview::zoomOut()
{
    if(preview->zoomFactor() > 0.5)
        preview->zoomOut();
}

void TransPrintPreview::showPrintOpts()
{
    QPrintDialog* dlg = new QPrintDialog(document->getPrinter(), this);
    if (dlg->exec() == QDialog::Accepted) {
            document->printDocument(dlg->printer(), fact->getSecteursToPrint());
        }
    delete dlg;
}

void TransPrintPreview::updateSecteurs()
{
/*
    QPrinter print = document->getDefaultPrinter();
    preview = new QPrintPreviewWidget(print, this);
    */
}

void TransPrintPreview::emitRepaint(QPrinter* printer)
{
    emit repaint(printer, fact->getSecteursToPrint());
}
