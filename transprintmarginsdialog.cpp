#include "transprintmarginsdialog.h"
#include "ui_transprintmarginsdialog.h"
#include <QDebug>
#include <qgroupboxstyleimage.h>

TransPrintMarginsDialog::TransPrintMarginsDialog(TransDocument* document, QWidget *parent, GestionTabWidget* gestionnaire) :
    QDialog(parent),
    ui(new Ui::TransPrintMarginsDialog)
{
    this->doc = document;
    this->gestionnaire = gestionnaire;
    konami_int = 0;

    QList<int>* margins = doc->getMargins();
    left = margins->at(0);
    top = margins->at(1);
    right = margins->at(2);
    bottom = margins->at(3);

    font = doc->getFont();
    ui->setupUi(this);
    ui->groupBox_2->setEnabled(false);
    connect(ui->konami_label, SIGNAL(clicked()), this, SLOT(konami()));
    fontSize = doc->getFontSize();

    this->setWindowTitle("Options");
    this->setWindowFlags(this->windowFlags()&~(Qt::WindowContextHelpButtonHint));
    this->setWindowIcon(QIcon(":/options"));
    ui->spinL->setValue(left);
    ui->spinT->setValue(top);
    ui->spinR->setValue(right);
    ui->spinB->setValue(bottom);
    ui->Fonts->setCurrentFont((QFont(font)));
    ui->fontSizeBox->setValue(fontSize);

    connect(ui->boutOK, SIGNAL(clicked()), this, SLOT(valider()));
    connect(ui->boutAN, SIGNAL(clicked()), this, SLOT(close()));
    ui->groupBox->setStyle(new QGroupBoxStyleImage(ui->groupBox->style()));
    ui->groupBox_2->setStyle(new QGroupBoxStyleImage(ui->groupBox_2->style()));
}

TransPrintMarginsDialog::~TransPrintMarginsDialog()
{
    delete ui;
}

void TransPrintMarginsDialog::valider()
{
    doc->setMargins(ui->spinL->value(),ui->spinT->value(),ui->spinR->value(),ui->spinB->value());
    doc->setFont(ui->Fonts->currentText());
    doc->setFontSize(ui->fontSizeBox->value());
    if(gestionnaire != 0)
    {
        gestionnaire->setMargins(ui->spinL->value(),ui->spinT->value(),ui->spinR->value(),ui->spinB->value());
        gestionnaire->setFont(ui->Fonts->currentText());
        gestionnaire->setFontSize(ui->fontSizeBox->value());
    }
    writeToFile();
    emit finish_update();
    this->close();
}

void TransPrintMarginsDialog::writeToFile()
{
    //Options
    QFile f("config.trs");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    QTextStream str(&f);
    str << "[Options Transmissions Qt]" << endl;
    str << "[Margins]" << endl;
    str << "LEFT = " << ui->spinL->value() << endl;
    str << "TOP = " << ui->spinT->value() << endl;
    str << "RIGHT = " << ui->spinR->value() << endl;
    str << "BOTTOM = " << ui->spinB->value() << endl;
    str << endl;
    str << "[Polices]" << endl;
    str << "Font = " << ui->Fonts->currentText() << endl;
    str << "SIZE = " << ui->fontSizeBox->value() << endl;

    f.close();
}

void TransPrintMarginsDialog::konami()
{
    if(konami_int == 0)
        ui->groupBox_2->setEnabled(false);
    if(konami_int ==5 )
    {
        ui->groupBox_2->setEnabled(true);
        konami_int = -1;
    }
    if(konami_int < 5)
        konami_int++;
}
