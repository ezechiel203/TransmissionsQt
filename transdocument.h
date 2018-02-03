#ifndef TRANSDOCUMENT_H
#define TRANSDOCUMENT_H

#include "gestiontabwidget.h"
#include <QObject>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QList>
#include <QPainter>
#include <qprintpreviewdialog.h>

class TransDocument : public QObject
{
    Q_OBJECT

private:
    float percentSum(int i);
    void drawIncompleteRect(bool left, bool top, bool right, bool bottom, QRectF rect, QPainter *painter);
    float drawOffset;
    Secteur* secteur;
    QPainter painter;
    QPrinter printer;
    int lineNB;
    GestionTabWidget* baseData;
    float zoom;
    float VWorkingSpace;
    float HWorkingSpace;
    float lineHeight;
    QString font;
    int fontSize;
    QList<Secteur*>* sect;
    void printChambre(ChambrePanel* chambre, QPainter* paint);
    void printSecteur(Secteur *sect);
    void printSecteur(Secteur *sect, QPainter *paint);
    void setSecteur(Secteur* s);
    QList<QList<QRectF> > setTablePadding(int left, int top, int right, int bottom, QList<QList<QRectF> > tableau);
    QRectF setCellPadding(int left, int top, int right, int bottom, QRectF rectr);
    void drawWrappedText(QString t, QRectF r, QFont f, QPainter* p, int minFontSize, bool auth_slashN = false, QRectF *bound=0);
    QList<float> checkLength(QString t, QRectF r, QFont f, bool auth_slashN);
    QSize *scaletot;

public:
    explicit TransDocument(GestionTabWidget* gestionnaire, QObject *parent);
    explicit TransDocument(GestionTabWidget* gestionnaire, ChambrePanel* cp=0);
    ~TransDocument();
    void setMargins(int left, int top, int right, int bottom);
    QList<int> *getMargins();
    QString getFont();
    void setFont(QString ft);
    int getFontSize();
    void setFontSize(int sz);
    GestionTabWidget* getGestionnaire();

    const static  int pageSize;
    const static  int rooms;
    const static  int tableRows;
    const static  QList<float> colWidthPercent;

    //Default margins
    float millimetersMarginLeft;
    float millimetersMarginRight;
    float millimetersMarginTop;
    float millimetersMarginBottom;

    float marginLeft;
    float marginRight;
    float marginTop;
    float marginBottom;
    QTextDocument* pdf;
    float basicCellHeight;
    QFont minFont;
    void printDocument(QList<Secteur*>* secteurs = 0);
    void printDocument(QPrinter *print, QList<Secteur *> *secteurs = 0);
    QPrinter* getPrinter();
    void printPreview(QPrinter *print, QList<Secteur *> *secteurs = 0);

    enum rectSize
    {
      SMALL = 0,
      BIG,
      MISC,
      REASMALL
    };
    QList<float> lengthValidator(QString t, TransDocument::rectSize size);


signals:

public slots:
    void refresh(QPrinter *print, QList<Secteur *> *);

};

#endif // TRANSDOCUMENT_H
