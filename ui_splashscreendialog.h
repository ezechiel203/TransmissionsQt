/********************************************************************************
** Form generated from reading UI file 'splashscreendialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHSCREENDIALOG_H
#define UI_SPLASHSCREENDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_SplashScreenDialog
{
public:
    QListWidget *listWidget;
    QLabel *petale1;
    QLabel *petale2;
    QLabel *petale3;
    QLabel *label;

    void setupUi(QDialog *SplashScreenDialog)
    {
        if (SplashScreenDialog->objectName().isEmpty())
            SplashScreenDialog->setObjectName(QStringLiteral("SplashScreenDialog"));
        SplashScreenDialog->setWindowModality(Qt::ApplicationModal);
        SplashScreenDialog->resize(670, 250);
        SplashScreenDialog->setMinimumSize(QSize(670, 250));
        SplashScreenDialog->setMaximumSize(QSize(670, 250));
        SplashScreenDialog->setCursor(QCursor(Qt::BusyCursor));
        SplashScreenDialog->setFocusPolicy(Qt::StrongFocus);
        SplashScreenDialog->setContextMenuPolicy(Qt::NoContextMenu);
        SplashScreenDialog->setAutoFillBackground(false);
        SplashScreenDialog->setStyleSheet(QStringLiteral("QDialog {background-image : url(:/logo)}"));
        listWidget = new QListWidget(SplashScreenDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(192, 160, 281, 91));
        listWidget->setStyleSheet(QStringLiteral(""));
        listWidget->setFrameShape(QFrame::NoFrame);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        listWidget->setAutoScroll(false);
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        petale1 = new QLabel(SplashScreenDialog);
        petale1->setObjectName(QStringLiteral("petale1"));
        petale1->setGeometry(QRect(168, 24, 31, 31));
        petale1->setPixmap(QPixmap(QString::fromUtf8(":/petal1")));
        petale2 = new QLabel(SplashScreenDialog);
        petale2->setObjectName(QStringLiteral("petale2"));
        petale2->setGeometry(QRect(152, 33, 21, 21));
        petale2->setPixmap(QPixmap(QString::fromUtf8(":/petal2")));
        petale3 = new QLabel(SplashScreenDialog);
        petale3->setObjectName(QStringLiteral("petale3"));
        petale3->setGeometry(QRect(152, 47, 21, 16));
        petale3->setPixmap(QPixmap(QString::fromUtf8(":/petal3")));
        label = new QLabel(SplashScreenDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 50, 671, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/titre")));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(SplashScreenDialog);

        QMetaObject::connectSlotsByName(SplashScreenDialog);
    } // setupUi

    void retranslateUi(QDialog *SplashScreenDialog)
    {
        SplashScreenDialog->setWindowTitle(QApplication::translate("SplashScreenDialog", "Dialog", nullptr));
        petale1->setText(QString());
        petale2->setText(QString());
        petale3->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SplashScreenDialog: public Ui_SplashScreenDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHSCREENDIALOG_H
