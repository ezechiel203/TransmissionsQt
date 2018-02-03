/********************************************************************************
** Form generated from reading UI file 'aboutformdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTFORMDIALOG_H
#define UI_ABOUTFORMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutFormDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *AboutFormDialog)
    {
        if (AboutFormDialog->objectName().isEmpty())
            AboutFormDialog->setObjectName(QStringLiteral("AboutFormDialog"));
        AboutFormDialog->resize(591, 250);
        QPalette palette;
        QBrush brush(QColor(253, 253, 253, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        AboutFormDialog->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral(":/mainIcon"), QSize(), QIcon::Normal, QIcon::Off);
        AboutFormDialog->setWindowIcon(icon);
        AboutFormDialog->setStyleSheet(QStringLiteral("background-color: #FDFDFD;"));
        gridLayout = new QGridLayout(AboutFormDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetFixedSize);
        label_3 = new QLabel(AboutFormDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgba(255, 255, 255, 0);\n"
""));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/titre")));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        label_2 = new QLabel(AboutFormDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgba(255, 255, 255,0);\n"
""));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(AboutFormDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QLatin1String("background-image: url(null);\n"
"background-color: rgba(255, 255, 255, 0);\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/mainIcon")));
        label->setScaledContents(false);

        gridLayout->addWidget(label, 0, 0, 2, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 3);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        retranslateUi(AboutFormDialog);

        QMetaObject::connectSlotsByName(AboutFormDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutFormDialog)
    {
        AboutFormDialog->setWindowTitle(QApplication::translate("AboutFormDialog", "Dialog", nullptr));
        label_3->setText(QString());
        label_2->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutFormDialog: public Ui_AboutFormDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTFORMDIALOG_H
