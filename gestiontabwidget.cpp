#include <gestiontabwidget.h>
#include <secteur.h>
#include <QList>
#include <QColor>
#include <QStringList>
#include <QDebug>
#include <QElapsedTimer>
#include <transdocument.h>
#include <QDate>
#include <QDebug>


GestionTabWidget::GestionTabWidget(TransTabWidget *tabWid, Transmain *parent) : QObject()
{
    //gestion centralisée des marges et polices pour les documents imprimés; Lit le fichier config.trs
    font = "";
    if(!readOpts())
    {
        left = -1;
        top = -1;
        right = -1;
        bottom = -1;
        font = "Times New Roman";
        fontSize = -1;
    }

    //##############################################
    QElapsedTimer timer;
    timer.start();
    this->setParent(parent);
    this->tabWidget = tabWid;
    this->sect = new QList<Secteur*>;
    this->initSect();
    TransDocument *lengthChecker = new TransDocument(this, (ChambrePanel*) nullptr);


    for(int i=0; i<sect->count();i++){
        this->ChambrePanelSecteurList << new QList<ChambrePanel*>;
    }

    for(int i=0; i<this->ChambrePanelSecteurList.count(); i++){
        for(int j=0; j<sect->at(i)->getChambres().count(); j++){
            QString titre;
            titre.append("Chambre ");
            QString suffixeChambre(sect->at(i)->getChambres().at(j));
            titre.append(suffixeChambre);
            ChambrePanelSecteurList.at(i)->append(new ChambrePanel(titre,this, parent,lengthChecker));
            ChambrePanelSecteurList.at(i)->last()->setObjectName(suffixeChambre);
        }
    }

    this->setCote(sect->at(0));

    this->datelastUpdateBed = QDate::currentDate();


}

void GestionTabWidget::setSecteurTabs(Secteur* s)
{
    this->tabWidget->clear();
    int i = this->getSect()->indexOf(s);
    for(int j=0 ; j<ChambrePanelSecteurList.at(i)->count(); j++)
    {
        this->tabWidget->addTab(ChambrePanelSecteurList.at(i)->at(j), ChambrePanelSecteurList.at(i)->at(j)->getTitre());
    }
    this->setCote(this->getSect()->at(i));

    tabWidget->setCurrentIndexWithUpdate(0);

}

Secteur* GestionTabWidget::getCote(){
    return this->cote;
}

void GestionTabWidget::cycleCote(){
    int i = this->getSect()->indexOf(this->getCote());
    int j = sect->count()-1;
    if(i == j)
        i = 0;
    else
        i++;
    this->setCote(this->getSect()->at(i));
    this->setSecteurTabs(this->getCote());
    this->tabWidget->buttonEventDispatcher();
}

void GestionTabWidget::changeCote(){
    if(this->getCote()->getNom() != this->getSectbyName(this->sender()->objectName())->getNom())
    {
        this->setSecteurTabs(this->getSectbyName(this->sender()->objectName()));
        this->tabWidget->buttonEventDispatcher();
    }
}

void GestionTabWidget::changeCoteInt(int i){
    if(this->getCote()->getNom() != this->getSect()->at(i)->getNom())
    {
        this->setSecteurTabs(this->getSect()->at(i));
        this->tabWidget->buttonEventDispatcher();
    }
}

Secteur* GestionTabWidget::getSectbyName(QString sectName)
{
    for(int i=0; i<this->getSect()->count(); i++){
        if(this->getSect()->at(i)->getNom() == sectName)
            return this->getSect()->at(i);
    }
    return this->getCote();
}

QList<Secteur*>* GestionTabWidget::getSect(){
    return sect;
}

void GestionTabWidget::setCote(Secteur* s)
{
    this->cote = s;
}

void GestionTabWidget::initSect(){
    QStringList ailes, chbleu, chrouge;//, chvert;
    ailes << "bleu" << "rouge";// << "vert";
    QList<QStringList> Chambres;
    chbleu << "8" << "9P" << "9F" << "10" << "11P" << "11F" << "12"  << "14" << "16" << "18" << "20";
    chrouge << "1P" << "1F" << "2" << "3P" << "3F" << "4" << "5P" << "5F" << "6" << "7P" << "7F";
    //chvert << "21P" << "21F" << "22" << "23P" << "23F" << "24"  << "26" << "28" << "29" << "30";
    //chvert << "2" << "3P" << "3F" << "4" << "5P" << "5F" << "6" << "7P" << "7F" << "8";
    Chambres << chbleu << chrouge ;//<< chvert;
    QList<QColor> backgroundColors, fontColors;
    backgroundColors << QColor("#03A9F4") << QColor("#F44336") ;//<< QColor("#7AE880");
    fontColors << QColor(0,102,255) << QColor(204,0,0) ;//<< QColor("#09C614");
    for (int i=0; i<ailes.count();i++){
        *sect << new Secteur(ailes.at(i), Chambres.at(i), backgroundColors.at(i), fontColors.at(i),i);
    }
}

