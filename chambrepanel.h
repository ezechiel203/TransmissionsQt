#ifndef CHAMBREPANEL_H
#define CHAMBREPANEL_H

#include <QFrame>
#include "transmain.h"
#include "clearformdialog.h"
#include <QString>
#include <transtabwidget.h>
#include <QDate>
#include <QRegExp>



namespace Ui {
class ChambrePanel;
}

class TransDocument;

class ChambrePanel : public QFrame
{
    Q_OBJECT

public:
    explicit ChambrePanel(QString titre, GestionTabWidget* gestionnaire, Transmain* parent = 0, TransDocument* lengthChk = 0);
    ~ChambrePanel();


//GETTERS AND SETTERS
    GestionTabWidget* getParent();
    Transmain* getTransmain();
    QString getTitre();
    void setTitre(QString titre);
    QString getMisc();
    void setMisc(QString texte);
    bool getAerosolsCheck();
    void setAerosolsCheck(bool checked);
    void setAerosolsCheck(QString checked);
    bool getOxyCheck();
    void setOxyCheck(bool checked);
    void setOxyCheck(QString checked);
    void setPansementsCheck(bool checked);
    bool getPansementsCheck();
    bool getAllergiesCheck();
    void setAllergiesCheck(bool checked);
    void setAllergiesCheck(QString checked);
    bool getReaChecked();
    void setReaChecked(bool checked);
    void setReaChecked(QString checked);
    bool getSondeVesCheck();
    void setSondeVesCheck(bool checked);
    void setSondeVesCheck(QString checked);
    QString getOxyDeb();
    void setOxyDeb(double debit);
    void setOxyDeb(QString debit);
    QString getAllergiesText();
    void setAllergiesText(QString allergies);
    QString getReaText();
    void setReaText(QString rea);
    QString getSondeVesCombo();
    int getSondeVesComboIndex();
    void setSondeVesCombo(QString sondeVes);
    QString getNomText();
    void setNomText(QString nom);
    QString getAtcdText();
    void setAtcdText(QString atcd);
    QString getExamText();
    void setExamText(QString exam);
    QString getMotifEntreeText();
    void setMotifEntreeText(QString motifEntree);
    QString getReaBigText();
    void setReaBigText(QString reaBig);
    QString getPerosText();
    void setPerosText(QString peros);
    QString getSortieMainText();
    void setSortieMainText(QString text);
    QString getSortieSubText();
    void setSortieSubText(QString text);
    QString getSvMainText();
    void setSvMainText(QString text);
    QString getSvSubText();
    void setSvSubText(QString text);
    QString getDate();
    void setDate(QString date);
    void setRemainLetters(QString letters);
    void setDureeSejour(QString duree);
    QString getDureeSejour();
    TransTabWidget *getTabWidget();
//FIN GETTERS AND SETTERS

    void ClearForm();
    void connectToSaveButton();
    void disconnectFromSaveButton();
    void setParent(Transmain *parent);
    void connectInterfaceParts();
    void switchActiveInterfaceParts();
public slots:
    void showClearFormDialog();
    void clearFormDialogReturn(bool chk);
    void sondeVesChecked();
    void oxyChecked();
    void reaChecked();
    void aerosolChecked();
    void pansementsChecked();
    void allergiesChecked();
    void dureeSejourUpdate();
    void setNextTab();
    void setPrevTab();
    //MISE EN PAGE
    void miseEnPage();
    void toCaps();
    void dateEditReminder();

private:
    Ui::ChambrePanel *ui;
    Transmain *parent;
    ClearFormDialog* dlg;
    TransDocument* lengthChecker;
    TransTabWidget *tabWidget;

signals :
    void dateUpdate(QDate);
;
private slots:
    void oxyDebUpdated();
    void setDateToday();
    void eraseDate();
    void razDateToggle();

};

#endif // CHAMBREPANEL_H
