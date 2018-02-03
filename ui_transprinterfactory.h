/********************************************************************************
** Form generated from reading UI file 'transprinterfactory.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSPRINTERFACTORY_H
#define UI_TRANSPRINTERFACTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransPrinterFactory
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *printFast;
    QPushButton *print;

    void setupUi(QWidget *TransPrinterFactory)
    {
        if (TransPrinterFactory->objectName().isEmpty())
            TransPrinterFactory->setObjectName(QStringLiteral("TransPrinterFactory"));
        TransPrinterFactory->resize(243, 130);
        verticalLayout = new QVBoxLayout(TransPrinterFactory);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(TransPrinterFactory);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(TransPrinterFactory);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFrame(false);
        comboBox->setModelColumn(0);

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        printFast = new QPushButton(TransPrinterFactory);
        printFast->setObjectName(QStringLiteral("printFast"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/printfast"), QSize(), QIcon::Normal, QIcon::Off);
        printFast->setIcon(icon);
        printFast->setIconSize(QSize(32, 32));
        printFast->setAutoExclusive(false);

        horizontalLayout->addWidget(printFast);

        print = new QPushButton(TransPrinterFactory);
        print->setObjectName(QStringLiteral("print"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/print"), QSize(), QIcon::Normal, QIcon::Off);
        print->setIcon(icon1);
        print->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(print);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TransPrinterFactory);

        QMetaObject::connectSlotsByName(TransPrinterFactory);
    } // setupUi

    void retranslateUi(QWidget *TransPrinterFactory)
    {
        TransPrinterFactory->setWindowTitle(QApplication::translate("TransPrinterFactory", "Form", nullptr));
        label->setText(QApplication::translate("TransPrinterFactory", "Imprimer les transmissions pour :", nullptr));
#ifndef QT_NO_TOOLTIP
        printFast->setToolTip(QApplication::translate("TransPrinterFactory", "Imprimer un exemplaire", nullptr));
#endif // QT_NO_TOOLTIP
        printFast->setText(QApplication::translate("TransPrinterFactory", "Impression\n"
"rapide", nullptr));
#ifndef QT_NO_TOOLTIP
        print->setToolTip(QApplication::translate("TransPrinterFactory", "Choix du nombre d'exemplaires\n"
"Choix des pages \303\240 imprimer\n"
"Choix de l'imprimante", nullptr));
#endif // QT_NO_TOOLTIP
        print->setText(QApplication::translate("TransPrinterFactory", "Impression\n"
"personnalis\303\251e", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransPrinterFactory: public Ui_TransPrinterFactory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSPRINTERFACTORY_H
