#ifndef CHOIXSECTEURDIALOG_H
#define CHOIXSECTEURDIALOG_H

#include "transmain.h"

#include <QDialog>
#include <QModelIndex>

namespace Ui {
class ChoixSecteurDialog;
}

class ChoixSecteurDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChoixSecteurDialog(QWidget *parent = 0);
    ~ChoixSecteurDialog();

private:
    Ui::ChoixSecteurDialog *ui;
    Transmain* mainWindow;

private slots:
    void setSecteur(QModelIndex);
};

#endif // CHOIXSECTEURDIALOG_H
