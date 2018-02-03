#include "qgroupboxstyleimage.h"
#include <QWidget>
#include <QPainter>
#include <QVariant>
#include <QDebug>


QGroupBoxStyleImage::QGroupBoxStyleImage(QStyle *base) : QProxyStyle(base)
{
    hasBeenSet = false;
}

QRect QGroupBoxStyleImage::subControlRect(ComplexControl cc, const QStyleOptionComplex *opt,
                     SubControl sc, const QWidget *widget) const
{
    QRect rect = QProxyStyle::subControlRect(cc, opt, sc, widget);
    // Si la taille demandée concerne le label d'un QGroupBox
    // et si le widget a une propriété dynamique "titleImage"
    if (cc == CC_GroupBox && sc == SC_GroupBoxLabel && !hasBeenSet) {
        // on fait de la place pour l'image (ex: pour un icône 16x16)
        // en décalant l'emplacement où sera affiché le texte
        rect.translate(5,0);
        rect.setWidth(rect.width()+5);
        //setHasBeenSet(true);
    }
    return rect;
}

void QGroupBoxStyleImage::drawComplexControl(QStyle::ComplexControl control, const QStyleOptionComplex *option, QPainter *painter, const QWidget *widget) const
{
    QProxyStyle::drawComplexControl(control, option, painter, widget);
    // On dessine normalement le widget...
    if (control == CC_GroupBox) {
        QRect rect = QGroupBoxStyleImage::subControlRect(control,
                                                 option,
                                                 SC_GroupBoxLabel,
                                                 widget);
        painter->drawPixmap(rect.topRight(), QPixmap(":/arrow"));
    }

}

void QGroupBoxStyleImage::drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    QProxyStyle::drawControl(element, option, painter, widget);
    // On dessine normalement le widget...

    if (element == CE_CheckBox) {
        QRect rect = QProxyStyle::subElementRect(SE_CheckBoxContents,
                                                 option,
                                                 widget);
        rect.setWidth(rect.width()-12);
        rect.setY(2);
        painter->drawPixmap(rect.topRight(), QPixmap(":/arrow"));
    }

}

void QGroupBoxStyleImage::setHasBeenSet(bool b)
 {
    hasBeenSet = b;
}
