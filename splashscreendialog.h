#ifndef SPLASHSCREENDIALOG_H
#define SPLASHSCREENDIALOG_H

#include <QDialog>
#include "transmain.h"
#include <QModelIndex>


namespace Ui {
class SplashScreenDialog;
}

class SplashScreenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SplashScreenDialog(QWidget *parent = 0);
    ~SplashScreenDialog();
    void start();
public slots:
    void setSelector(Transmain *mainClass);

protected slots:
    void paintEvent(QPaintEvent *evt);
private:
    Ui::SplashScreenDialog *ui;
    Transmain* mainWindow;
    QStringList* secteurslist;
    float opacity;
    int duration;
    int duration1;
    int duration2;
    int duration3;
    int time;
    int interval;
    bool isRunning;
    bool petal1aff;
    bool petale2aff;
    bool petale3aff;

private slots:
    void setSecteur(QModelIndex);
};

#endif // SPLASHSCREENDIALOG_H
