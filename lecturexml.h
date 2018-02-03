#ifndef LECTUREXML_H
#define LECTUREXML_H

#include <QObject>
#include <QDomDocument>
#include <chambrepanel.h>
#include <QDomNodeList>
#include <QDomNode>
#include <gestiontabwidget.h>
#include <QFile>

class LectureXML
{
public:
    explicit LectureXML(GestionTabWidget *parent=0);
    explicit LectureXML(QString openFile, GestionTabWidget *parent=0);
    void setParent(GestionTabWidget *par);
    void fillPanels();
    void closeDelete();

private:
    QDomDocument* doc;
    GestionTabWidget* parent;
    void findRooms(QList<ChambrePanel*>* panels, QDomNode rootNode);
    void fillRoom(ChambrePanel* cp, QDomNode baseNode);
    QString getTextValue(QString val, QDomNode chambre);

};

#endif // LECTUREXML_H
