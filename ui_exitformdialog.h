/********************************************************************************
** Form generated from reading UI file 'exitformdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITFORMDIALOG_H
#define UI_EXITFORMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExitFormDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *save;
    QPushButton *nosave;
    QPushButton *cancel;
    QLabel *label_3;

    void setupUi(QDialog *ExitFormDialog)
    {
        if (ExitFormDialog->objectName().isEmpty())
            ExitFormDialog->setObjectName(QStringLiteral("ExitFormDialog"));
        ExitFormDialog->resize(514, 151);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExitFormDialog->sizePolicy().hasHeightForWidth());
        ExitFormDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/warning"), QSize(), QIcon::Normal, QIcon::Off);
        ExitFormDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(ExitFormDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        label = new QLabel(ExitFormDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/warning")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(ExitFormDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        save = new QPushButton(ExitFormDialog);
        save->setObjectName(QStringLiteral("save"));
        save->setMinimumSize(QSize(93, 27));

        horizontalLayout->addWidget(save);

        nosave = new QPushButton(ExitFormDialog);
        nosave->setObjectName(QStringLiteral("nosave"));
        nosave->setMinimumSize(QSize(104, 27));

        horizontalLayout->addWidget(nosave);

        cancel = new QPushButton(ExitFormDialog);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setMinimumSize(QSize(93, 27));

        horizontalLayout->addWidget(cancel);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 3);

        gridLayout->addLayout(horizontalLayout, 2, 2, 1, 1);

        label_3 = new QLabel(ExitFormDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        gridLayout->setRowStretch(0, 10);
        gridLayout->setRowStretch(1, 30);
        gridLayout->setRowStretch(2, 1);
        QWidget::setTabOrder(save, cancel);
        QWidget::setTabOrder(cancel, nosave);

        retranslateUi(ExitFormDialog);

        QMetaObject::connectSlotsByName(ExitFormDialog);
    } // setupUi

    void retranslateUi(QDialog *ExitFormDialog)
    {
        ExitFormDialog->setWindowTitle(QApplication::translate("ExitFormDialog", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("ExitFormDialog", "Vous \303\252tes sur le point de quitter l'application sans avoir enregistr\303\251 les derniers changements.<br/>En choisissant de quitter tout de m\303\252me, tous les changements effectu\303\251s seront annul\303\251s.", nullptr));
        save->setText(QApplication::translate("ExitFormDialog", "Enregistrer", nullptr));
        nosave->setText(QApplication::translate("ExitFormDialog", "Ne pas enregistrer", nullptr));
        cancel->setText(QApplication::translate("ExitFormDialog", "Annuler", nullptr));
        label_3->setText(QApplication::translate("ExitFormDialog", "Attention", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ExitFormDialog: public Ui_ExitFormDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITFORMDIALOG_H
