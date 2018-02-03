#include "clickableqlabel.h"

ClickableQLabel::ClickableQLabel(QWidget *parent) :
    QLabel(parent)
{
}

void ClickableQLabel::labelClicked()
{
    emit this->clicked();
}

void ClickableQLabel::mousePressEvent(QMouseEvent*)
{
   this->labelClicked();
}
