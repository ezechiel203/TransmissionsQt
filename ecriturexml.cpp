#include "ecriturexml.h"
#include <QDateTime>
#include <QDebug>
#include <QTextStream>

EcritureXML::EcritureXML(GestionTabWidget* parent)
{
    this->parent = parent;
    this->f = new QFile("trans.sav");
    if (!f->open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
}

EcritureXML::EcritureXML(QString fichier, GestionTabWidget *parent)
{
    this->parent = parent;
    this->f = new QFile(fichier);
    if (!f->open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
}

EcritureXML::~EcritureXML(){
    delete f;
    delete doc;

}
void EcritureXML::save()
{
    createDomTree();
    QTextStream stream(f) ;
    this->doc->save(stream,4);
    stream.flush();
}

void EcritureXML::closeDelete()
{
    this->f->close();
}

void EcritureXML::createDomTree()
{
    this->doc = new QDomDocument("Transmissions");
    QDomProcessingInstruction instr = doc->createProcessingInstruction(
                      "xml", "version='1.0' encoding='UTF-8'");
    doc->appendChild(instr);
    QDomElement rootNode = doc->createElement("Transmissions");
    doc->appendChild(rootNode);
    QList<QList<ChambrePanel*>*>* panels = parent->getPanels();
    QList<ChambrePanel*>* panel;
    QList<Secteur*>* secteurs = parent->sect;
    QString nowTime;
    nowTime = nowTime.number(QDateTime::currentMSecsSinceEpoch());

    for(int i=0 ; i< secteurs->count();i++)
    {
        QDomElement secteurNode = doc->createElement("secteur");
        panel = panels->at(i);
        secteurNode.setAttribute("type", secteurs->at(i)->getNom());
        secteurNode.setAttribute("time", nowTime);

        for(int j=0;j< panel->count();j++)
        {
            panel->at(j)->dureeSejourUpdate();
            QDomElement chambreNode = doc->createElement("chambre");
            chambreNode.setAttribute("id", panel->at(j)->objectName());
            populateChambreNode(&chambreNode, panel->at(j));
            secteurNode.appendChild(chambreNode);
        }
        rootNode.appendChild(secteurNode);
    }
}


void EcritureXML::populateChambreNode(QDomElement* chambreElt, ChambrePanel *chambre)
{
    QDomElement nom = doc->createElement("nom");
    QDomElement dateEntree = doc->createElement("dateEntree");
    QDomElement motif = doc->createElement("motif");
    QDomElement atcd = doc->createElement("atcd");
    QDomElement exams = doc->createElement("exams");
    QDomElement issv = doc->createElement("issv");
    QDomElement svtype = doc->createElement("svtype");
    QDomElement svmain = doc->createElement("svmain");
    QDomElement svsub = doc->createElement("svsub");
    QDomElement sortiemain = doc->createElement("sortiemain");
    QDomElement sortiesub = doc->createElement("sortiesub");
    QDomElement misc = doc->createElement("misc");
    QDomElement reamain = doc->createElement("reaMain");
    QDomElement reasub = doc->createElement("reasub");
    QDomElement peros = doc->createElement("peros");
    QDomElement reaset = doc->createElement("reaset");
    QDomElement o2check = doc->createElement("o2check");
    QDomElement oxydeb = doc->createElement("oxydeb");
    QDomElement aerosols = doc->createElement("aerosols");
    QDomElement allergiescheck = doc->createElement("allergiesCheck");
    QDomElement allergies = doc->createElement("allergies");

    appendTextElement(&nom, chambre->getNomText());
    appendTextElement(&dateEntree, chambre->getDate());
    appendTextElement(&motif, chambre->getMotifEntreeText());
    appendTextElement(&atcd, chambre->getAtcdText());
    appendTextElement(&exams, chambre->getExamText());
    appendTextElement(&issv, (chambre->getSondeVesCheck()==true)?"true":"false");
    appendTextElement(&svtype, QString::number(chambre->getSondeVesComboIndex()));
    appendTextElement(&sortiemain, chambre->getSortieMainText());
    appendTextElement(&sortiesub, chambre->getSortieSubText());
    appendTextElement(&misc, chambre->getMisc());
    appendTextElement(&reamain, chambre->getReaText());
    appendTextElement(&reasub, chambre->getReaBigText());
    appendTextElement(&peros, chambre->getPerosText());
    appendTextElement(&reaset, (chambre->getReaChecked()==true)?"true":"false");
    appendTextElement(&o2check, (chambre->getOxyCheck()==true)?"true":"false");
    appendTextElement(&oxydeb, chambre->getOxyDeb());
    appendTextElement(&aerosols, (chambre->getAerosolsCheck()==true)?"true":"false");
    appendTextElement(&allergiescheck, (chambre->getAllergiesCheck()==true)?"true":"false");
    appendTextElement(&allergies, chambre->getAllergiesText());
    appendTextElement(&svmain, chambre->getSvMainText());
    appendTextElement(&svsub, chambre->getSvSubText());

    chambreElt->appendChild(nom);
    chambreElt->appendChild(dateEntree);
    chambreElt->appendChild(motif);
    chambreElt->appendChild(atcd);
    chambreElt->appendChild(exams);
    chambreElt->appendChild(issv);
    chambreElt->appendChild(svtype);
    chambreElt->appendChild(svmain);
    chambreElt->appendChild(svsub);
    chambreElt->appendChild(sortiemain);
    chambreElt->appendChild(sortiesub);
    chambreElt->appendChild(misc);
    chambreElt->appendChild(reamain);
    chambreElt->appendChild(reasub);
    chambreElt->appendChild(peros);
    chambreElt->appendChild(reaset);
    chambreElt->appendChild(o2check);
    chambreElt->appendChild(oxydeb);
    chambreElt->appendChild(aerosols);
    chambreElt->appendChild(allergiescheck);
    chambreElt->appendChild(allergies);

}

void EcritureXML::appendTextElement(QDomElement* elt, QString valeur)
{
    if(valeur != "")
    {
        QDomText txt = doc->createTextNode(valeur);
        elt->appendChild(txt);
    }
}
