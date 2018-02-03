#ifndef QTHREADUPDATE_H
#define QTHREADUPDATE_H

#include <QThread>
#include <splashscreendialog.h>

class SplashScreenDialog;

class QThreadUpdate : public QThread
{
    Q_OBJECT
public:
    explicit QThreadUpdate(SplashScreenDialog *dlg, QObject *parent = 0);
    bool keepOn;
    SplashScreenDialog* splash;

signals:

protected:
    void run();


};

#endif // QTHREADUPDATE_H
