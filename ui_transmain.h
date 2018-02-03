/********************************************************************************
** Form generated from reading UI file 'transmain.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSMAIN_H
#define UI_TRANSMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "transtabwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Transmain
{
public:
    QAction *actionOuvrir;
    QAction *actionEnregistrer_Sous;
    QAction *actionEnregistrer;
    QAction *actionImprimer;
    QAction *actionFermer;
    QAction *actionA_propos;
    QAction *actionOptions;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    TransTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuSecteur;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *Transmain)
    {
        if (Transmain->objectName().isEmpty())
            Transmain->setObjectName(QStringLiteral("Transmain"));
        Transmain->setWindowModality(Qt::ApplicationModal);
        Transmain->resize(915, 675);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Transmain->sizePolicy().hasHeightForWidth());
        Transmain->setSizePolicy(sizePolicy);
        Transmain->setMinimumSize(QSize(915, 650));
        QPalette palette;
        QBrush brush(QColor(250, 250, 250, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(253, 253, 253, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        QBrush brush2(QColor(240, 240, 240, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        QBrush brush3(QColor(247, 247, 247, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        Transmain->setPalette(palette);
        Transmain->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/mainIcon"), QSize(), QIcon::Normal, QIcon::Off);
        Transmain->setWindowIcon(icon);
        Transmain->setWindowOpacity(1);
        Transmain->setDocumentMode(false);
        Transmain->setUnifiedTitleAndToolBarOnMac(true);
        actionOuvrir = new QAction(Transmain);
        actionOuvrir->setObjectName(QStringLiteral("actionOuvrir"));
        actionEnregistrer_Sous = new QAction(Transmain);
        actionEnregistrer_Sous->setObjectName(QStringLiteral("actionEnregistrer_Sous"));
        actionEnregistrer = new QAction(Transmain);
        actionEnregistrer->setObjectName(QStringLiteral("actionEnregistrer"));
        actionEnregistrer->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/saveIcon"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrer->setIcon(icon1);
        actionImprimer = new QAction(Transmain);
        actionImprimer->setObjectName(QStringLiteral("actionImprimer"));
        actionFermer = new QAction(Transmain);
        actionFermer->setObjectName(QStringLiteral("actionFermer"));
        actionA_propos = new QAction(Transmain);
        actionA_propos->setObjectName(QStringLiteral("actionA_propos"));
        actionOptions = new QAction(Transmain);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        centralWidget = new QWidget(Transmain);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        tabWidget = new TransTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(831, 531));
        tabWidget->setFocusPolicy(Qt::StrongFocus);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        Transmain->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Transmain);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 915, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuSecteur = new QMenu(menuBar);
        menuSecteur->setObjectName(QStringLiteral("menuSecteur"));
        Transmain->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Transmain);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy1);
        mainToolBar->setMinimumSize(QSize(0, 0));
        mainToolBar->setFocusPolicy(Qt::NoFocus);
        mainToolBar->setContextMenuPolicy(Qt::PreventContextMenu);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::NoToolBarArea);
        mainToolBar->setIconSize(QSize(32, 32));
        mainToolBar->setFloatable(false);
        Transmain->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuSecteur->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrer);
        menuFichier->addAction(actionEnregistrer_Sous);
        menuFichier->addAction(actionImprimer);
        menuFichier->addAction(actionFermer);
        mainToolBar->addAction(actionEnregistrer);

        retranslateUi(Transmain);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Transmain);
    } // setupUi

    void retranslateUi(QMainWindow *Transmain)
    {
        Transmain->setWindowTitle(QString());
        actionOuvrir->setText(QApplication::translate("Transmain", "Ouvrir", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOuvrir->setShortcut(QApplication::translate("Transmain", "Ctrl+Shift+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionEnregistrer_Sous->setText(QApplication::translate("Transmain", "Enregistrer Sous", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEnregistrer_Sous->setShortcut(QApplication::translate("Transmain", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionEnregistrer->setText(QApplication::translate("Transmain", "Enregistrer", nullptr));
#ifndef QT_NO_SHORTCUT
        actionEnregistrer->setShortcut(QApplication::translate("Transmain", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionImprimer->setText(QApplication::translate("Transmain", "Imprimer", nullptr));
#ifndef QT_NO_SHORTCUT
        actionImprimer->setShortcut(QApplication::translate("Transmain", "Ctrl+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionFermer->setText(QApplication::translate("Transmain", "Fermer", nullptr));
#ifndef QT_NO_SHORTCUT
        actionFermer->setShortcut(QApplication::translate("Transmain", "Shift+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionA_propos->setText(QApplication::translate("Transmain", "A propos", nullptr));
        actionOptions->setText(QApplication::translate("Transmain", "Options", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Transmain", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Transmain", "Tab 2", nullptr));
        menuFichier->setTitle(QApplication::translate("Transmain", "Fichier", nullptr));
        menuSecteur->setTitle(QApplication::translate("Transmain", "Secteur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transmain: public Ui_Transmain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSMAIN_H
