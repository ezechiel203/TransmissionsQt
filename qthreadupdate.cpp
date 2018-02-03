#include "qthreadupdate.h"
#include <QApplication>
#include <QDebug>

QThreadUpdate::QThreadUpdate(SplashScreenDialog *dlg, QObject *parent) :
    QThread(parent)
{
    splash = dlg;
    keepOn = true;
}

void QThreadUpdate::run(){
    int i = 0;
    while(keepOn == true)
    {
        qDebug() << "boucle " << i << endl;
        splash->repaint();
        QApplication::processEvents();
        QThread::msleep(33);
        i++;
    }
}
