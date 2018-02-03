#include "splashscreen.h"
#include "QLabel"

#include <QVBoxLayout>

SplashScreen::SplashScreen(QWidget *parent) :
    QDialog(parent)
{
    pix = new QPixmap(":/logo");
    this->setStyleSheet("background-image:url(:/logo);");
    this->resize(pix->width(),pix->height());
   // this->setWindowFlags(Qt::FramelessWindowHint);
    //this->setMask(logo.mask());
}
