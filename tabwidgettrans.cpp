#include "tabwidgettrans.h"
#include "ui_tabwidgettrans.h"

TabWidgetTrans::TabWidgetTrans(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::TabWidgetTrans)
{
    ui->setupUi(this);
}

TabWidgetTrans::~TabWidgetTrans()
{
    delete ui;
}
