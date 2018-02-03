#ifndef ABOUTFORMDIALOG_H
#define ABOUTFORMDIALOG_H

#include <QDialog>

namespace Ui {
class AboutFormDialog;
}

class AboutFormDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutFormDialog(QWidget *parent = 0);
    ~AboutFormDialog();

private:
    Ui::AboutFormDialog *ui;
    void closeEvent(QCloseEvent *evt);
};

#endif // ABOUTFORMDIALOG_H
