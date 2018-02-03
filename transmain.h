#ifndef TRANSMAIN_H
#define TRANSMAIN_H
#include "secteur.h"
#include <QMainWindow>
#include <QCloseEvent>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Transmain;
}

class GestionTabWidget;

class Transmain : public QMainWindow
{
    Q_OBJECT

public:
    explicit Transmain(QWidget *parent = 0);
    ~Transmain();
    void setClearFormShow(bool check);
    bool getClearFormShow();
    void setSave(bool checked);
    bool getSave();
    GestionTabWidget* getGestionnaire();
    QStatusBar* sb;
    QPushButton* helpButton;

    static QString getVersion();
    static QString getYearcpy();
    static QString getAuthorFull();
    static QString getAuthorMin();
    static QString getAppName();
    static QString getAuthorMail();
    void init();

public slots:
    void toggleSaveTrue();
    void toggleSaveFalse();
    void saveAction();
    void showAbout();
    void saveUnderAction();
    void openAction();
    void printFast(QList<Secteur *>* = 0);
    void printOpts(QList<Secteur *>* sects = 0);
    void showOptions();

    void chCote();
signals:
    void saveToggled(bool sv);
    void initialized(Transmain*);

private:
    Ui::Transmain *ui;
    bool clearFormShow;
    bool save;
    GestionTabWidget* gestionnaire;

protected:
    void closeEvent(QCloseEvent* event);

private slots:
    void switchRoomsClicked();
    void printPreview();
};

#endif // TRANSMAIN_H
