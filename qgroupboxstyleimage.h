#ifndef QGROUPBOXSTYLEIMAGE_H
#define QGROUPBOXSTYLEIMAGE_H

#include <QProxyStyle>

class QGroupBoxStyleImage : public QProxyStyle
{
public:
    QGroupBoxStyleImage(QStyle* base);
    void drawComplexControl(ComplexControl control,
                                const QStyleOptionComplex *option,
                            QPainter *painter, const QWidget *widget) const;
    QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *widget) const;
    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget = 0) const;

private:
    bool hasBeenSet;
    void setHasBeenSet(bool b);
};

#endif // QGROUPBOXSTYLEIMAGE_H
