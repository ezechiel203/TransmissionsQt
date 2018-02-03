#include "transdocument.h"

#include <QTextTable>
#include <qtextcursor.h>
#include <QPainter>
#include <QPixmap>
#include <QStaticText>
#include <QDebug>
#include <QDateTime>
#include <QPrintPreviewDialog>
#include <QRegularExpression>

#define MAIN_REA_TXT "Réa"
#define MIN_FONT 70
#define DEFAULT_FONTSIZE 6
#define PADDINGL 5
#define PADDINGT 5
#define PADDINGR 5
#define PADDINGB 5
#define UNMODIFWIDTHLEFT 0
#define UNMODIFWIDTHRIGHT 0
#define LEFTMARGIN 5
#define TOPMARGIN 7
#define RIGHTMARGIN 6
#define BOTTOMMARGIN 5

#define DEBUG qDebug() <<

//Définitide la largeur de chaque cellule en % de la largeur de la page
const QList<float> TransDocument::colWidthPercent = QList<float>() << 0.1072 << 0.094 << 0.3524 <<0.094 << 0.3524;

//Constructeurs
TransDocument::TransDocument(GestionTabWidget* gestionnaire, QObject *parent) :
    QObject(parent)
{
    font = "Times New Roman";
    bool b;
    QList<int>* listeMarges = gestionnaire->getMargins(&b);

    if(!b)
    {
        setMargins(LEFTMARGIN,TOPMARGIN,RIGHTMARGIN,BOTTOMMARGIN);
        setFontSize(DEFAULT_FONTSIZE);
    }
    else
    {
        setMargins(listeMarges->at(0), listeMarges->at(1), listeMarges->at(2), listeMarges->at(3));
        setFontSize(gestionnaire->getFontSize());
    }
    font = gestionnaire->getFont();

    //Initiation de l'objet
    drawOffset = 0;
    lineNB=0;

    //Define default sector
    secteur = gestionnaire->getCote();
    baseData = gestionnaire;
    //Zoom de la page. entre 1 et x. Pour 1 -> 1px = 1mm pour 10 ; 10px = 1mm etc...
    zoom = 10.;
    marginLeft = (UNMODIFWIDTHLEFT+millimetersMarginLeft)*zoom;
    marginRight = (UNMODIFWIDTHRIGHT+millimetersMarginRight)*zoom;
    marginTop = millimetersMarginTop*zoom;
    marginBottom = millimetersMarginBottom*zoom;

    printer.setFullPage(true);
    printer.setResolution(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);
}

