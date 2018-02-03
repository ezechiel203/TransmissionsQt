#include "secteur.h"
#include <QDebug>
#include <QDateTime>

Secteur::Secteur()
{
    this->nom= static_cast<QString> ("Default");
    this->backgroundColor = QColor(240,240,240);
    this->fontColor = QColor(0,0,0);
    this->lastEditEpoch = QString::number(QDateTime::currentMSecsSinceEpoch());
}

Secteur::Secteur(QString nom){
    this->nom = nom;
    this->backgroundColor = QColor(240,240,240);
    this->fontColor = QColor(0,0,0);
    this->lastEditEpoch = QString::number(QDateTime::currentMSecsSinceEpoch());
}

Secteur::Secteur(QString nom, QStringList chambres, QColor bgcol, QColor fcol, int i){
    this->index = i;
    this->nom = nom;
    this->chambres = chambres;
    this->backgroundColor = bgcol;
    this->fontColor = fcol;
    this->lastEditEpoch = QString::number(QDateTime::currentMSecsSinceEpoch());
}

void Secteur::setNom(QString nom){
    this->nom = nom;
}

void Secteur::setBackGroundColor(QColor backgroundColor){
    this->backgroundColor = backgroundColor;
}

void Secteur::setFontColor(QColor fontColor){
    this->fontColor = fontColor;
}

void Secteur::setChambres(QStringList chambres){
    this->chambres = chambres;
}

void Secteur:: setIndex(int index){
    this->index = index;
}

void Secteur::setLastEditEpoch(QString time)
{
    this->lastEditEpoch = time;
}

QString Secteur::getNom() const{
    return this->nom;
}

QColor Secteur::getBackgrounddColor() const{
    return this->backgroundColor;
}

QColor Secteur::getFontColor() const{
    return this->fontColor;
}

QStringList Secteur::getChambres() const{
    return this->chambres;
}

int Secteur::getIndex() const{
    return this->index;
}

QString Secteur::getLastEditEpoch()
{
    return this->lastEditEpoch;
}

bool Secteur::operator == (Secteur s){
    return (this->getNom() == s.getNom());
}