void GestionTabWidget::setParent(Transmain *parent)
{
    this->parent = parent;
}

QList<ChambrePanel *> *GestionTabWidget::getPanelFromSecteur(Secteur* sect)
{
    return ChambrePanelSecteurList.at(this->sect->indexOf(sect));
}

QList<QList<ChambrePanel *> *> *GestionTabWidget::getPanels()
{
    return &this->ChambrePanelSecteurList;
}

//Mise à jour temps passé dans lit
void GestionTabWidget::updateTimeInBeds()
{
    QDate dateNow = QDate::currentDate();
    if(dateNow != this->datelastUpdateBed){
        qDebug() << "Ok, la date a changé";
        qDebug() << "oldDate " << this->datelastUpdateBed.toString();
        qDebug() << "NewDate : " << (dateNow).toString();
        for(int i=0; i<this->ChambrePanelSecteurList.count(); i++){
            for(int j=0; j<ChambrePanelSecteurList.at(i)->count(); j++){
                auto* chambre = ChambrePanelSecteurList.at(i)->at(j);
                chambre->dureeSejourUpdate();
            }
        }
        this->datelastUpdateBed = dateNow;
    }
}

//Lit le fichier d'options et récupère les marges
bool GestionTabWidget::readOpts()
{
    int lefty = -1 , topy = -1 , righty = -1 , bottomy = -1, sizes = -1;
    QString fonts;
    QFile f("config.trs");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    else
    {
        QTextStream in(&f);
        while(!in.atEnd())
        {
            QString opts = in.readLine();
            if(opts.contains("LEFT", Qt::CaseSensitive)){
                QRegExp rxlen(".*(\\d+)");
                int pos = rxlen.indexIn(opts);
                if (pos > -1) {
                    lefty = rxlen.cap(1).toInt();
                }
            }
            if(opts.contains("TOP", Qt::CaseSensitive)){
                QRegExp rxlen(".*(\\d+)");
                int pos = rxlen.indexIn(opts);
                if (pos > -1) {
                    topy = rxlen.cap(1).toInt();
                }
            }
            if(opts.contains("RIGHT", Qt::CaseSensitive)){
                QRegExp rxlen(".*(\\d+)");
                int pos = rxlen.indexIn(opts);
                if (pos > -1) {
                    righty = rxlen.cap(1).toInt();
                }
            }
            if(opts.contains("BOTTOM", Qt::CaseSensitive)){
                QRegExp rxlen(".*(\\d+)");
                int pos = rxlen.indexIn(opts);
                if (pos > -1) {
                   bottomy = rxlen.cap(1).toInt();
                }
            }
            if(opts.contains("Font", Qt::CaseSensitive)){
                QRegExp rxlen("^Font = (.*)$");
                int pos = rxlen.indexIn(opts);
                if (pos > -1) {
                    fonts = rxlen.cap(1);
                }
            }
            if(opts.contains("SIZE", Qt::CaseSensitive)){
                QRegExp rxlen("^SIZE = (.*)$");
                int pos = rxlen.indexIn(opts);
                if (pos > -1) {
                    sizes = rxlen.cap(1).toInt();
                }
            }
        }
    }
    if(!(lefty >0 && topy >0 && righty > 0 && bottomy > 0 && sizes > 0))
    {
        return false;
    }

    left = lefty;
    top = topy;
    right = righty;
    bottom = bottomy;
    fontSize = sizes;

    if(fonts != "")
        font = fonts;
    return true;
}

QList<int>* GestionTabWidget::getMargins(bool *b)
{
    *b = true;
    QList<int>* liste = new QList<int>;

    if(left != -1)
        liste->append(left);
    else
        *b = false;
    if(right != -1)
        liste->append(top);
    else
        *b = false;
    if(top != -1)
        liste->append(right);
    else
        *b = false;
    if(bottom != -1)
        liste->append(bottom);
    else
        *b = false;
    return liste;
}

QString GestionTabWidget::getFont()
{
    return font;
}

void GestionTabWidget::setFont(QString ft)
{
    font = ft;
}

int GestionTabWidget::getFontSize()
{
    return fontSize;
}

void GestionTabWidget::setFontSize(int sz)
{
    fontSize = sz;
}

void GestionTabWidget::setMargins(int l, int t, int r, int b)
{
    left = l;
    top = t;
    right = r;
    bottom = b;
}

TransTabWidget* GestionTabWidget::getTabWidget(){
    return this->tabWidget;
}
