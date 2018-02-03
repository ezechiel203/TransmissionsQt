#ifndef QMAINTEXTEDIT_H
#define QMAINTEXTEDIT_H

#include "qmisctextedit.h"
#include <QTextEdit>
#include <transdocument.h>

class QMainTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit QMainTextEdit(QWidget *parent = 0);

    void setLengthChecker(TransDocument* lc);
    void setSize(TransDocument::rectSize sz);
    void setChambre(ChambrePanel *ch);
signals:
    void focusOut();

public slots:
    void checkLength();

protected slots:
    void hideTooltip();

protected:
    bool eventFilter(QObject *obj, QEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *evt);
 //   void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

private:
    bool hasFocus = false;
    float length = 0.;
    TransDocument* lengthChecker = 0;
    TransDocument::rectSize size;
    ChambrePanel* parentChambre;

};

#endif // QMAINTEXTEDIT_H
