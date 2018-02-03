#ifndef QMAINALLERGIESTEXTEDIT_H
#define QMAINALLERGIESTEXTEDIT_H

#include "qmisctextedit.h"
#include <QTextEdit>
#include <transdocument.h>
#include <qmainatcdtextedit.h>
#include <QCheckBox>

class QMainAtcdTextEdit;

class QMainAllergiesTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit QMainAllergiesTextEdit(QWidget *parent=0);

    void setLengthChecker(TransDocument* lc);
    void setSize(TransDocument::rectSize sz);
    void setPartner(QMainAtcdTextEdit* atcd);
    void setLength(float l);
    bool focus();
    void setChambre(ChambrePanel *ch);
    void setAllergiesCheck(QCheckBox *allergiesChk);
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

private:
    bool hasFocus = false;
    float length = 0.;
    TransDocument* lengthChecker = 0;
    TransDocument::rectSize size;
    ChambrePanel* parentChambre;
    QMainAtcdTextEdit* antecedents;
    QString TexteMisEnForme();
    ChambrePanel* chambre;
    QCheckBox* allergiesCheck;
};


#endif // QMAINALLERGIESTEXTEDIT_H
