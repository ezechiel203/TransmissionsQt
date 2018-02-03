#ifndef ECRITUREXML_H
#define ECRITUREXML_H

#include <QDomDocument>
#include <QDomElement>
#include <chambrepanel.h>
#include <gestiontabwidget.h>
#include <QFile>

class EcritureXML
{
public:
    explicit EcritureXML(GestionTabWidget* parent);
    explicit EcritureXML(QString fichier, GestionTabWidget* parent);
    ~EcritureXML();
    void save();
    void closeDelete();


private:
    void writeToFile(QFile f);
    void createDomTree();
    void populateChambreNode(QDomElement* chambreElt, ChambrePanel *chambre);
    void appendTextElement(QDomElement* elt, QString valeur);
    GestionTabWidget* parent;
    QDomDocument* doc;
    QFile* f;

};

#endif // ECRITUREXML_H
