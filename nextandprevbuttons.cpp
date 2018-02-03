#include "nextandprevbuttons.h"

NextAndPrevButtons::NextAndPrevButtons(QWidget *parent) :
    QPushButton(parent)
{
}

void NextAndPrevButtons::switchEnable()
{
        this->setEnabled(!this->isEnabled());
    }
