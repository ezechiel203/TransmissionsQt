#ifndef SECTEUR_H
#define SECTEUR_H
#include <QColor>
#include <QString>
#include <QStringList>

class Secteur
{
public:
    Secteur();
    Secteur(QString nom);
    Secteur(QString nom, QStringList chambres, QColor bgcol, QColor fcol, int i);

    void setNom(QString nom);
    void setBackGroundColor(QColor backgroundColor);
    void setFontColor(QColor fontColor);
    void setChambres(QStringList chambres);
    void setIndex(int i);
    void setLastEditEpoch(QString time);
    QString getNom() const;
    QColor getBackgrounddColor() const;
    QColor getFontColor() const;
    QStringList getChambres() const;
    int getIndex() const;
    QString getLastEditEpoch();
    bool operator == (Secteur s);


private:
    int index;
    QString lastEditEpoch;
    QString nom;
    QStringList chambres;
    QColor backgroundColor;
    QColor fontColor;
};

#endif // SECTEUR_H