TransDocument::TransDocument(GestionTabWidget* gestionnaire, ChambrePanel* cp) :
    QObject(cp)
{
    font = "Times New Roman";
    bool b;
    QList<int>* listeMarges = gestionnaire->getMargins(&b);

    if(!b)
    {
        setMargins(LEFTMARGIN,TOPMARGIN,RIGHTMARGIN,BOTTOMMARGIN);
        setFontSize(DEFAULT_FONTSIZE);
    }
    else
    {
        setMargins(listeMarges->at(0), listeMarges->at(1), listeMarges->at(2), listeMarges->at(3));
        setFontSize(gestionnaire->getFontSize());
    }
    font = gestionnaire->getFont();

    //Initiation de l'objet
    drawOffset = 0;
    lineNB=0;

    //Define default sector
    secteur = gestionnaire->getCote();
    baseData = gestionnaire;

    //Zoom de la page. entre 1 et x. Pour 1 -> 1px = 1mm pour 10 ; 10px = 1mm etc...
    zoom = 10.;
    marginLeft = (UNMODIFWIDTHLEFT+millimetersMarginLeft)*zoom;
    marginRight = (UNMODIFWIDTHRIGHT+millimetersMarginRight)*zoom;
    marginTop = millimetersMarginTop*zoom;
    marginBottom = millimetersMarginBottom*zoom;

    minFont = QFont(font);
    printer.setFullPage(true);
    printer.setResolution(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    printer.setPageMargins(0,0,0,0,QPrinter::Millimeter);

    lineNB = 44;

    //qDebug("setting V and H workingspaces :");
    VWorkingSpace = ((printer.heightMM()*zoom)-(marginTop+marginBottom));
    //Cell height
    lineHeight = VWorkingSpace/lineNB;
    //Horizontal working space (width minux left & right borders)
    HWorkingSpace = ((printer.widthMM()*zoom)-(marginLeft+marginRight));


}

TransDocument::~TransDocument()
{
}

void TransDocument::setMargins(int left, int top, int right, int bottom)
{
    millimetersMarginLeft = left;
    millimetersMarginTop = top;
    millimetersMarginRight = right;
    millimetersMarginBottom = bottom;
}

QList<int>* TransDocument::getMargins()
{
    QList<int>* liste = new QList<int>;
    liste->append(millimetersMarginLeft);
    liste->append(millimetersMarginTop);
    liste->append(millimetersMarginRight);
    liste->append(millimetersMarginBottom);
    return liste;
}

QString TransDocument::getFont()
{
    return font;
}

void TransDocument::setFont(QString ft)
{
    font = ft;
}

int TransDocument::getFontSize()
{
    return fontSize;
}

void TransDocument::setFontSize(int sz)
{
    fontSize = sz;
}

GestionTabWidget *TransDocument::getGestionnaire()
{
    return baseData;
}

//Sums up percentages for cells drawing
float TransDocument::percentSum(int i){
    float perc = 0.;
    for(int j = 0; j<i; j++)
        perc+=colWidthPercent.at(j);
    return perc;
}

QList<float> TransDocument::lengthValidator(QString t, TransDocument::rectSize size)
{
    // générer les rectangles correspondant
    // 0 small
    // 1 big
    // 2 misc
    // 3 ReaSmall

    //qDebug("setting Rectangles :");
    QRectF small(marginLeft+percentSum(1)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(1)*HWorkingSpace,lineHeight);
    QRectF big(marginLeft+percentSum(2)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(2)*HWorkingSpace,lineHeight);
    QRectF misc(marginLeft+percentSum(0)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(0)*HWorkingSpace,lineHeight*3);
    QFontMetricsF fm(QFont(font, 115*zoom, QFont::Bold), &printer);
    QRectF interm = fm.boundingRect(QRectF(QPointF(small.topLeft().x(),small.topLeft().y()),QPointF(small.bottomRight().x(),small.bottomRight().y())).toRect(),Qt::AlignVCenter|Qt::TextWordWrap,MAIN_REA_TXT);
    QRectF reaSmall(QPoint(interm.topRight().x(),small.topRight().y()),small.bottomRight());

    QList<QList<QRectF> > listeRectTab;
    QList<QRectF> rectLigne;
    rectLigne.append(small);
    rectLigne.append(big);
    rectLigne.append(misc);
    rectLigne.append(reaSmall);
    listeRectTab.append(rectLigne);

    int paddingLeft = PADDINGL;
    int paddingTop = PADDINGT;
    int paddingRight = PADDINGR;
    int paddingBottom = PADDINGB;
    listeRectTab = setTablePadding(paddingLeft, paddingTop, paddingRight, paddingBottom,listeRectTab);

    // attribuer le bon rectangle à la fonction
    QRectF r;
    if(size == TransDocument::SMALL)
        r = listeRectTab.at(0).at(0);
    if(size == TransDocument::BIG)
        r = listeRectTab.at(0).at(1);
    if(size == TransDocument::MISC)
        r = listeRectTab.at(0).at(2);
    if(size == TransDocument::REASMALL)
        r = listeRectTab.at(0).at(3);

    // Enfin tester la longueur et retourner
    QList<float> retour = checkLength(t,r,QFont(font,70*zoom),size == TransDocument::MISC);
    return retour;
}

void TransDocument::printPreview(QPrinter* print, QList<Secteur*>* secteurs)
{
    print->setFullPage(true);
    print->setResolution(QPrinter::HighResolution);
    print->setPageSize(QPrinter::A4);
    print->setOrientation(QPrinter::Portrait);
    sect = secteurs;
    printDocument(print, sect);

}

void TransDocument::refresh(QPrinter* print, QList<Secteur *>*  sects)
{
    marginLeft = (UNMODIFWIDTHLEFT+millimetersMarginLeft)*zoom;
    marginRight = (UNMODIFWIDTHRIGHT+millimetersMarginRight)*zoom;
    marginTop = millimetersMarginTop*zoom;
    marginBottom = millimetersMarginBottom*zoom;

    printDocument(print, sects);
}

void TransDocument::printDocument(QList<Secteur*>* secteurs)
{
    printer.setFullPage(true);
    printer.setResolution(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    painter.begin(&printer);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(Qt::SolidPattern, qreal(0)));
    //initiate painter scale
    painter.scale(printer.width()/(printer.widthMM()*zoom),printer.height()/(printer.heightMM()*zoom));

    QList<Secteur *>* sects = new QList<Secteur *>;

    if(secteurs == 0)
    {
        sects->append(secteur);
    }
    else
        sects = secteurs;

    for(int i=0 ; i < sects->count() ; i++)
    {
        lineNB = sects->at(i)->getChambres().count()*4;
        //Vertical working space (height minus top & bottom margins)
        VWorkingSpace = (printer.heightMM()*zoom)-(marginTop+marginBottom);
        //Cell height
        lineHeight = VWorkingSpace/lineNB;
        //Horizontal working space (width minux left & right borders)
        HWorkingSpace = (printer.widthMM()*zoom)-(marginLeft+marginRight);

        printSecteur(sects->at(i));
        if(i < sects->count()-1)
            printer.newPage();
    }
    painter.end();

}

void TransDocument::printDocument(QPrinter* print, QList<Secteur*>* secteurs)
{
    print->setFullPage(true);
    print->setResolution(QPrinter::HighResolution);
    print->setPageSize(QPrinter::A4);
    print->setOrientation(QPrinter::Portrait);
    painter.begin(print);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(QPen(Qt::SolidPattern, qreal(0)));
    //initiate painter scale
    painter.scale(print->width()/(print->widthMM()*zoom),print->height()/(print->heightMM()*zoom));
    QList<Secteur *>* sects = new QList<Secteur *>;

    if(secteurs == 0)
    {
        sects->append(secteur);
    }
    else
        sects = secteurs;

    for(int i=0 ; i < sects->count() ; i++)
    {
        lineNB = sects->at(i)->getChambres().count()*4;
        //Vertical working space (height minus top & bottom margins)
        VWorkingSpace = (print->heightMM()*zoom)-(marginTop+marginBottom);
        //Cell height
        lineHeight = VWorkingSpace/lineNB;
        //Horizontal working space (width minux left & right borders)
        HWorkingSpace = (print->widthMM()*zoom)-(marginLeft+marginRight);

        printSecteur(sects->at(i));
        if(i < sects->count()-1)
            print->newPage();
    }
    painter.end();

}

QPrinter *TransDocument::getPrinter()
{
    return &printer;
}

void TransDocument::printSecteur(Secteur* sect)
{
    lineNB = sect->getChambres().count()*4;
    QList<ChambrePanel*>* chambres = baseData->getPanelFromSecteur(sect);

    //Draw Secteur time String
    if(sect->getLastEditEpoch() != "")
    {
        QDateTime tpsEpoch = QDateTime::currentDateTime();
        QString date = tpsEpoch.toString("'Document imprimé le 'dddd d MMMM yyyy 'à' H:mm:ss");

        painter.setFont(QFont(font, 80*zoom));
        QFontMetrics fm(painter.font());
        painter.drawText(QPointF(marginLeft,marginTop+drawOffset-5), date);
    }

    for(int i=0; i<chambres->count(); i++)
    {
        printChambre(chambres->at(i), &painter);
        drawOffset+=lineHeight*4;
    }
    drawOffset=0;

}

void TransDocument::printSecteur(Secteur* sect, QPainter* paint)
{
    lineNB = sect->getChambres().count()*4;
    QList<ChambrePanel*>* chambres = baseData->getPanelFromSecteur(sect);

    //Draw print time String

    QDateTime tpsEpoch = QDateTime::currentDateTime();
    QString date = tpsEpoch.toString("'Document imprimé le 'dddd d MMMM yyyy 'à' H:mm:ss");

    paint->setFont(QFont(font, 80*zoom));
    QFontMetrics fm(paint->font());
    paint->drawText(QPointF(marginLeft,marginTop+drawOffset-5), date);

    for(int i=0; i<chambres->count(); i++)
    {
        printChambre(chambres->at(i), paint);
        drawOffset+=lineHeight*4;
    }
    drawOffset=0;

}

void TransDocument::printChambre(ChambrePanel* chambre, QPainter *paint)
{
    QList<QList<QRectF> > listeRectTab;

    //Ligne 1
    QList<QRectF> rectLigne1;
    rectLigne1.append(QRectF(marginLeft+percentSum(0)*HWorkingSpace,marginTop+drawOffset+lineHeight*0,colWidthPercent.at(0)*HWorkingSpace,lineHeight));
    rectLigne1.append(QRectF(marginLeft+percentSum(1)*HWorkingSpace,marginTop+drawOffset+lineHeight*0,colWidthPercent.at(1)*0.4*HWorkingSpace,lineHeight));
    rectLigne1.append(QRectF(marginLeft+percentSum(1)*HWorkingSpace+colWidthPercent.at(1)*0.4*HWorkingSpace,marginTop+drawOffset+lineHeight*0,colWidthPercent.at(1)*0.6*HWorkingSpace,lineHeight));
    rectLigne1.append(QRectF(marginLeft+percentSum(2)*HWorkingSpace,marginTop+drawOffset+lineHeight*0,colWidthPercent.at(2)*HWorkingSpace,lineHeight));
    rectLigne1.append(QRectF(marginLeft+percentSum(3)*HWorkingSpace,marginTop+drawOffset+lineHeight*0,colWidthPercent.at(3)*HWorkingSpace,lineHeight));
    rectLigne1.append(QRectF(marginLeft+percentSum(4)*HWorkingSpace,marginTop+drawOffset+lineHeight*0,colWidthPercent.at(4)*HWorkingSpace,lineHeight));
    listeRectTab.append(rectLigne1);


    //Ecriture ligne 1
    paint->setPen(QPen(Qt::black, 1, Qt::SolidLine));

    drawIncompleteRect(true,true,true,false,listeRectTab.at(0).at(0),paint);
    drawIncompleteRect(true,true,true,true,listeRectTab.at(0).at(1),paint);
    drawIncompleteRect(false,true,false,true,listeRectTab.at(0).at(2),paint);
    drawIncompleteRect(false,true,false,true,listeRectTab.at(0).at(3),paint);
    drawIncompleteRect(false,true,false,true,listeRectTab.at(0).at(4),paint);
    drawIncompleteRect(false,true,true,true,listeRectTab.at(0).at(5),paint);

    //Ligne 2
    QList<QRectF> rectLigne2;
        //Misc (sur 3 lignes)
    rectLigne2.append(QRectF(marginLeft+percentSum(0)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(0)*HWorkingSpace,lineHeight*3));

    rectLigne2.append(QRectF(marginLeft+percentSum(1)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(1)*HWorkingSpace,lineHeight));
    rectLigne2.append(QRectF(marginLeft+percentSum(2)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(2)*HWorkingSpace,lineHeight));
    rectLigne2.append(QRectF(marginLeft+percentSum(3)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(3)*HWorkingSpace,lineHeight));
    rectLigne2.append(QRectF(marginLeft+percentSum(4)*HWorkingSpace,marginTop+drawOffset+lineHeight*1,colWidthPercent.at(4)*HWorkingSpace,lineHeight));
    listeRectTab.append(rectLigne2);

    //Ecriture ligne 2
    drawIncompleteRect(true,false,true,true,listeRectTab.at(1).at(0),paint);
    drawIncompleteRect(false,false,false,false,listeRectTab.at(1).at(1),paint);
    drawIncompleteRect(false,false,false,false,listeRectTab.at(1).at(2),paint);
    drawIncompleteRect(false,false,false,false,listeRectTab.at(1).at(3),paint);
    drawIncompleteRect(false,false,true,false,listeRectTab.at(1).at(4),paint);

    //Ligne 3
    QList<QRectF> rectLigne3;
    rectLigne3.append(QRectF(marginLeft+percentSum(1)*HWorkingSpace,marginTop+drawOffset+lineHeight*2,colWidthPercent.at(1)*HWorkingSpace,lineHeight));
    rectLigne3.append(QRectF(marginLeft+percentSum(2)*HWorkingSpace,marginTop+drawOffset+lineHeight*2,colWidthPercent.at(2)*HWorkingSpace,lineHeight));
    rectLigne3.append(QRectF(marginLeft+percentSum(3)*HWorkingSpace,marginTop+drawOffset+lineHeight*2,colWidthPercent.at(3)*HWorkingSpace,lineHeight));
    rectLigne3.append(QRectF(marginLeft+percentSum(4)*HWorkingSpace,marginTop+drawOffset+lineHeight*2,colWidthPercent.at(4)*HWorkingSpace,lineHeight));
    listeRectTab.append(rectLigne3);

    //Ecriture ligne 3
    drawIncompleteRect(false,false,false,false,listeRectTab.at(2).at(0),paint);
    drawIncompleteRect(false,false,false,false,listeRectTab.at(2).at(1),paint);
    drawIncompleteRect(false,false,false,false,listeRectTab.at(2).at(2),paint);
    drawIncompleteRect(false,false,true,false,listeRectTab.at(2).at(3),paint);

    //Ligne 4
    QList<QRectF> rectLigne4;
    rectLigne4.append(QRectF(marginLeft+percentSum(1)*HWorkingSpace,marginTop+drawOffset+lineHeight*3,colWidthPercent.at(1)*HWorkingSpace,lineHeight));
    rectLigne4.append(QRectF(marginLeft+percentSum(2)*HWorkingSpace,marginTop+drawOffset+lineHeight*3,colWidthPercent.at(2)*HWorkingSpace,lineHeight));
    rectLigne4.append(QRectF(marginLeft+percentSum(3)*HWorkingSpace,marginTop+drawOffset+lineHeight*3,colWidthPercent.at(3)*HWorkingSpace,lineHeight));
    rectLigne4.append(QRectF(marginLeft+percentSum(4)*HWorkingSpace,marginTop+drawOffset+lineHeight*3,colWidthPercent.at(4)*HWorkingSpace,lineHeight));
    listeRectTab.append(rectLigne4);

    //Ecriture ligne 4
    drawIncompleteRect(false,false,false,true,listeRectTab.at(3).at(0),paint);
    drawIncompleteRect(false,false,false,true,listeRectTab.at(3).at(1),paint);
    drawIncompleteRect(false,false,false,true,listeRectTab.at(3).at(2),paint);
    drawIncompleteRect(false,false,true,true,listeRectTab.at(3).at(3),paint);

    //sets table default padding
    int paddingLeft = PADDINGL;
    int paddingTop = PADDINGT;
    int paddingRight = PADDINGR;
    int paddingBottom = PADDINGB;
    QList<QList<QRectF> > listeRectTabOld = listeRectTab;
    listeRectTab = setTablePadding(paddingLeft, paddingTop, paddingRight, paddingBottom,listeRectTab);


    //N° de chambre
    paint->setFont(QFont(font, 200*zoom, QFont::Bold));
    paint->drawText(listeRectTab.at(0).at(0), Qt::AlignCenter|Qt::TextWordWrap, chambre->objectName());

    //Fonts
    QFont baseFont = QFont(font, (MIN_FONT+fontSize*5)*zoom);
    int minFontSize = MIN_FONT;

    //Date entree
    paint->setFont(QFont(font, 130*zoom, QFont::Bold));

    QString dateEntree = chambre->getDureeSejour();
    if(!dateEntree.startsWith('j',Qt::CaseInsensitive))
    {
        paint->setBackgroundMode(Qt::OpaqueMode);
        paint->setBackground(QBrush(QColor(70,70,70)));
        paint->fillRect(listeRectTabOld.at(0).at(1),QBrush(QColor(70,70,70)));
    }
    else
        paint->drawText(listeRectTab.at(0).at(1), Qt::AlignCenter|Qt::TextWordWrap, dateEntree);
    paint->setBackgroundMode(Qt::TransparentMode);
    paint->setBackground(QBrush(QColor(255,255,255)));



    //NomLabel
    paint->setFont(baseFont);
    paint->drawText(listeRectTab.at(0).at(2), Qt::AlignVCenter|Qt::TextWordWrap, "Nom");

    //Nom
    paint->setFont(QFont(font, 155*zoom, QFont::Bold));
    //paint->drawText(listeRectTab.at(0).at(3), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getNomText());
    drawWrappedText(chambre->getNomText(),listeRectTab.at(0).at(3), paint->font(),paint,120);



    //MotifEntreeLabel
    paint->setFont(baseFont);
    paint->drawText(listeRectTab.at(0).at(4), Qt::AlignVCenter|Qt::TextWordWrap, "Motif d'entrée");

    //MotifdEntree
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(0).at(5), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getMotifEntreeText());
    drawWrappedText(chambre->getMotifEntreeText(),listeRectTab.at(0).at(5), paint->font(),paint,minFontSize);


    //Misc
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(1).at(0), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getMisc());
    drawWrappedText(chambre->getMisc(),listeRectTab.at(1).at(0), paint->font(),paint,minFontSize,true);



    //AtcdLabel
    paint->setFont(baseFont);
    paint->drawText(listeRectTab.at(1).at(1), Qt::AlignVCenter|Qt::TextWordWrap, "Antécédents");

    //Atcd
    QString atcdAllergies = chambre->getAtcdText()+
            ((chambre->getAllergiesCheck())?" allergies : "+chambre->getAllergiesText()+"":"");
    paint->setFont(baseFont);
    drawWrappedText(atcdAllergies,listeRectTab.at(1).at(2), paint->font(),paint,minFontSize);




    //ReaMain
    if(chambre->getReaChecked())
    {
        QFont reaFont = QFont(font, 110*zoom, QFont::Bold);
        reaFont.setUnderline(true);
        paint->setFont(reaFont);
        QRectF interm;
        paint->drawText(listeRectTab.at(1).at(3), Qt::AlignVCenter|Qt::TextWordWrap, MAIN_REA_TXT, &interm);
        //QRectF interm = paint->boundingRect(listeRectTab.at(1).at(3), Qt::AlignVCenter|Qt::TextWordWrap, MAIN_REA_TXT);
        QRectF mainReaTextRect = QRectF(QPoint(interm.topRight().x()+5,listeRectTab.at(1).at(3).topRight().y()),listeRectTab.at(1).at(3).bottomRight());
        reaFont.setUnderline(false);
        reaFont.setBold(false);
        paint->setFont(reaFont);
        //paint->drawText(mainReaTextRect, Qt::AlignVCenter|Qt::TextWordWrap, chambre->getReaText());
        drawWrappedText(chambre->getReaText(),mainReaTextRect,paint->font(),paint,minFontSize);
    }
    else
    {
        paint->setFont(baseFont);
        paint->drawText(listeRectTab.at(1).at(3), Qt::AlignVCenter|Qt::TextWordWrap, "Réa");
    }

    //ReaSub
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(1).at(4), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getReaBigText());
    drawWrappedText(chambre->getReaBigText(),listeRectTab.at(1).at(4),paint->font(),paint,minFontSize);



    //ExamsLabel
    paint->setFont(baseFont);
    paint->drawText(listeRectTab.at(2).at(0), Qt::AlignVCenter|Qt::TextWordWrap, "Exams/Soins");

    //Exams
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(2).at(1), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getExamText());
    drawWrappedText(chambre->getExamText(), listeRectTab.at(2).at(1),paint->font(),paint,minFontSize);



    //Per os Label
    paint->setFont(baseFont);
    paint->drawText(listeRectTab.at(2).at(2), Qt::AlignVCenter|Qt::TextWordWrap, "Per os");

    //Per os
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(2).at(3), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getPerosText());
    drawWrappedText(chambre->getPerosText(), listeRectTab.at(2).at(3),paint->font(),paint,minFontSize);



    //SVMain
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(3).at(0), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getSvMainText());
    drawWrappedText(chambre->getSvMainText(), listeRectTab.at(3).at(0),paint->font(),paint,minFontSize);

    //SVSub
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(3).at(1), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getSvSubText());
    drawWrappedText(chambre->getSvSubText(), listeRectTab.at(3).at(1),paint->font(),paint,minFontSize);



    //SortieMain
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(3).at(2), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getSortieMainText());
    drawWrappedText(chambre->getSortieMainText(), listeRectTab.at(3).at(2),paint->font(),paint,minFontSize);

    //SortieSub
    paint->setFont(baseFont);
    //paint->drawText(listeRectTab.at(3).at(3), Qt::AlignVCenter|Qt::TextWordWrap, chambre->getSortieSubText());
    drawWrappedText(chambre->getSortieSubText(), listeRectTab.at(3).at(3),paint->font(),paint,minFontSize);
}

