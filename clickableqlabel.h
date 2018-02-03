#ifndef CLICKABLEQLABEL_H
#define CLICKABLEQLABEL_H

#include <QMouseEvent>
#include <QLabel>

class ClickableQLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickableQLabel(QWidget *parent = 0);

signals:
    void clicked();

public slots:

private slots:
    void labelClicked();

protected:
    void mousePressEvent ( QMouseEvent * event ) ;
};

#endif // CLICKABLEQLABEL_H
