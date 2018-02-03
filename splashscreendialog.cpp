#include "splashscreendialog.h"
#include "ui_splashscreendialog.h"
#include "gestiontabwidget.h"
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QTimer>
#include <QThread>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QSequentialAnimationGroup>
#include <qdebug.h>


SplashScreenDialog::SplashScreenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashScreenDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->setWindowFlags(this->windowFlags() | Qt::FramelessWindowHint);
    ui->listWidget->setVisible(false);
    opacity =0;
    duration = 600;

    ui->petale1->setVisible(false);
    ui->petale2->setVisible(false);
    ui->petale3->setVisible(false);
    ui->label->setVisible(false);

}

SplashScreenDialog::~SplashScreenDialog()
{
    delete ui;
}

void SplashScreenDialog::setSelector(Transmain* mainClass)
{

    {
        mainWindow = static_cast<Transmain *>(mainClass);
        QList<Secteur *>* sect = mainWindow->getGestionnaire()->getSect();
        QList<QListWidgetItem*> listeSecteurs;
        secteurslist = new QStringList();

        for(int i = 0; i<sect->count(); i++)
        {
            QString tmp = sect->at(i)->getNom();
            secteurslist->append(tmp);
            QListWidgetItem* itm = new QListWidgetItem("Secteur " +tmp+ ", chambres "+ sect->at(i)->getChambres().at(0)+" à "+ sect->at(i)->getChambres().last());

            QPixmap pix(22,22);
            pix.fill(Qt::transparent);
            QPainter paint(&pix);
            paint.setRenderHint(QPainter::Antialiasing);
            paint.setPen(QPen(QColor(0,0,0,0)));
            paint.setBrush(QBrush(sect->at(i)->getBackgrounddColor()));
            paint.setOpacity(0.9);
            paint.drawRoundedRect(QRect(0,0,22,22),3,3);
            //paint.fillRect(QRectF(0,0,32,32),QBrush(gestionnaire->getSect()->at(i)->getFontColor()));
            paint.end();
            QIcon ic(pix);
            itm->setIcon(ic);
            listeSecteurs.append(itm);

        }

        for(int i = 0; i< listeSecteurs.count() ; i++)
        {
            ui->listWidget->addItem(listeSecteurs.at(i));
        }

        connect(ui->listWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(setSecteur(QModelIndex)));
        ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->listWidget->setStyleSheet("QListWidget {background-image: url(null);background-color : rgb(255,255,255,0);}"
                                      "QListWidget::item{height : 25;border-radius: 3px;color : rgb(3,115,125);}"
                                      "QListWidget::item:hover{background-color : rgb(88,156,170);	color: rgb(255, 255, 255);}");
        ui->listWidget->setVisible(true);
        QGraphicsOpacityEffect* fade_effect = new QGraphicsOpacityEffect(ui->listWidget);
        ui->listWidget->setGraphicsEffect(fade_effect);
        QPropertyAnimation *animation = new QPropertyAnimation(fade_effect, "opacity");
        animation->setEasingCurve(QEasingCurve::OutCirc);
        animation->setDuration(500);
        animation->setStartValue(0.01);
        animation->setEndValue(1.0);
        animation->start();
        this->setCursor(QCursor(Qt::ArrowCursor));

    }
}

void SplashScreenDialog::setSecteur(QModelIndex idx)
{
    QString str = secteurslist->at(idx.row());
    mainWindow->getGestionnaire()->setCote(mainWindow->getGestionnaire()->getSectbyName(str));
    mainWindow->getGestionnaire()->setSecteurTabs(mainWindow->getGestionnaire()->getCote());
    mainWindow->show();
    this->close();
}

