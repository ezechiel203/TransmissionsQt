#ifndef TRANSSECTEURCHOOSERFACTORY_H
#define TRANSSECTEURCHOOSERFACTORY_H


#include <QWidget>
#include <transmain.h>
#include <transprintpreview.h>

namespace Ui {
class TransSecteurChooserFactory;
}

class TransPrintPreview;

class TransSecteurChooserFactory : public QWidget
{
    Q_OBJECT

public:
    explicit TransSecteurChooserFactory(QWidget *parent = 0);
    ~TransSecteurChooserFactory();
    QList<Secteur *> *getSecteursToPrint();

public slots:
    void updateCombo();

private:
    Ui::TransSecteurChooserFactory *ui;
    void setupComboBox();
    TransPrintPreview* parentWindow;
    Transmain* mainWindow;
    GestionTabWidget* gestionnaire;
    QList<QList<Secteur *>*> comboListe;
};

#endif // TRANSSECTEURCHOOSERFACTORY_H
