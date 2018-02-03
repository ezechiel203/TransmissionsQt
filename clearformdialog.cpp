#include "clearformdialog.h"
#include "ui_clearformdialog.h"


ClearFormDialog::ClearFormDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClearFormDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Attention");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(accept()));
}

ClearFormDialog::~ClearFormDialog()
{
    delete ui;
}

void ClearFormDialog::accept()
{
    emit accepted(ui->noAsk->isChecked());
    this->hide();
}

bool ClearFormDialog::getHideCheck()
{
    return this->ui->noAsk->isChecked();
}
