#ifndef SWITCHROOMS_H
#define SWITCHROOMS_H

#include "gestiontabwidget.h"

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class SwitchRooms;
}

class SwitchRooms : public QDialog
{
    Q_OBJECT

public:
    explicit SwitchRooms(GestionTabWidget* gest, QWidget *parent = 0);
    ~SwitchRooms();

private slots:
    void propagerChangement();
    void sectDepChanged(int);
    void sectArrChanged(int);
    void chDepChanged(int);
    void chArrChanged(int);
    void validClicked();
    void affiche();
    void cache();

private:
    Ui::SwitchRooms *ui;
    Transmain* parent;
    GestionTabWidget* gestionnaire;
    QList<QStringList>* chambres;
    QList<Secteur*>* secteurs;
    QList<QList<ChambrePanel*>*>* chambresSecteursList;
    QList<QStringListModel*> chambresListModel;
    void initSecteurModel(QStringListModel *secteursModel);
};

#endif // SWITCHROOMS_H
