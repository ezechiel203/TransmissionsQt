#ifndef NEXTANDPREVBUTTONS_H
#define NEXTANDPREVBUTTONS_H

#include <QPushButton>

class NextAndPrevButtons : public QPushButton
{
    Q_OBJECT
public:
    explicit NextAndPrevButtons(QWidget *parent = 0);

signals:

public slots:
    void switchEnable();

};

#endif // NEXTANDPREVBUTTONS_H