void TransDocument::drawIncompleteRect(bool left, bool top, bool right, bool bottom, QRectF rect, QPainter* painter)
{
    if(left)
        painter->drawLine(rect.topLeft(),rect.bottomLeft());
    if(top)
        painter->drawLine(rect.topLeft(),rect.topRight());
    if(right)
        painter->drawLine(rect.topRight(),rect.bottomRight());
    if(bottom)
        painter->drawLine(rect.bottomLeft(),rect.bottomRight());
}

void TransDocument::setSecteur(Secteur *s)
{
    this->secteur = s;
}

QList<QList<QRectF> > TransDocument::setTablePadding(int left, int top, int right, int bottom, QList<QList<QRectF> > tableau)
{
    QList<QList<QRectF> > double_tableau;
    for(int i=0 ; i<tableau.count() ; i++)
    {
        QList<QRectF> tableau_interne;
        for(int j=0 ; j<tableau.at(i).count(); j++)
        {
            tableau_interne.append(setCellPadding(left, top, right, bottom, tableau.at(i).at(j)));
        }
        double_tableau.append(tableau_interne);
    }
    return double_tableau;
}

QRectF TransDocument::setCellPadding(int left, int top, int right, int bottom, QRectF rectr)
{
    rectr.setTopLeft(QPointF(rectr.topLeft().x()+left, rectr.topLeft().y()+top));
    rectr.setBottomRight(QPointF(rectr.bottomRight().x()-right, rectr.bottomRight().y()-bottom));
    return rectr;
}

