#include "exitformdialog.h"
#include "ui_exitformdialog.h"

ExitFormDialog::ExitFormDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExitFormDialog)
{
    ui->setupUi(this);

    connect(ui->save, SIGNAL(clicked()),this,SLOT(saveClicked()));
    connect(ui->nosave, SIGNAL(clicked()),this,SLOT(nosaveClicked()));
    connect(ui->cancel, SIGNAL(clicked()),this,SLOT(cancelClicked()));

    this->setWindowTitle("Attention");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint & ~Qt::WindowCloseButtonHint);
    this->closeafter = false;
}

ExitFormDialog::~ExitFormDialog()
{
    delete ui;

}

void ExitFormDialog::saveClicked()
{
    this->closeafter = true;
    emit this->acceptedclick();
    this->close();
}


void ExitFormDialog::nosaveClicked()
{
    this->closeafter = true;
    emit this->notaccepted();
    this->close();
}

void ExitFormDialog::cancelClicked()
{
    this->closeafter = false;
    emit this->cancelled();
    this->close();
}

bool ExitFormDialog::getCloseAfter(){
    return this->closeafter;
}
