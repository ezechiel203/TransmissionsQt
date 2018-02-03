#ifndef QLABELDATE_H
#define QLABELDATE_H

#include <QLabel>
#include <QDate>
#include <chambrepanel.h>

class QLabelDate : public QLabel
{
    Q_OBJECT
public:
    explicit QLabelDate(QWidget *parent);
    QString getDate();
    QDate getnumDate();
    void setDate(QString str);

signals:
    void dateChanged();

public slots:
    void setDate(QDate date);


private:
    QDate* date;
    ChambrePanel* chambre;

};

#endif // QLABELDATE_H
