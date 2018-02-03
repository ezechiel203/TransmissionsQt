/********************************************************************************
** Form generated from reading UI file 'transprintmarginsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSPRINTMARGINSDIALOG_H
#define UI_TRANSPRINTMARGINSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "clickableqlabel.h"

QT_BEGIN_NAMESPACE

class Ui_TransPrintMarginsDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinT;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinL;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *spinR;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *spinB;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QFontComboBox *Fonts;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *fontSizeBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    ClickableQLabel *konami_label;
    QSpacerItem *horizontalSpacer;
    QPushButton *boutOK;
    QPushButton *boutAN;

    void setupUi(QDialog *TransPrintMarginsDialog)
    {
        if (TransPrintMarginsDialog->objectName().isEmpty())
            TransPrintMarginsDialog->setObjectName(QStringLiteral("TransPrintMarginsDialog"));
        TransPrintMarginsDialog->resize(299, 318);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransPrintMarginsDialog->sizePolicy().hasHeightForWidth());
        TransPrintMarginsDialog->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(TransPrintMarginsDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout_3->setContentsMargins(9, -1, -1, -1);
        groupBox = new QGroupBox(TransPrintMarginsDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(19, -1, 19, -1);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        spinT = new QSpinBox(groupBox);
        spinT->setObjectName(QStringLiteral("spinT"));
        sizePolicy.setHeightForWidth(spinT->sizePolicy().hasHeightForWidth());
        spinT->setSizePolicy(sizePolicy);
        spinT->setBaseSize(QSize(37, 0));
        spinT->setWrapping(true);
        spinT->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinT->setMaximum(20);

        verticalLayout->addWidget(spinT);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        spinL = new QSpinBox(groupBox);
        spinL->setObjectName(QStringLiteral("spinL"));
        spinL->setWrapping(true);
        spinL->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinL->setMaximum(20);

        horizontalLayout_2->addWidget(spinL);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        spinR = new QSpinBox(groupBox);
        spinR->setObjectName(QStringLiteral("spinR"));
        spinR->setWrapping(true);
        spinR->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinR->setMaximum(20);

        horizontalLayout->addWidget(spinR);


        gridLayout->addLayout(horizontalLayout, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_2->setContentsMargins(19, -1, 19, -1);
        spinB = new QSpinBox(groupBox);
        spinB->setObjectName(QStringLiteral("spinB"));
        sizePolicy.setHeightForWidth(spinB->sizePolicy().hasHeightForWidth());
        spinB->setSizePolicy(sizePolicy);
        spinB->setBaseSize(QSize(37, 0));
        spinB->setWrapping(true);
        spinB->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinB->setMaximum(20);

        verticalLayout_2->addWidget(spinB);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);


        gridLayout->addLayout(verticalLayout_2, 2, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(TransPrintMarginsDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 80));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        Fonts = new QFontComboBox(groupBox_2);
        Fonts->setObjectName(QStringLiteral("Fonts"));
        Fonts->setMinimumSize(QSize(0, 23));
        Fonts->setWritingSystem(QFontDatabase::Latin);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        Fonts->setCurrentFont(font);

        verticalLayout_4->addWidget(Fonts);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        fontSizeBox = new QSpinBox(groupBox_2);
        fontSizeBox->setObjectName(QStringLiteral("fontSizeBox"));
        fontSizeBox->setMinimumSize(QSize(0, 23));
        fontSizeBox->setWrapping(true);
        fontSizeBox->setMaximum(12);

        horizontalLayout_4->addWidget(fontSizeBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_4);


        verticalLayout_3->addWidget(groupBox_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, -1, -1, -1);
        konami_label = new ClickableQLabel(TransPrintMarginsDialog);
        konami_label->setObjectName(QStringLiteral("konami_label"));
        konami_label->setMinimumSize(QSize(70, 0));

        horizontalLayout_3->addWidget(konami_label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        boutOK = new QPushButton(TransPrintMarginsDialog);
        boutOK->setObjectName(QStringLiteral("boutOK"));
        sizePolicy.setHeightForWidth(boutOK->sizePolicy().hasHeightForWidth());
        boutOK->setSizePolicy(sizePolicy);
        boutOK->setMinimumSize(QSize(75, 25));

        horizontalLayout_3->addWidget(boutOK);

        boutAN = new QPushButton(TransPrintMarginsDialog);
        boutAN->setObjectName(QStringLiteral("boutAN"));
        sizePolicy.setHeightForWidth(boutAN->sizePolicy().hasHeightForWidth());
        boutAN->setSizePolicy(sizePolicy);
        boutAN->setMinimumSize(QSize(80, 25));

        horizontalLayout_3->addWidget(boutAN);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 4);
        verticalLayout_3->setStretch(2, 1);
        QWidget::setTabOrder(spinL, spinT);
        QWidget::setTabOrder(spinT, spinR);
        QWidget::setTabOrder(spinR, spinB);
        QWidget::setTabOrder(spinB, Fonts);
        QWidget::setTabOrder(Fonts, boutOK);
        QWidget::setTabOrder(boutOK, boutAN);

        retranslateUi(TransPrintMarginsDialog);

        QMetaObject::connectSlotsByName(TransPrintMarginsDialog);
    } // setupUi

    void retranslateUi(QDialog *TransPrintMarginsDialog)
    {
        TransPrintMarginsDialog->setWindowTitle(QApplication::translate("TransPrintMarginsDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("TransPrintMarginsDialog", "Marges (mm)", nullptr));
        label->setText(QApplication::translate("TransPrintMarginsDialog", "Haut", nullptr));
        label_2->setText(QApplication::translate("TransPrintMarginsDialog", "Gauche", nullptr));
        label_3->setText(QApplication::translate("TransPrintMarginsDialog", "Droite", nullptr));
        label_4->setText(QApplication::translate("TransPrintMarginsDialog", "Bas", nullptr));
        groupBox_2->setTitle(QApplication::translate("TransPrintMarginsDialog", "Police", nullptr));
        fontSizeBox->setPrefix(QApplication::translate("TransPrintMarginsDialog", "taille ", nullptr));
        konami_label->setText(QString());
        boutOK->setText(QApplication::translate("TransPrintMarginsDialog", "Ok", nullptr));
        boutAN->setText(QApplication::translate("TransPrintMarginsDialog", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransPrintMarginsDialog: public Ui_TransPrintMarginsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSPRINTMARGINSDIALOG_H
