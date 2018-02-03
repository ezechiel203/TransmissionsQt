/********************************************************************************
** Form generated from reading UI file 'chambrepanel.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAMBREPANEL_H
#define UI_CHAMBREPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include "qlabeldate.h"
#include "qmainallergiestextedit.h"
#include "qmainatcdtextedit.h"
#include "qmaintextedit.h"
#include "qmisctextedit.h"
#include "qnomlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_ChambrePanel
{
public:
    QGridLayout *gridLayout_3;
    QFrame *frame_4;
    QGridLayout *gridLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *boutonCalendrier;
    QPushButton *boutonToday;
    QHBoxLayout *horizontalLayout_3;
    QLabelDate *dateEntree;
    QPushButton *razDate;
    QHBoxLayout *horizontalLayout_5;
    QLabel *dureeSejourLabel;
    QLabel *dureeSejour;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout;
    QCheckBox *AerosolsCheck;
    QComboBox *sondeVesCombo;
    QCheckBox *reaCheck;
    QCheckBox *OxyCheck;
    QCheckBox *sondeVesCheck;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *oxyDeb;
    QLabel *label_2;
    QMainAllergiesTextEdit *allergiesText;
    QMainTextEdit *reaText;
    QCheckBox *allergiesCheck;
    QCheckBox *pansementsCheck;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *resetChambrePanel;
    QLabel *titre;
    QMiscTextEdit *misc;
    QFrame *frame_3;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_6;
    QMainTextEdit *motifEntreeText;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QMainAtcdTextEdit *atcdText;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_2;
    QMainTextEdit *reaBigText;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QMainTextEdit *examText;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_8;
    QMainTextEdit *perosText;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_7;
    QMainTextEdit *sortieMainText;
    QMainTextEdit *sortieSubText;
    QGroupBox *groupBox_7;
    QGridLayout *_2;
    QMainTextEdit *svSubText;
    QMainTextEdit *svMainText;
    QSpacerItem *verticalSpacer;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBoxNom;
    QVBoxLayout *verticalLayout_3;
    QNomLineEdit *nomText;

    void setupUi(QFrame *ChambrePanel)
    {
        if (ChambrePanel->objectName().isEmpty())
            ChambrePanel->setObjectName(QStringLiteral("ChambrePanel"));
        ChambrePanel->resize(875, 536);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ChambrePanel->sizePolicy().hasHeightForWidth());
        ChambrePanel->setSizePolicy(sizePolicy);
        ChambrePanel->setMinimumSize(QSize(875, 0));
        ChambrePanel->setAutoFillBackground(true);
        ChambrePanel->setFrameShape(QFrame::NoFrame);
        ChambrePanel->setFrameShadow(QFrame::Raised);
        ChambrePanel->setLineWidth(0);
        gridLayout_3 = new QGridLayout(ChambrePanel);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        frame_4 = new QFrame(ChambrePanel);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        frame_4->setMaximumSize(QSize(300, 107));
        QPalette palette;
        QBrush brush(QColor(255, 225, 225, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        frame_4->setPalette(palette);
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Sunken);
        gridLayout_7 = new QGridLayout(frame_4);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        boutonCalendrier = new QToolButton(frame_4);
        boutonCalendrier->setObjectName(QStringLiteral("boutonCalendrier"));
        sizePolicy.setHeightForWidth(boutonCalendrier->sizePolicy().hasHeightForWidth());
        boutonCalendrier->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/cal"), QSize(), QIcon::Normal, QIcon::Off);
        boutonCalendrier->setIcon(icon);
        boutonCalendrier->setIconSize(QSize(24, 24));
        boutonCalendrier->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_4->addWidget(boutonCalendrier);

        boutonToday = new QPushButton(frame_4);
        boutonToday->setObjectName(QStringLiteral("boutonToday"));
        sizePolicy.setHeightForWidth(boutonToday->sizePolicy().hasHeightForWidth());
        boutonToday->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(boutonToday);

        horizontalLayout_4->setStretch(0, 8);
        horizontalLayout_4->setStretch(1, 6);

        gridLayout_7->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        dateEntree = new QLabelDate(frame_4);
        dateEntree->setObjectName(QStringLiteral("dateEntree"));
        sizePolicy.setHeightForWidth(dateEntree->sizePolicy().hasHeightForWidth());
        dateEntree->setSizePolicy(sizePolicy);
        dateEntree->setMinimumSize(QSize(100, 23));
        dateEntree->setContextMenuPolicy(Qt::NoContextMenu);
        dateEntree->setStyleSheet(QLatin1String(" border: #ECECEC;\n"
" border-top-left-radius: 4px;\n"
" border-bottom-left-radius: 4px;\n"
"background: #FFFFFF;\n"
"padding: 5px;"));

        horizontalLayout_3->addWidget(dateEntree);

        razDate = new QPushButton(frame_4);
        razDate->setObjectName(QStringLiteral("razDate"));
        razDate->setMinimumSize(QSize(25, 23));
        razDate->setCursor(QCursor(Qt::ArrowCursor));
        razDate->setStyleSheet(QLatin1String("QPushButton{\n"
"border-top-right-radius : 4px;\n"
"border-bottom-right-radius : 4px;\n"
"background-color: #fdfdfd;\n"
"border-left : 1px dotted #acacac;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: #ffffff;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/remove"), QSize(), QIcon::Normal, QIcon::Off);
        razDate->setIcon(icon1);
        razDate->setIconSize(QSize(10, 10));

        horizontalLayout_3->addWidget(razDate);


        gridLayout_7->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        dureeSejourLabel = new QLabel(frame_4);
        dureeSejourLabel->setObjectName(QStringLiteral("dureeSejourLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dureeSejourLabel->sizePolicy().hasHeightForWidth());
        dureeSejourLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_5->addWidget(dureeSejourLabel);

        dureeSejour = new QLabel(frame_4);
        dureeSejour->setObjectName(QStringLiteral("dureeSejour"));
        sizePolicy2.setHeightForWidth(dureeSejour->sizePolicy().hasHeightForWidth());
        dureeSejour->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        dureeSejour->setFont(font);

        horizontalLayout_5->addWidget(dureeSejour);


        gridLayout_7->addLayout(horizontalLayout_5, 2, 0, 1, 1);


        gridLayout_3->addWidget(frame_4, 2, 0, 1, 1);

        frame_2 = new QFrame(ChambrePanel);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy3);
        frame_2->setMaximumSize(QSize(300, 16777215));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Sunken);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        gridLayout->setContentsMargins(10, 10, 10, 10);
        AerosolsCheck = new QCheckBox(frame_2);
        AerosolsCheck->setObjectName(QStringLiteral("AerosolsCheck"));

        gridLayout->addWidget(AerosolsCheck, 3, 0, 1, 1);

        sondeVesCombo = new QComboBox(frame_2);
        sondeVesCombo->setObjectName(QStringLiteral("sondeVesCombo"));
        sondeVesCombo->setEnabled(false);
        sondeVesCombo->setFrame(false);

        gridLayout->addWidget(sondeVesCombo, 0, 1, 1, 1);

        reaCheck = new QCheckBox(frame_2);
        reaCheck->setObjectName(QStringLiteral("reaCheck"));

        gridLayout->addWidget(reaCheck, 1, 0, 1, 1);

        OxyCheck = new QCheckBox(frame_2);
        OxyCheck->setObjectName(QStringLiteral("OxyCheck"));

        gridLayout->addWidget(OxyCheck, 2, 0, 1, 1);

        sondeVesCheck = new QCheckBox(frame_2);
        sondeVesCheck->setObjectName(QStringLiteral("sondeVesCheck"));

        gridLayout->addWidget(sondeVesCheck, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        oxyDeb = new QDoubleSpinBox(frame_2);
        oxyDeb->setObjectName(QStringLiteral("oxyDeb"));
        oxyDeb->setEnabled(false);
        oxyDeb->setMinimumSize(QSize(0, 0));
        oxyDeb->setMaximumSize(QSize(38, 16777215));
        oxyDeb->setCursor(QCursor(Qt::ArrowCursor));
        oxyDeb->setAutoFillBackground(false);
        oxyDeb->setWrapping(false);
        oxyDeb->setFrame(false);
        oxyDeb->setReadOnly(false);
        oxyDeb->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        oxyDeb->setAccelerated(true);
        oxyDeb->setProperty("showGroupSeparator", QVariant(false));
        oxyDeb->setDecimals(1);
        oxyDeb->setMaximum(15);

        horizontalLayout->addWidget(oxyDeb, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        allergiesText = new QMainAllergiesTextEdit(frame_2);
        allergiesText->setObjectName(QStringLiteral("allergiesText"));
        allergiesText->setEnabled(false);
        allergiesText->setMinimumSize(QSize(0, 0));
        allergiesText->setMaximumSize(QSize(16777215, 40));
        allergiesText->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(allergiesText, 7, 0, 1, 2);

        reaText = new QMainTextEdit(frame_2);
        reaText->setObjectName(QStringLiteral("reaText"));
        reaText->setEnabled(false);
        reaText->setMaximumSize(QSize(16777215, 20));
        reaText->setFrameShape(QFrame::NoFrame);
        reaText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        reaText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        reaText->setLineWrapMode(QTextEdit::NoWrap);

        gridLayout->addWidget(reaText, 1, 1, 1, 1);

        allergiesCheck = new QCheckBox(frame_2);
        allergiesCheck->setObjectName(QStringLiteral("allergiesCheck"));
        allergiesCheck->setCheckable(true);

        gridLayout->addWidget(allergiesCheck, 5, 0, 1, 1);

        pansementsCheck = new QCheckBox(frame_2);
        pansementsCheck->setObjectName(QStringLiteral("pansementsCheck"));

        gridLayout->addWidget(pansementsCheck, 4, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_2, 3, 0, 1, 1);

        frame = new QFrame(ChambrePanel);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy3.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy3);
        frame->setMaximumSize(QSize(300, 16777215));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        resetChambrePanel = new QPushButton(frame);
        resetChambrePanel->setObjectName(QStringLiteral("resetChambrePanel"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(resetChambrePanel->sizePolicy().hasHeightForWidth());
        resetChambrePanel->setSizePolicy(sizePolicy4);
        resetChambrePanel->setMaximumSize(QSize(300, 70));
        resetChambrePanel->setLayoutDirection(Qt::LeftToRight);
        resetChambrePanel->setAutoFillBackground(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/open_door"), QSize(), QIcon::Normal, QIcon::Off);
        resetChambrePanel->setIcon(icon2);
        resetChambrePanel->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(resetChambrePanel);

        titre = new QLabel(frame);
        titre->setObjectName(QStringLiteral("titre"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferAntialias);
        titre->setFont(font1);
        titre->setScaledContents(false);

        verticalLayout->addWidget(titre);

        misc = new QMiscTextEdit(frame);
        misc->setObjectName(QStringLiteral("misc"));
        misc->setMinimumSize(QSize(230, 0));
        misc->setContextMenuPolicy(Qt::DefaultContextMenu);
        misc->setStyleSheet(QStringLiteral(""));
        misc->setFrameShape(QFrame::NoFrame);
        misc->setFrameShadow(QFrame::Plain);
        misc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        misc->setLineWrapMode(QTextEdit::FixedColumnWidth);
        misc->setLineWrapColumnOrWidth(30);
        misc->setAcceptRichText(false);

        verticalLayout->addWidget(misc);


        gridLayout_3->addWidget(frame, 0, 0, 2, 1);

        frame_3 = new QFrame(ChambrePanel);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy3.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy3);
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Sunken);
        gridLayout_5 = new QGridLayout(frame_3);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setHorizontalSpacing(10);
        gridLayout_5->setVerticalSpacing(3);
        gridLayout_5->setContentsMargins(-1, 4, -1, -1);
        groupBox_4 = new QGroupBox(frame_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        groupBox_4->setStyleSheet(QStringLiteral(""));
        groupBox_4->setFlat(true);
        verticalLayout_6 = new QVBoxLayout(groupBox_4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        motifEntreeText = new QMainTextEdit(groupBox_4);
        motifEntreeText->setObjectName(QStringLiteral("motifEntreeText"));
        sizePolicy.setHeightForWidth(motifEntreeText->sizePolicy().hasHeightForWidth());
        motifEntreeText->setSizePolicy(sizePolicy);
        motifEntreeText->setMinimumSize(QSize(270, 0));
        motifEntreeText->setMaximumSize(QSize(16777215, 16777215));
        motifEntreeText->setContextMenuPolicy(Qt::DefaultContextMenu);
        motifEntreeText->setAutoFillBackground(false);
        motifEntreeText->setStyleSheet(QStringLiteral(""));
        motifEntreeText->setFrameShape(QFrame::NoFrame);
        motifEntreeText->setLineWrapMode(QTextEdit::WidgetWidth);

        verticalLayout_6->addWidget(motifEntreeText, 0, Qt::AlignTop);


        gridLayout_5->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(frame_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFlat(true);
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        atcdText = new QMainAtcdTextEdit(groupBox_2);
        atcdText->setObjectName(QStringLiteral("atcdText"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(atcdText->sizePolicy().hasHeightForWidth());
        atcdText->setSizePolicy(sizePolicy5);
        atcdText->setMaximumSize(QSize(16777215, 16777215));
        atcdText->setContextMenuPolicy(Qt::DefaultContextMenu);
        atcdText->setStyleSheet(QStringLiteral(""));
        atcdText->setFrameShape(QFrame::NoFrame);

        verticalLayout_4->addWidget(atcdText);


        gridLayout_5->addWidget(groupBox_2, 3, 0, 1, 1);

        groupBox_5 = new QGroupBox(frame_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        reaBigText = new QMainTextEdit(groupBox_5);
        reaBigText->setObjectName(QStringLiteral("reaBigText"));
        sizePolicy.setHeightForWidth(reaBigText->sizePolicy().hasHeightForWidth());
        reaBigText->setSizePolicy(sizePolicy);
        reaBigText->setMaximumSize(QSize(16777215, 16777215));
        reaBigText->setContextMenuPolicy(Qt::DefaultContextMenu);
        reaBigText->setStyleSheet(QStringLiteral(""));
        reaBigText->setFrameShape(QFrame::NoFrame);

        horizontalLayout_2->addWidget(reaBigText);


        gridLayout_5->addWidget(groupBox_5, 3, 1, 1, 1);

        groupBox_3 = new QGroupBox(frame_3);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setFlat(true);
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        examText = new QMainTextEdit(groupBox_3);
        examText->setObjectName(QStringLiteral("examText"));
        sizePolicy.setHeightForWidth(examText->sizePolicy().hasHeightForWidth());
        examText->setSizePolicy(sizePolicy);
        examText->setMaximumSize(QSize(16777215, 16777215));
        examText->setContextMenuPolicy(Qt::DefaultContextMenu);
        examText->setStyleSheet(QStringLiteral(""));
        examText->setFrameShape(QFrame::NoFrame);

        verticalLayout_5->addWidget(examText);


        gridLayout_5->addWidget(groupBox_3, 4, 0, 1, 1);

        groupBox_6 = new QGroupBox(frame_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setFlat(true);
        verticalLayout_8 = new QVBoxLayout(groupBox_6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        perosText = new QMainTextEdit(groupBox_6);
        perosText->setObjectName(QStringLiteral("perosText"));
        sizePolicy.setHeightForWidth(perosText->sizePolicy().hasHeightForWidth());
        perosText->setSizePolicy(sizePolicy);
        perosText->setMaximumSize(QSize(16777215, 16777215));
        perosText->setContextMenuPolicy(Qt::DefaultContextMenu);
        perosText->setStyleSheet(QStringLiteral(""));
        perosText->setFrameShape(QFrame::NoFrame);

        verticalLayout_8->addWidget(perosText);


        gridLayout_5->addWidget(groupBox_6, 4, 1, 1, 1);

        groupBox_8 = new QGroupBox(frame_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setFlat(true);
        verticalLayout_7 = new QVBoxLayout(groupBox_8);
        verticalLayout_7->setSpacing(3);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        sortieMainText = new QMainTextEdit(groupBox_8);
        sortieMainText->setObjectName(QStringLiteral("sortieMainText"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(sortieMainText->sizePolicy().hasHeightForWidth());
        sortieMainText->setSizePolicy(sizePolicy6);
        sortieMainText->setMaximumSize(QSize(16777215, 20));
        sortieMainText->setContextMenuPolicy(Qt::DefaultContextMenu);
        sortieMainText->setFrameShape(QFrame::NoFrame);
        sortieMainText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sortieMainText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        sortieMainText->setLineWrapMode(QTextEdit::NoWrap);

        verticalLayout_7->addWidget(sortieMainText);

        sortieSubText = new QMainTextEdit(groupBox_8);
        sortieSubText->setObjectName(QStringLiteral("sortieSubText"));
        sizePolicy.setHeightForWidth(sortieSubText->sizePolicy().hasHeightForWidth());
        sortieSubText->setSizePolicy(sizePolicy);
        sortieSubText->setMinimumSize(QSize(0, 30));
        sortieSubText->setMaximumSize(QSize(16777215, 16777215));
        sortieSubText->setContextMenuPolicy(Qt::DefaultContextMenu);
        sortieSubText->setStyleSheet(QStringLiteral(""));
        sortieSubText->setFrameShape(QFrame::NoFrame);

        verticalLayout_7->addWidget(sortieSubText);


        gridLayout_5->addWidget(groupBox_8, 5, 1, 1, 1);

        groupBox_7 = new QGroupBox(frame_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setFlat(true);
        _2 = new QGridLayout(groupBox_7);
        _2->setObjectName(QStringLiteral("_2"));
        _2->setVerticalSpacing(3);
        _2->setContentsMargins(0, 0, 0, 0);
        svSubText = new QMainTextEdit(groupBox_7);
        svSubText->setObjectName(QStringLiteral("svSubText"));
        sizePolicy.setHeightForWidth(svSubText->sizePolicy().hasHeightForWidth());
        svSubText->setSizePolicy(sizePolicy);
        svSubText->setMinimumSize(QSize(0, 30));
        svSubText->setMaximumSize(QSize(16777215, 16777215));
        svSubText->setContextMenuPolicy(Qt::DefaultContextMenu);
        svSubText->setStyleSheet(QStringLiteral(""));
        svSubText->setFrameShape(QFrame::NoFrame);

        _2->addWidget(svSubText, 1, 0, 1, 1);

        svMainText = new QMainTextEdit(groupBox_7);
        svMainText->setObjectName(QStringLiteral("svMainText"));
        sizePolicy6.setHeightForWidth(svMainText->sizePolicy().hasHeightForWidth());
        svMainText->setSizePolicy(sizePolicy6);
        svMainText->setMaximumSize(QSize(16777215, 20));
        svMainText->setContextMenuPolicy(Qt::DefaultContextMenu);
        svMainText->setFrameShape(QFrame::NoFrame);
        svMainText->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        svMainText->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        svMainText->setLineWrapMode(QTextEdit::NoWrap);

        _2->addWidget(svMainText, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_7, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer, 2, 0, 1, 1);

        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        sizePolicy3.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy3);
        frame_5->setFrameShape(QFrame::NoFrame);
        frame_5->setFrameShadow(QFrame::Plain);
        verticalLayout_9 = new QVBoxLayout(frame_5);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        groupBoxNom = new QGroupBox(frame_5);
        groupBoxNom->setObjectName(QStringLiteral("groupBoxNom"));
        sizePolicy5.setHeightForWidth(groupBoxNom->sizePolicy().hasHeightForWidth());
        groupBoxNom->setSizePolicy(sizePolicy5);
        QFont font2;
        font2.setStyleStrategy(QFont::PreferDefault);
        groupBoxNom->setFont(font2);
        groupBoxNom->setStyleSheet(QStringLiteral(""));
        groupBoxNom->setFlat(false);
        verticalLayout_3 = new QVBoxLayout(groupBoxNom);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        nomText = new QNomLineEdit(groupBoxNom);
        nomText->setObjectName(QStringLiteral("nomText"));
        sizePolicy6.setHeightForWidth(nomText->sizePolicy().hasHeightForWidth());
        nomText->setSizePolicy(sizePolicy6);
        nomText->setMinimumSize(QSize(270, 0));
        nomText->setMaximumSize(QSize(16777215, 16777215));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        nomText->setFont(font3);
        nomText->setStyleSheet(QStringLiteral(""));
        nomText->setMaxLength(29);
        nomText->setFrame(false);
        nomText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        nomText->setCursorMoveStyle(Qt::LogicalMoveStyle);
        nomText->setClearButtonEnabled(false);

        verticalLayout_3->addWidget(nomText);


        verticalLayout_9->addWidget(groupBoxNom);


        gridLayout_5->addWidget(frame_5, 0, 0, 2, 1);


        gridLayout_3->addWidget(frame_3, 0, 1, 4, 1);

        gridLayout_3->setRowStretch(0, 10);
        gridLayout_3->setColumnStretch(0, 10);
        QWidget::setTabOrder(misc, boutonCalendrier);
        QWidget::setTabOrder(boutonCalendrier, boutonToday);
        QWidget::setTabOrder(boutonToday, sondeVesCheck);
        QWidget::setTabOrder(sondeVesCheck, sondeVesCombo);
        QWidget::setTabOrder(sondeVesCombo, reaCheck);
        QWidget::setTabOrder(reaCheck, reaText);
        QWidget::setTabOrder(reaText, OxyCheck);
        QWidget::setTabOrder(OxyCheck, oxyDeb);
        QWidget::setTabOrder(oxyDeb, AerosolsCheck);
        QWidget::setTabOrder(AerosolsCheck, allergiesCheck);
        QWidget::setTabOrder(allergiesCheck, allergiesText);
        QWidget::setTabOrder(allergiesText, nomText);
        QWidget::setTabOrder(nomText, motifEntreeText);
        QWidget::setTabOrder(motifEntreeText, atcdText);
        QWidget::setTabOrder(atcdText, reaBigText);
        QWidget::setTabOrder(reaBigText, examText);
        QWidget::setTabOrder(examText, perosText);
        QWidget::setTabOrder(perosText, svMainText);
        QWidget::setTabOrder(svMainText, svSubText);
        QWidget::setTabOrder(svSubText, sortieMainText);
        QWidget::setTabOrder(sortieMainText, sortieSubText);

        retranslateUi(ChambrePanel);

        QMetaObject::connectSlotsByName(ChambrePanel);
    } // setupUi

    void retranslateUi(QFrame *ChambrePanel)
    {
        ChambrePanel->setWindowTitle(QApplication::translate("ChambrePanel", "Frame", nullptr));
        boutonCalendrier->setText(QApplication::translate("ChambrePanel", "Date d'entr\303\251e", nullptr));
        boutonToday->setText(QApplication::translate("ChambrePanel", "Aujourd'hui", nullptr));
        dateEntree->setText(QString());
        razDate->setText(QString());
        dureeSejourLabel->setText(QApplication::translate("ChambrePanel", "S\303\251jour dans le service :", nullptr));
        dureeSejour->setText(QString());
        AerosolsCheck->setText(QApplication::translate("ChambrePanel", "A\303\251rosols", nullptr));
        reaCheck->setText(QApplication::translate("ChambrePanel", "R\303\251a", nullptr));
        OxyCheck->setText(QApplication::translate("ChambrePanel", "Oxyg\303\250ne", nullptr));
        sondeVesCheck->setText(QApplication::translate("ChambrePanel", "Sonde Ves", nullptr));
        oxyDeb->setPrefix(QString());
        label_2->setText(QApplication::translate("ChambrePanel", "L/min", nullptr));
        allergiesCheck->setText(QApplication::translate("ChambrePanel", "Allergies ", nullptr));
        pansementsCheck->setText(QApplication::translate("ChambrePanel", "Pansement", nullptr));
        resetChambrePanel->setText(QApplication::translate("ChambrePanel", "Sortie patient", nullptr));
        titre->setText(QApplication::translate("ChambrePanel", "Parent text", nullptr));
        groupBox_4->setTitle(QApplication::translate("ChambrePanel", "Motif d'entr\303\251e", nullptr));
        groupBox_2->setTitle(QApplication::translate("ChambrePanel", "Ant\303\251c\303\251dents", nullptr));
        groupBox_5->setTitle(QApplication::translate("ChambrePanel", "R\303\251a", nullptr));
        groupBox_3->setTitle(QApplication::translate("ChambrePanel", "Exams/Soins", nullptr));
        groupBox_6->setTitle(QApplication::translate("ChambrePanel", "Per Os", nullptr));
        groupBox_8->setTitle(QApplication::translate("ChambrePanel", "Sortie", nullptr));
        sortieMainText->setHtml(QApplication::translate("ChambrePanel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Sortie</span></p></body></html>", nullptr));
        groupBox_7->setTitle(QApplication::translate("ChambrePanel", "Sonde v\303\251sicale", nullptr));
        groupBoxNom->setTitle(QApplication::translate("ChambrePanel", "Nom", nullptr));
        nomText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChambrePanel: public Ui_ChambrePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAMBREPANEL_H
