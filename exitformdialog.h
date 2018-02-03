#ifndef EXITFORMDIALOG_H
#define EXITFORMDIALOG_H

#include <QDialog>

namespace Ui {
class ExitFormDialog;
}

class ExitFormDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExitFormDialog(QWidget *parent = 0);
    ~ExitFormDialog();
    bool getCloseAfter();

signals:
    void acceptedclick();
    void notaccepted();
    void cancelled();

public slots:
    void saveClicked();
    void nosaveClicked();
    void cancelClicked();

private:
    Ui::ExitFormDialog *ui;
    bool closeafter;
};

#endif // EXITFORMDIALOG_H
