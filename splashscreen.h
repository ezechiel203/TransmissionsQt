#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>

class SplashScreen : public QDialog
{
    Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent = 0);

private:
    QPixmap* pix;
};

#endif // SPLASHSCREEN_H
