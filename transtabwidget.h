#ifndef TRANSTABWIDGET_H
#define TRANSTABWIDGET_H
#include "transmain.h"
#include <QTabWidget>
#include <QPushButton>
#include <QString>

class TransTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TransTabWidget(QWidget *parent = 0);
    void setCurrentIndexWithUpdate(int index);
    void buttonEventDispatcher();
signals:
    void lastIndexReached(bool);
    void firstIndexReached(bool);
    void currentIndexChanged(int);

public slots:
    void setNextIndex();
    void setPreviousIndex();
    void addNewTab(QString);
    void updateOnClick(int);
    void setFirst();
    void setLast();

private slots:

private:
    Transmain* parent;

};

#endif // TRANSTABWIDGET_H
