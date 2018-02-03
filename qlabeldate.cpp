#include "qlabeldate.h"
#include <QDebug>

QLabelDate::QLabelDate(QWidget *parent) :
    QLabel(parent)
{
    this->date = new QDate();
    this->setAlignment(Qt::AlignCenter);
    emit dateChanged();
}

void QLabelDate::setDate(QDate date)
{
    this->date = new QDate(date);
    this->setText(this->date->toString("dddd d MMMM yyyy"));
    emit dateChanged();
}

void QLabelDate::setDate(QString str){
    if(!(str=="")){
        this->date = new QDate(QDate::fromString(str,"dd/MM/yyyy"));
        this->setText(date->toString("dddd d MMMM yyyy"));

    }
    else
    {
        this->setText("");
        this->date= new QDate();
    }
    emit dateChanged();

}

QString QLabelDate::getDate(){
    if(date->isValid())
        return date->toString("dd/MM/yy");
    else
        return "";

}

QDate QLabelDate::getnumDate(){
    return *date;
}
