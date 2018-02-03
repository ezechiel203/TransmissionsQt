#include "choixsecteurdialog.h"
#include "gestiontabwidget.h"
#include "ui_choixsecteurdialog.h"
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QBrush>

ChoixSecteurDialog::ChoixSecteurialog(QWidget *parent) :
    QDialog(),
    ui(new Ui::ChoixSecteurDialog)
{
    mainWindow = static_cast<Transmain *>(parent);
    QList<Secteur *>* sect = mainWindow->getGestionnaire()->getSect();
    QList<QListWidgetItem*> listeSecteurs;

    for(int i = 0; i<sect->count(); i++)
    {
        QString tmp = sect->at(i)->getNom();
        tmp.replace(0,1,tmp[0].toTitleCase());
        QListWidgetItem* itm = new QListWidgetItem(tmp);

        QPixmap pix(16,16);
        pix.fill(Qt::transparent);
        QPainter paint(&pix);
        paint.setRenderHint(QPainter::Antialiasing);
        paint.setPen(QPen(sect->at(i)->getFontColor()));
        paint.setBrush(QBrush(sect->at(i)->getFontColor()));
        paint.setOpacity(0.5);
        paint.drawRoundedRect(QRect(0,0,16,16),4,4);
        //paint.fillRect(QRectF(0,0,32,32),QBrush(gestionnaire->getSect()->at(i)->getFontColor()));
        paint.end();
        QIcon ic(pix);
        itm->setIcon(ic);
        listeSecteurs.append(itm);

    }
    ui->setupUi(this);

    for(int i = 0; i< listeSecteurs.count() ; i++)
    {
        ui->listWidget->addItem(listeSecteurs.at(i));
    }

    connect(ui->listWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(setSecteur(QModelIndex)));
    this->setWindowTitle("Choix Secteur :");
    this->setWindowFlags(Qt::Tool);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
}

ChoixSecteurDialog::~ChoixSecteurDialog()
{
    delete ui;
}

void ChoixSecteurDialog::setSecteur(QModelIndex idx)
{
    QString str = idx.data().toString().toLower();
    mainWindow->getGestionnaire()->setCote(mainWindow->getGestionnaire()->getSectbyName(str));
    this->close();
}
