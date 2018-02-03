#ifndef TRANSPRINTPREVIEW_H
#define TRANSPRINTPREVIEW_H


#include <QDialog>
#include <QtPrintSupport/qprintpreviewwidget.h>
#include <transdocument.h>
#include <transsecteurchooserfactory.h>

class TransSecteurChooserFactory;

class TransPrintPreview : public QDialog
{
    Q_OBJECT

public:
    explicit TransPrintPreview(TransDocument* doc, QWidget *parent = 0);
    ~TransPrintPreview();
    QPrintPreviewWidget* preview;
    Transmain* getTransmain();

public slots:
    void updateSecteurs();

private slots:
    void showOptions();
    void fullScreenZoom();
    void zoomIn();
    void zoomOut();    
    void showPrintOpts();
    void emitRepaint(QPrinter *printer);

signals:
    void repaint(QPrinter*, QList<Secteur *>*);

private:
    TransDocument* document;
    Transmain* mainWindow;

    TransSecteurChooserFactory* fact;

};

#endif // TRANSPRINTPREVIEW_H
