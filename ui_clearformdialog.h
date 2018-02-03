/********************************************************************************
** Form generated from reading UI file 'clearformdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLEARFORMDIALOG_H
#define UI_CLEARFORMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ClearFormDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QCheckBox *noAsk;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ClearFormDialog)
    {
        if (ClearFormDialog->objectName().isEmpty())
            ClearFormDialog->setObjectName(QStringLiteral("ClearFormDialog"));
        ClearFormDialog->resize(331, 151);
        QIcon icon;
        icon.addFile(QStringLiteral(":/mainIcon"), QSize(), QIcon::Normal, QIcon::Off);
        ClearFormDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(ClearFormDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ClearFormDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        noAsk = new QCheckBox(ClearFormDialog);
        noAsk->setObjectName(QStringLiteral("noAsk"));

        verticalLayout->addWidget(noAsk);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, 10, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(ClearFormDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(157);
        sizePolicy.setVerticalStretch(39);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setMinimumSize(QSize(157, 39));
        buttonBox->setMaximumSize(QSize(157, 39));
        buttonBox->setBaseSize(QSize(157, 39));
        buttonBox->setStyleSheet(QStringLiteral(""));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        horizontalLayout->addWidget(buttonBox);

        horizontalLayout->setStretch(0, 60);
        horizontalLayout->setStretch(1, 40);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 40);
        verticalLayout->setStretch(1, 40);
        verticalLayout->setStretch(2, 20);

        retranslateUi(ClearFormDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), ClearFormDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ClearFormDialog);
    } // setupUi

    void retranslateUi(QDialog *ClearFormDialog)
    {
        ClearFormDialog->setWindowTitle(QApplication::translate("ClearFormDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("ClearFormDialog", "Vous allez supprimer l'ensemble des donn\303\251es pour cette chambre.<br />Continuer?", nullptr));
        noAsk->setText(QApplication::translate("ClearFormDialog", "J'ai bien compris. Ne plus me poser la question.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClearFormDialog: public Ui_ClearFormDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLEARFORMDIALOG_H
