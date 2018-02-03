#ifndef QMISCTEXTEDIT_H
#define QMISCTEXTEDIT_H

#include <QTextEdit>
#include <transdocument.h>

class QMiscTextEdit : public QTextEdit
{
    Q_OBJECT

public:
    explicit QMiscTextEdit(QWidget *parent = 0);
    void setLengthChecker(TransDocument* lc);
    void setSize(TransDocument::rectSize sz);

    void setChambre(ChambrePanel *ch);
signals:
    void focusOut();

public slots:
    void checkLength();

private slots:
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
};

#endif // QMISCTEXTEDIT_H
