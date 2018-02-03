#include "lecturexml.h"
#include <QDebug>
#include <QRegularExpression>

LectureXML::LectureXML(GestionTabWidget *parent)
{
    doc = new QDomDocument("trans.sav");
    this->parent = parent;
    QFile* file = new QFile("trans.sav");
    if (!file->open(QIODevice::ReadOnly)){
        return;
    }
    if (! this->doc->setContent(file))
    {
        file->close();
        return;
    }
    file->close();
}

LectureXML::LectureXML(QString openFile, GestionTabWidget *parent)
{
    doc = new QDomDocument("trans.sav");
    this->parent = parent;
    QFile* file = new QFile(openFile);
    if (!file->open(QIODevice::ReadOnly)){
        return;
    }
    if (! this->doc->setContent(file))
    {
        file->close();
        return;
    }
    file->close();

}

void LectureXML::closeDelete()
{
    //delete this;
}

void LectureXML::fillPanels(){
    QList<QList<ChambrePanel*>*>* panels = parent->getPanels();
    QList<Secteur*>* secteurs = parent->sect;
    QString sectName= "";
    QDomElement docElem = doc->documentElement();
    QDomNodeList primusNodeList = docElem.elementsByTagName("secteur");

    for(int i = 0; i < panels->count(); i++)
    {
        sectName = secteurs->at(i)->getNom();
        for(int j=i;j<primusNodeList.count(); j++){
            if(primusNodeList.at(j).toElement().attribute("type") == sectName)
            {

                QString time(primusNodeList.at(j).toElement().attribute("time"));
                if(!(time == ""))
                {

                    parent->getSectbyName(sectName)->setLastEditEpoch(time);
                }
                //Béquille après modif des chambres
                //findRooms(panels->at(j),primusNodeList.at(j));
                for(int k = 0; k < panels->count(); k++)
                    findRooms(panels->at(j),primusNodeList.at(k));
                break;
            }
        }
    }
}

void LectureXML::findRooms(QList<ChambrePanel*>* panels, QDomNode rootNode)
{
    QDomNodeList chambreNodesList = rootNode.toElement().elementsByTagName("chambre");
    QString chName;
    for(int i=0 ; i<panels->count();i++)
    {
        chName = panels->at(i)->objectName();
        //béquille
        //for(int j=i; j<chambreNodesList.count();j++)
        for(int j=0; j<chambreNodesList.count();j++)
        {
            if(chambreNodesList.at(j).toElement().attribute("id") == chName)
            {
                fillRoom(panels->at(i),chambreNodesList.at(j));
                panels->at(i)->dureeSejourUpdate();
                break;
            }
        }
    }
}

void LectureXML::fillRoom(ChambrePanel* cp, QDomNode baseNode)
{
    cp->setNomText(getTextValue("nom",baseNode));
    cp->setDate(getTextValue("dateEntree",baseNode));
    cp->setMotifEntreeText(getTextValue("motif",baseNode));
    cp->setAtcdText(getTextValue("atcd",baseNode));
    cp->setExamText(getTextValue("exams",baseNode));
    cp->setSondeVesCheck(getTextValue("issv",baseNode));
    cp->setSondeVesCombo(getTextValue("svtype",baseNode));
    cp->setSvMainText(getTextValue("svmain",baseNode));
    cp->setSvSubText(getTextValue("svsub",baseNode));
    cp->setSortieMainText(getTextValue("sortiemain",baseNode));
    cp->setSortieSubText(getTextValue("sortiesub",baseNode));
    cp->setMisc(getTextValue("misc",baseNode));
    cp->setReaText(getTextValue("reaMain",baseNode));
    cp->setReaBigText(getTextValue("reasub",baseNode));
    cp->setPerosText(getTextValue("peros",baseNode));
    cp->setReaChecked(getTextValue("reaset",baseNode));
    cp->setOxyCheck(getTextValue("o2check",baseNode));
    cp->setOxyDeb(getTextValue("oxydeb",baseNode));
    cp->setAerosolsCheck(getTextValue("aerosols",baseNode));
    cp->setAllergiesCheck(getTextValue("allergiesCheck",baseNode));
    cp->setAllergiesText(getTextValue("allergies",baseNode));
    cp->setPansementsCheck(getTextValue("exams",baseNode).contains(QRegularExpression("p|Psmt")));

    //Mise en forme du panel, activation / désactivation des zones
    cp->switchActiveInterfaceParts();
}

QString LectureXML::getTextValue(QString val, QDomNode chambre)
{
    return chambre.firstChildElement(val).childNodes().at(0).toText().nodeValue();
}

void LectureXML::setParent(GestionTabWidget *par)
{
    this->parent = par;
}
