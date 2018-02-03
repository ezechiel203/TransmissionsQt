#include "aboutformdialog.h"
#include "ui_aboutformdialog.h"
#include "transmain.h"
AboutFormDialog::AboutFormDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutFormDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("À propos");
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setModal(false);
    ui->label_2->setText("<b>"+Transmain::getAppName()+" "+Transmain::getVersion()+"</b><br/>Copyright 2013-"+Transmain::getYearcpy()+"<br/>"+Transmain::getAuthorFull()+", tous droits réservés<br/>Contact : <a href='mailto:"+Transmain::getAuthorMail()+"?subject=[contact]Transmissions IDE Qt'>"+Transmain::getAuthorMail()+"</a>");
    ui->label_2->setOpenExternalLinks(true);
    this->setStyleSheet("AboutFormDialog {background-color : #FDFDFD;}");
}

AboutFormDialog::~AboutFormDialog()
{
    delete ui;
}

void AboutFormDialog::closeEvent(QCloseEvent * evt){
    delete this;
    evt->accept();
}
