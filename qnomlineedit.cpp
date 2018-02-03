#include "qnomlineedit.h"
#include <QDebug>

QNomLineEdit::QNomLineEdit(QWidget *parent=0) :
    QLineEdit(parent)
{
    connect(this, SIGNAL(textChanged(QString)), this, SLOT(textToUpper()));
    this->installEventFilter(this);
}

void QNomLineEdit::textToUpper()
{
    this->setText(this->text().toUpper());
}

bool QNomLineEdit::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == this){
        if(event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvt = static_cast<QKeyEvent *>(event);

            if(keyEvt->key() == Qt::Key_Right && keyEvt->modifiers() == Qt::ControlModifier){
                this->parentChambre->setNextTab();
                return true;
            }

            if(keyEvt->key() == Qt::Key_Left && keyEvt->modifiers() == Qt::ControlModifier){
                this->parentChambre->setPrevTab();
                return true;
            }

            if(keyEvt->key() == Qt::Key_Home && keyEvt->modifiers() == Qt::ControlModifier){
                this->parentChambre->getTabWidget()->setFirst();
                return true;
            }

            if(keyEvt->key() == Qt::Key_End && keyEvt->modifiers() == Qt::ControlModifier){
                this->parentChambre->getTabWidget()->setLast();
                return true;
            }

        }
    }
    return false;
}

void QNomLineEdit::setChambre(ChambrePanel * ch)
{
    this->parentChambre=ch;
}
