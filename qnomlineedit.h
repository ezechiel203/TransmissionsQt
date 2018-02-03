#ifndef QNOMLINEEDIT_H
#define QNOMLINEEDIT_H
#ifndef TRANSTABWIDGET_H
#include <transtabwidget.h>
#endif
#include <QLineEdit>
#include <chambrepanel.h>

class QNomLineEdit : public QLineEdit
{
    Q_OBJECT

    ChambrePanel* parentChambre;
public:
    explicit QNomLineEdit(QWidget *parent);

    void setChambre(ChambrePanel *ch);
signals:

protected:
    bool eventFilter(QObject *obj, QEvent *event);
public slots:
    void textToUpper();
};

#endif // QNOMLINEEDIT_H
