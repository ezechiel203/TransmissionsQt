#ifndef QMAINATCDTEXTEDIT_H
#define QMAINATCDTEXTEDIT_H

#include "qmisctextedit.h"
#include <QTextEdit>
#include <transdocument.h>
#include <qmainallergiestextedit.h>
#include <QCheckBox>

class QMainAllergiesTextEdit;

class QMainAtcdTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit QMainAtcdTextEdit(QWidget *parent=0);

    void setLengthChecker(TransDocument* lc);
    void setSize(TransDocument::rectSize sz);
    void setPartner(QMainAllergiesTextEdit* allergies);
    void setAllergiesCheck(QCheckBox* allergiesChk);
    void setLength(float l);
    bool focus();
    void setChambre(ChambrePanel *ch);
signals:
    void focusOut();

public slots:
    void checkLength();
    void check_uncheck();

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
    QMainAllergiesTextEdit* allerg;
    QCheckBox* allergiesCheck;
    QString TexteMisEnForme();

};


#endif // QMAINATCDTEXTEDIT_H
