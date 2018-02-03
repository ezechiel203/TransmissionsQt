/********************************************************************************
** Form generated from reading UI file 'switchrooms.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCHROOMS_H
#define UI_SWITCHROOMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SwitchRooms
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QComboBox *comboChDep;
    QLabel *labelChDep;
    QComboBox *comboSectDep;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QComboBox *comboChArr;
    QLabel *labelChArr;
    QComboBox *comboSectArr;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *ChambrePrise;
    QLabel *label_2;
    QComboBox *options;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *boutonValid;
    QPushButton *boutonAnul;

    void setupUi(QDialog *SwitchRooms)
    {
        if (SwitchRooms->objectName().isEmpty())
            SwitchRooms->setObjectName(QStringLiteral("SwitchRooms"));
        SwitchRooms->resize(381, 351);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SwitchRooms->sizePolicy().hasHeightForWidth());
        SwitchRooms->setSizePolicy(sizePolicy);
        SwitchRooms->setMinimumSize(QSize(381, 280));
        SwitchRooms->setMaximumSize(QSize(381, 166665));
        SwitchRooms->setBaseSize(QSize(381, 400));
        QIcon icon;
        icon.addFile(QStringLiteral(":/lit"), QSize(), QIcon::Normal, QIcon::Off);
        SwitchRooms->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SwitchRooms);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        groupBox = new QGroupBox(SwitchRooms);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(363, 100));
        groupBox->setStyleSheet(QStringLiteral(""));
        comboChDep = new QComboBox(groupBox);
        comboChDep->setObjectName(QStringLiteral("comboChDep"));
        comboChDep->setGeometry(QRect(60, 60, 111, 22));
        labelChDep = new QLabel(groupBox);
        labelChDep->setObjectName(QStringLiteral("labelChDep"));
        labelChDep->setGeometry(QRect(200, 30, 151, 51));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelChDep->setFont(font);
        comboSectDep = new QComboBox(groupBox);
        comboSectDep->setObjectName(QStringLiteral("comboSectDep"));
        comboSectDep->setGeometry(QRect(60, 30, 111, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 46, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 60, 46, 21));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(SwitchRooms);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(363, 100));
        groupBox_2->setStyleSheet(QStringLiteral(""));
        comboChArr = new QComboBox(groupBox_2);
        comboChArr->setObjectName(QStringLiteral("comboChArr"));
        comboChArr->setGeometry(QRect(60, 60, 111, 22));
        labelChArr = new QLabel(groupBox_2);
        labelChArr->setObjectName(QStringLiteral("labelChArr"));
        labelChArr->setGeometry(QRect(200, 30, 151, 51));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelChArr->sizePolicy().hasHeightForWidth());
        labelChArr->setSizePolicy(sizePolicy2);
        labelChArr->setFont(font);
        comboSectArr = new QComboBox(groupBox_2);
        comboSectArr->setObjectName(QStringLiteral("comboSectArr"));
        comboSectArr->setGeometry(QRect(60, 30, 111, 22));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 58, 46, 21));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 46, 21));

        verticalLayout->addWidget(groupBox_2);

        ChambrePrise = new QWidget(SwitchRooms);
        ChambrePrise->setObjectName(QStringLiteral("ChambrePrise"));
        ChambrePrise->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ChambrePrise->sizePolicy().hasHeightForWidth());
        ChambrePrise->setSizePolicy(sizePolicy3);
        ChambrePrise->setMinimumSize(QSize(0, 80));
        ChambrePrise->setBaseSize(QSize(0, 80));
        label_2 = new QLabel(ChambrePrise);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 241, 31));
        options = new QComboBox(ChambrePrise);
        options->setObjectName(QStringLiteral("options"));
        options->setGeometry(QRect(10, 50, 111, 22));

        verticalLayout->addWidget(ChambrePrise);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(12);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        boutonValid = new QPushButton(SwitchRooms);
        boutonValid->setObjectName(QStringLiteral("boutonValid"));
        boutonValid->setEnabled(false);

        horizontalLayout->addWidget(boutonValid);

        boutonAnul = new QPushButton(SwitchRooms);
        boutonAnul->setObjectName(QStringLiteral("boutonAnul"));

        horizontalLayout->addWidget(boutonAnul);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 5);
        verticalLayout->setStretch(3, 1);

        retranslateUi(SwitchRooms);

        QMetaObject::connectSlotsByName(SwitchRooms);
    } // setupUi

    void retranslateUi(QDialog *SwitchRooms)
    {
        SwitchRooms->setWindowTitle(QApplication::translate("SwitchRooms", "Mouvement interne au service", nullptr));
        groupBox->setTitle(QApplication::translate("SwitchRooms", "Chambre d'origine", nullptr));
        labelChDep->setText(QApplication::translate("SwitchRooms", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("SwitchRooms", "Secteur", nullptr));
        label_4->setText(QApplication::translate("SwitchRooms", "Chambre", nullptr));
        groupBox_2->setTitle(QApplication::translate("SwitchRooms", "Chambre de destination", nullptr));
        labelChArr->setText(QApplication::translate("SwitchRooms", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("SwitchRooms", "Chambre", nullptr));
        label_6->setText(QApplication::translate("SwitchRooms", "Secteur", nullptr));
        label_2->setText(QApplication::translate("SwitchRooms", "<html><b>La chambre de destination n'est pas libre.</b><br/> Que voulez vous faire ?</html>", nullptr));
        boutonValid->setText(QApplication::translate("SwitchRooms", "Valider", nullptr));
        boutonAnul->setText(QApplication::translate("SwitchRooms", "Annuler", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SwitchRooms: public Ui_SwitchRooms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCHROOMS_H
