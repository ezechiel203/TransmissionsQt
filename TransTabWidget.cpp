#include "transtabwidget.h"
#include "chambrepanel.h"
#include <QStatusBar>

TransTabWidget::TransTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    this->parent = dynamic_cast<Transmain*>(parent);
    this->buttonEventDispatcher();




    connect(this,SIGNAL(currentChanged(int)),this,SLOT(updateOnClick(int)));

}

void TransTabWidget::setNextIndex()
{
    int index = this->currentIndex();
    int tabs = this->count()-1; //Retranche 1 pour partir du Tab 0

    if(index < tabs){
        index++;
        this->setCurrentIndexWithUpdate(index);
    }
}

void TransTabWidget::setPreviousIndex()
{
    int index = this->currentIndex();

    if(index > 0){
        index--;
        this->setCurrentIndexWithUpdate(index);
    }
}

void TransTabWidget::setFirst()
{
    this->setCurrentIndexWithUpdate(0);
}

void TransTabWidget::setLast()
{
    this->setCurrentIndexWithUpdate(this->count()-1);
}

void TransTabWidget::addNewTab(QString titre){
    ChambrePanel* contenu = new ChambrePanel(titre, parent->getGestionnaire(), parent,0);

    this->addTab(contenu, titre);
    contenu->setTitre(titre);
    this->buttonEventDispatcher();
}

void TransTabWidget::updateOnClick(int){
    this->buttonEventDispatcher();
}

void TransTabWidget::buttonEventDispatcher(){
    if (this->count() == 1){
        emit firstIndexReached(false);
        emit lastIndexReached(false);
    }
    else if (this->currentIndex() == 0){
        emit firstIndexReached(false);
        emit lastIndexReached(true);
    }
    else if (this->currentIndex() == this->count()-1){
        emit lastIndexReached(false);
        emit firstIndexReached(true);
    }
    else{
        emit firstIndexReached(true);
        emit lastIndexReached(true);
    }
}

void TransTabWidget::setCurrentIndexWithUpdate(int index){
    this->setCurrentIndex(index);
    emit this->currentIndexChanged(index);
    this->buttonEventDispatcher();
}