void SplashScreenDialog::start()
{/*
    if(dure != 0)
        duration = dure;

    opacity =0;
    */
    QApplication::processEvents();
    show();
    QApplication::processEvents();
    QPropertyAnimation *animation = new QPropertyAnimation(this,"windowOpacity");
    animation->setDuration(500);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->start();
    QApplication::processEvents();

/*
    QSequentialAnimationGroup* ag = new QSequentialAnimationGroup();
    QGraphicsOpacityEffect* fade_effect_p1 = new QGraphicsOpacityEffect(ui->petale1);
    QGraphicsOpacityEffect* fade_effect_p2 = new QGraphicsOpacityEffect(ui->petale2);
    QGraphicsOpacityEffect* fade_effect_p3 = new QGraphicsOpacityEffect(ui->petale3);
    ui->petale1->setGraphicsEffect(fade_effect_p1);
    ui->petale2->setGraphicsEffect(fade_effect_p2);
    ui->petale3->setGraphicsEffect(fade_effect_p3);
    QApplication::processEvents();
    QPropertyAnimation *anim_p1 = new QPropertyAnimation(fade_effect_p1, "opacity");
    anim_p1->setEasingCurve(QEasingCurve::OutCirc);
    anim_p1->setDuration(500);
    anim_p1->setStartValue(0.01);
    anim_p1->setEndValue(1.0);
    QApplication::processEvents();
    QPropertyAnimation *anim_p2 = new QPropertyAnimation(fade_effect_p2, "opacity");
    anim_p2->setEasingCurve(QEasingCurve::OutCirc);
    anim_p2->setDuration(500);
    anim_p2->setStartValue(0.01);
    anim_p2->setEndValue(1.0);
    QApplication::processEvents();
    QPropertyAnimation *anim_p3 = new QPropertyAnimation(fade_effect_p3, "opacity");
    anim_p3->setEasingCurve(QEasingCurve::OutCirc);
    anim_p3->setDuration(500);
    anim_p3->setStartValue(0.01);
    anim_p3->setEndValue(1.0);
    QApplication::processEvents();
    ag->addAnimation(anim_p1);
    ag->addAnimation(anim_p2);
    ag->addAnimation(anim_p3);
    ui->petale1->setVisible(true);
    ui->petale2->setVisible(true);
    ui->petale3->setVisible(true);
    ag->start();

    */
    time =0;
    interval = 10;
    isRunning = true;
    petal1aff = petale2aff = petale3aff = false;
    duration1 = duration2 = duration3 = 300;
    while(time <=duration1)
    {
        QApplication::processEvents();
        this->update();
        QApplication::processEvents();
        time += interval;
        QThread::msleep(interval);
        QApplication::processEvents();
    }
    QThread::msleep(66);
    time = 0;
    petal1aff = true;
    while(time <=duration2)
    {
        QApplication::processEvents();
        this->update();
        QApplication::processEvents();
        time += interval;
        QThread::msleep(interval);
        QApplication::processEvents();
    }
    QThread::msleep(66);
    time = 0;
    petale2aff = true;
    while(time <=duration3)
    {
        QApplication::processEvents();
        this->update();
        QApplication::processEvents();
        time += interval;
        QThread::msleep(interval);
        QApplication::processEvents();
    }
    isRunning = false;
    this->update();
    QApplication::processEvents();

}

void SplashScreenDialog::paintEvent(QPaintEvent *evt)
{
    QPoint pPetal1Raw(16,0), pPetal2Raw(0,7), pPetal3Raw(1,26), pTitreRaw(18,35);
    QPoint delta(152,55), subDeltaFleur(0,0), subDeltaTitre(0,0);// DELTAS
    //qreal deltaY = 45; //Delta Y en pixels
    QPoint pPetal1 = pPetal1Raw+delta+subDeltaFleur;
    QPoint pPetal2 = pPetal2Raw+delta+subDeltaFleur;
    QPoint pPetal3 = pPetal3Raw+delta+subDeltaFleur;
    QPoint pTitre = pTitreRaw+delta+subDeltaTitre;


    QDialog::paintEvent(evt);

    if(isRunning)
    {
        QPainter paint(this);
        QPixmap petal1(":/petal1");
        QPixmap petal2(":/petal2");
        QPixmap petal3(":/petal3");
        QPixmap titre(":/titre");
        opacity = (float)time/duration1;
        if(petal1aff == false)
            paint.setOpacity(opacity);
        else
            paint.setOpacity(1);

        paint.drawPixmap(pPetal3,petal3);
        if(petal1aff == false )
            paint.setOpacity(0);
        if(petal1aff == true)
            paint.setOpacity(opacity);
        if(petale2aff == true)
            paint.setOpacity(1);
        paint.drawPixmap(pPetal2,petal2);
        if(petale2aff == false)
            paint.setOpacity(0);
        if(petale2aff == true)
            paint.setOpacity(opacity);
        if(petale3aff == true)
            paint.setOpacity(1);
        paint.drawPixmap(pPetal1,petal1);
        paint.setOpacity(1);
        paint.drawPixmap(pTitre, titre);
    }
    else
    {
        QPainter paint(this);
        QPixmap petal1(":/petal1");
        QPixmap petal2(":/petal2");
        QPixmap petal3(":/petal3");
        QPixmap titre(":/titre");
        paint.drawPixmap(pPetal1,petal1);
        paint.drawPixmap(pPetal2,petal2);
        paint.drawPixmap(pPetal3,petal3);
        paint.drawPixmap(pTitre, titre);
    }

}
