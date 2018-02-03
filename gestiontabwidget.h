#ifndef GESTIONTABWIDGET_H
#define GESTIONTABWIDGET_H
#include <transtabwidget.h>
#include "transmain.h"
#include <chambrepanel.h>
#include <QList>
#include <secteur.h>
#include <QDate>

class GestionTabWidget : public QObject
{
    Q_OBJECT
public:
    GestionTabWidget(TransTabWidget* tabwid, Transmain* parent);
    void initSect();
    QList<Secteur*>* getSect();
    Secteur* getCote();
    void setCote(Secteur *s);
    Secteur* getSectbyName(QString sectName);
    void setSecteurTabs(Secteur *s);
    void setParent(Transmain *parent);
    QList<ChambrePanel*>* getPanelFromSecteur(Secteur *sect);
    QList<QList<ChambrePanel*>*>* getPanels();
    void updateTimeInBeds();

    //MARGES & POLICES
    QList<int>* getMargins(bool* b);
    QString getFont();

    //void savePanels();


    //getCurrentCote();
    Secteur* cote;
    QList<Secteur*>* sect;
    void setFont(QString ft);
    void setMargins(int l, int t, int r, int b);
    int getFontSize();
    void setFontSize(int sz);

    TransTabWidget *getTabWidget();
private:
    TransTabWidget* tabWidget;
    QList<QList<ChambrePanel*>*> ChambrePanelSecteurList;
    Transmain* parent;

    //MARGES & POLICE
    int left, top, right, bottom, fontSize;
    QString font;
    QDate datelastUpdateBed;
    bool readOpts();

public slots:
    void cycleCote();
    void changeCote();
    void changeCoteInt(int i);
};

#endif // GESTIONTABWIDGET_H