void TransDocument::drawWrappedText(QString t, QRectF r, QFont f, QPainter* p, int minFontSize, bool auth_slashN,QRectF* bound)
{

    QFont font(f);
    QFontMetrics* fm = new QFontMetrics(font);
    bool containsAllergies = false;
    bool containsPsmt = false;
    int allergiesOffset = 0;
    QRegularExpression psmt("((p|P)smt)");
    QRegularExpression allergies("allergies :");

    int tW = fm->width(t);
    int fontH = fm->height();
    int lignes_min = (tW/r.width())+1;
    int maxVLines = r.height()/fontH;
    int fontSizeDecreaseOffset = -5*zoom;
    p->setFont(font);

    if(auth_slashN)
    {
        t = t.replace("^\n","");
        lignes_min =0;
        int width = 0;
        for(int i=0 ; i<t.length() ; i++)
        {
            QChar c = t.at(i);
            if(c ==  '\n')
            {
                lignes_min++;
                width = 0;
            }
            else
            {
                width += fm->width(c);
            }
            if(width >= r.width())
            {
                lignes_min++;
                width =0;
            }

        }
            lignes_min++;
    }

    if(lignes_min > maxVLines && font.pointSize() > minFontSize*zoom)
    {
        font.setPointSize(font.pointSize()+fontSizeDecreaseOffset);
        return drawWrappedText(t, r, font, p, minFontSize, auth_slashN, bound);
    }
    else
    {

        QString workText = t;
        if(!auth_slashN)
            workText = workText.replace('\n',' ');
        else
            workText = workText.replace("(\n)*","\n");

        if(workText.contains(psmt)){
            containsPsmt = true;
        }
        if(workText.contains(allergies)){
            containsAllergies = true;
            allergiesOffset = workText.indexOf(allergies);
        }

        QChar cutChar = ' ';
        int offsetForCut = 0;
        int offset = 1;
        int fullOffset = 0;
        int lineSize = 0;
        int lines = 1;

        QList<QStaticText> l;
        QList<QPointF> pts;

        QPointF topL = QPointF(r.topLeft().x(), r.topLeft().y());

        for(; offset<workText.length(); offset++)
        {
            fullOffset++;
            if (fullOffset ==0 && containsPsmt)
            {
                font.setBold(true);
                font.setUnderline(true);
                fm = new QFontMetrics(font);
            }
            if (fullOffset ==4 && containsPsmt)
            {
                font.setBold(false);
                font.setUnderline(false);
                fm = new QFontMetrics(font);
            }

            if(containsAllergies){
                if(fullOffset == allergiesOffset)
                {
                    font.setBold(true);
                    font.setUnderline(true);
                    fm = new QFontMetrics(font);
                }
            }
            QChar currentC = workText.at(offset);
            lineSize=fm->boundingRect(workText.left(offset+1)).width();
            if(currentC == cutChar)
                offsetForCut = offset;

            if(currentC == '\n')
            {
                lineSize = 1.5*r.width();
                offsetForCut = offset;
            }
            if(lineSize >= r.width()-5)
            {

                int cutpt = 0;
                if(offsetForCut > 0 && offsetForCut <= offset && offset-offsetForCut <5)
                    cutpt = offsetForCut;
                else
                {
                    if(workText.length() > offset+2)
                    {
                        if(workText.at(offset+1) == ' ')
                        {
                            workText.insert(offset-2,'-');
                            cutpt = offset-2;
                        }
                        else if(workText.at(offset+2) == ' ')
                        {
                            workText.insert(offset-1,'-');
                            cutpt = offset-1;
                        }
                        else
                        {
                            workText.insert(offset,'-');
                            cutpt = offset++;
                        }
                    }
                }
                if(lines >= maxVLines)
                {
                    if(font.pointSize() > minFontSize*zoom)
                    {
                        font.setPointSize(font.pointSize()+fontSizeDecreaseOffset);
                        font.setBold(false);
                        font.setUnderline(false);
                        return drawWrappedText(t, r, font, p, minFontSize, auth_slashN, bound);
                    }
                    else
                    {
                    QStaticText elidedText(fm->elidedText(workText, Qt::ElideRight, r.width()));
                    elidedText.setTextWidth(r.width()*2);
                    l.append(elidedText);
                    pts.append(topL);
                    workText = "";
                    }
                }
                else
                {
                    QString tmp = workText.left(cutpt+1);
                    QStaticText lineText(tmp);
                    lineText.setTextWidth(r.width()*2);
                    l.append(lineText);
                    pts.append(topL);
                }
                workText = workText.remove(0,cutpt+1);
                if(workText.startsWith(' ') || workText.startsWith('\n'))
                    workText = workText.mid(1);
                if(workText.endsWith(' ') || (workText.endsWith('\n') ))
                    workText = workText.left(workText.length()-1);
                offset=0;
                offsetForCut=0;
                topL.setY(topL.y()+fontH);
                lineSize=0;
                lines++;

            }
        }
        QString tmp2 = workText;
        QStaticText finalText(tmp2);
        finalText.setTextWidth(r.width()*2);
        l.append(finalText);
        pts.append(topL);
        int Valign = ((r.height()-l.count()*fontH)/2>0)?(r.height()-l.count()*fontH)/2:0;

        if(containsAllergies)
        {
            bool allReached = false;
            int textOffset = 0;
            for(int i=0 ; i< l.count() ; i++)
            {
                textOffset += l.at(i).text().length();
                if(allReached)
                {
                    QString text = l.at(i).text();
                    text = "<b><u>"+text+"</u></b>";
                    QStaticText st(text);
                    st.setTextWidth(r.width()*2);
                    p->drawStaticText(QPointF(pts.at(i).x(), pts.at(i).y()+ Valign),st);
                    continue;
                }
                if(textOffset >= allergiesOffset)
                {
                    int offset = l.at(i).text().length()-(textOffset-allergiesOffset);
                    QString text = l.at(i).text().left(offset) + "<b><u>" +l.at(i).text().mid(offset)+"</u></b>";
                    QStaticText st(text);
                    st.setTextWidth(r.width()*2);
                    p->drawStaticText(QPointF(pts.at(i).x(), pts.at(i).y()+ Valign),st);
                    allReached = true;
                    continue;
                }
                p->drawStaticText(QPointF(pts.at(i).x(), pts.at(i).y()+ Valign), l.at(i));

            }
        }
        else
            for(int i=0 ; i< l.count() ; i++)
            {
                QStaticText tx;
                if(l.at(i).text().contains("Psmt")){
                    tx = QStaticText(l.at(i).text().replace("Psmt","<b>Psmt</b>"));
                }
                else
                    tx = l.at(i);
                tx.setTextWidth(r.width()+25);

                p->drawStaticText(QPointF(pts.at(i).x(), pts.at(i).y()+ Valign), tx);

            }
        return;
    }
}
//###############################################################################################################
//Renvoie une QList de 3 float. le premier retournant le nombre de ligens max ; le second représentant le nombre#
//de lignes utilisé, le dernier le % de l'espace occupé par le texte.                                           #
//                                                                                                              #
//                                                                                                              #
//                                                                                                              #
//                                                                                                              #
//                                                                                                              #
//                                                                                                              #
//###############################################################################################################
QList<float> TransDocument::checkLength(QString t, QRectF r, QFont f, bool auth_slashN)
{

    QList<float> retour;
    QFont font(f);
    //painter.setFont(font);


    QFontMetricsF* fm = new QFontMetricsF(font, &printer);
    qreal tW = ((fm->width(t)));
    int fontH = fm->height();
    int lignes_min = (tW/r.width())+1;
    int maxVLines = r.height()/fontH;
    retour.append(static_cast<float>(maxVLines));

    if(auth_slashN)
    {
        t = t.replace("^\n","");
        lignes_min =0;
        qreal width = 0;
        for(int i=0 ; i<t.length() ; i++)
        {
            QChar c = t.at(i);
            if(c ==  '\n')
            {
                lignes_min++;
                width = 0;
            }
            else
            {
                width += ((fm->width(c)));
            }
            if(width >= r.width()-1)
            {
                lignes_min++;
                width =0;
            }

        }
            lignes_min++;
    }

    if(lignes_min > maxVLines)
    {
        retour.append(lignes_min);
        retour.append(lignes_min/(maxVLines*1.));
        return retour;
    }
    bool containsAllergies = false;
    bool containsPsmt = false;
    if(t.contains(QRegularExpression("((p|P)smt)")))
        containsPsmt = true;

    int allergiesOffset = 0;
    if(t.contains(QRegExp("allergies : ")))
    {
        containsAllergies = true;
        allergiesOffset = t.indexOf(QRegExp("allergies : "));
    }
    if(t.contains(QRegularExpression("(<u>|<b>|</u>|</b>)")))
        t.replace(QRegularExpression("(<u>|<b>|</u>|</b>)"),"");

    QString workText = t;
    if(!auth_slashN)
        workText = workText.replace('\n',' ');
    else
        workText = workText.replace("(\n)*","\n");

    QChar cutChar = ' ';
    int offsetForCut = 0;
    int offset = 1;
    int fullOffset = 0;
    qreal lineSize = 0;
    int lines = 1;

    for(; offset<workText.length(); offset++)
    {
        fullOffset++;
        if(fullOffset == 0 && containsPsmt){
            font.setBold(true);
            font.setUnderline(true);
            delete fm;
            fm = new QFontMetricsF(font, &printer);
        }
        if(fullOffset == 0 && containsPsmt){
            font.setBold(false);
            font.setUnderline(false);
            delete fm;
            fm = new QFontMetricsF(font, &printer);
        }

        if(containsAllergies)
            if(fullOffset == allergiesOffset)
            {
                font.setBold(true);
                font.setUnderline(true);
                delete fm;
                fm = new QFontMetricsF(font, &printer);
            }
        QChar currentC = workText.at(offset);
        lineSize=((fm->boundingRect(workText.left(offset+1)).width()));
        if(currentC == cutChar)
            offsetForCut = offset;

        if(currentC == '\n')
        {
            lineSize = 1.5*r.width();
            offsetForCut = offset;
        }
        if(lineSize >= r.width()-5)
        {

            int cutpt = 0;
            if(offsetForCut > 0 && offsetForCut <= offset && offset-offsetForCut <5)
                cutpt = offsetForCut;
            else
            {

                if(workText.size() > offset+2) {

                    if(workText.at(offset+1) == ' ')
                    {
                        workText.insert(offset-2,'-');
                        cutpt = offset-2;
                    }
                    else if(workText.at(offset+2) == ' ')
                    {
                        workText.insert(offset-1,'-');
                        cutpt = offset-1;
                    }
                    else
                    {
                        workText.insert(offset,'-');
                        cutpt = offset++;
                    }
                }
                else
                {
                    workText.insert(offset,'-');
                    cutpt = offset++;
                }
            }
            if(lines >= maxVLines)
            {
                retour.append(lines);
                retour.append(1.);
                return retour;
            }
            workText = workText.remove(0,cutpt+1);
            if(workText.startsWith(' ') || workText.startsWith('\n'))
                workText = workText.mid(1);
            if(workText.endsWith(' ') || (workText.endsWith('\n') ))
                workText = workText.left(workText.length()-1);
            workText = workText;
            offset=0;
            offsetForCut=0;
            lineSize=0;
            lines++;
        }
    }
    retour.append(lines);
    float percent = ((lines-1)*(r.width()-5)+lineSize)/(maxVLines*(r.width()-5));
    retour.append(percent);
    return retour;
}

