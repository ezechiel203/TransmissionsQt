#ifndef TRANSPRINTMARGINSDIALOG_H
#define TRANSPRINTMARGINSDIALOG_H

#include <QDialog>
#include <transdocument.h>

namespace Ui {
class TransPrintMarginsDialog;
}

class TransPrintMarginsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransPrintMarginsDialog(TransDocument* document, QWidget *parent = 0, GestionTabWidget* gestionnaire =0);
    ~TransPrintMarginsDialog();

private:
    TransDocument* doc;
    GestionTabWidget* gestionnaire;
    Ui::TransPrintMarginsDialog *ui;
    int left, top, right, bottom, fontSize;
    QString font;
    int konami_int;

private slots:
    void valider();
    void konami();

signals:
    void finish_update();

protected:
    void writeToFile();
};

#endif // TRANSPRINTMARGINSDIALOG_H
