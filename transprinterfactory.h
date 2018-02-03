#ifndef TRANSPRINTERFACTORY_H
#define TRANSPRINTERFACTORY_H

#include <QWidget>
#include <transmain.h>
#include <gestiontabwidget.h>

namespace Ui {
class TransPrinterFactory;
}

/*class Transmain;
class gestionTabWidget;
*/
class TransPrinterFactory : public QWidget
{
    Q_OBJECT

public:
    explicit TransPrinterFactory(QWidget *parent);
    ~TransPrinterFactory();

public slots:
    void updateCombo();

private slots:
    void printFast();
    void printOpts();

private:
    Ui::TransPrinterFactory *ui;
    void setupComboBox();
    Transmain* mainWindow;
    GestionTabWidget* gestionnaire;
    QList<QList<Secteur *>*> comboListe;
};

#endif // TRANSPRINTERFACTORY_H
