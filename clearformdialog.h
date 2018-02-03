#ifndef CLEARFORMDIALOG_H
#define CLEARFORMDIALOG_H

#include <QDialog>

namespace Ui {
class ClearFormDialog;
}

class ClearFormDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClearFormDialog(QWidget *parent = 0);
    ~ClearFormDialog();
    bool getHideCheck();

public slots:
    void accept();

signals:
    void accepted(bool);

private:
    Ui::ClearFormDialog *ui;
};

#endif // CLEARFORMDIALOG_H
