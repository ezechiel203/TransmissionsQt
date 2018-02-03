#include "qmisctextedit.h"

#include <QKeyEvent>
#include <QPainter>
#include <QApplication>
#include <QClipboard>
#include <QToolTip>
#include <QTimer>
#include <cmath>
#include <QDebug>
#define DEBUG qDebug()
QMiscTextEdit::QMiscTextEdit(QWidget *parent) :
    QTextEdit(parent)
{
    this->installEventFilter(this);
    this->setTabChangesFocus(true);
}

bool QMiscTextEdit::eventFilter(QObject *obj, QEvent *event)
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

            //Pas plusieurs retours chariots à la suite
            if(keyEvt->key() == Qt::Key_Return || keyEvt->key() == Qt::Key_Enter)
            {
                QChar lastChar = '\n';
                if(this->textCursor().position() > 0)
                    lastChar = this->toPlainText().at(this->textCursor().position()-1);

                if(lastChar == '\n')
                    return true;
            }

            if(keyEvt->key() == Qt::Key_V && keyEvt->modifiers() == Qt::ControlModifier)
            {
                QClipboard* clip = QApplication::clipboard();
                if(lengthChecker->lengthValidator(this->toPlainText()+clip->text(),this->size).at(2) >=1)
                {
                    QToolTip::showText( this->mapToGlobal( QPoint( 0, 0 ) ), "<span style='color:#FE2E2E'>Collage trop long</span>" );
                    QTimer::singleShot(2000, this, SLOT(hideTooltip()));
                    return true;
                }
                else
                    return false;
            }

            if(this->length>=1 && ((keyEvt->key() >= 0x20 && keyEvt->key() <= 0x0ff) || keyEvt->key() == Qt::Key_Enter || keyEvt->key() == Qt::Key_Return))
            {
                QToolTip::showText( this->mapToGlobal( QPoint( 0, 0 ) ), "<span style='color:#FE2E2E'>Plus de place...</span>" );
                QTimer::singleShot(2000, this, SLOT(hideTooltip()));
                return true;
            }
        }


        if(event->type() == QEvent::FocusIn)
        {
            this->hasFocus = true;
            this->viewport()->update();
        }

        if(event->type() == QEvent::FocusOut)
        {
            this->hasFocus = false;
            this->viewport()->update();
            emit focusOut();
        }


        //Gestion de la longueur du texte
    }

    return false;

}

void QMiscTextEdit::paintEvent(QPaintEvent* event)
{

    if (length > 0){
        length = (length>1)?1:length;
        QPainter paint(this->viewport());
        paint.setRenderHint(QPainter::Antialiasing);
        //QRectF rect(QPointF(this->size().width()-30,this->size().height()-30), QPointF(this->size().width(),this->size().height()));
        int percent = length*100;
        //float percentpoint = (1-length)/(1-limit);
        /*QPen pen(QColor(255,((1-length)*1/(1-limit))*128,0));
            paint.setPen(pen);
            QBrush brush(QColor(255,((1-length)*1/(1-limit))*128,0), Qt::SolidPattern);
            paint.setBrush(brush);
            */
        //bottom right
        //QPointF points[] = {QPointF(this->width()-15, this->height()), QPointF(this->width(),this->height()-15), QPointF(this->width(),this->height())};
        //TopLeft
        //QPointF points[] = {QPointF(20, 0), QPointF(0,20), QPointF(0,0)};
        float deltaw = this->width()/100.;
        for(int i=0;i<=percent;i++){
            float perC = i/100.;
            float deltacolor = 356;
            float currentDeltaColor = perC*deltacolor;
            int r = currentDeltaColor<178?currentDeltaColor+66:244;
            int g = r < 244?244:66+deltacolor-currentDeltaColor ;
            QBrush brush(QColor(r,g,66), Qt::SolidPattern);
            QPen pen(QColor(r,g,66));
            paint.setBrush(brush);
            paint.setPen(pen);
            paint.drawRect(QRectF(QPointF(deltaw*i,0), QPointF(deltaw*i+deltaw,4)));
        }
    }
    QTextEdit::paintEvent(event);
}

void QMiscTextEdit::setLengthChecker(TransDocument *lc)
{
    this->lengthChecker = lc;
}

void QMiscTextEdit::setSize(TransDocument::rectSize sz)
{
    this->size = sz;
}

void QMiscTextEdit::checkLength()
{
    QList<float> lengthList = lengthChecker->lengthValidator(this->toPlainText(),this->size);
    length = lengthList.at(2);
}

void QMiscTextEdit::hideTooltip()
{
    QToolTip::hideText();
}

void QMiscTextEdit::keyPressEvent(QKeyEvent *evt)
{
    QTextEdit::keyPressEvent(evt);
    QList<float> lengthList = lengthChecker->lengthValidator(this->toPlainText(),this->size);
    length = lengthList.at(2);

    if(length >= 1)
    {
        this->textCursor().deletePreviousChar();
        //parentChambre->getTransmain()->togg;
    }
}

void QMiscTextEdit::setChambre(ChambrePanel * ch)
{
    this->parentChambre=ch;
}
