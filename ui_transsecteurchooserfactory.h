/********************************************************************************
** Form generated from reading UI file 'transsecteurchooserfactory.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSSECTEURCHOOSERFACTORY_H
#define UI_TRANSSECTEURCHOOSERFACTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransSecteurChooserFactory
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *TransSecteurChooserFactory)
    {
        if (TransSecteurChooserFactory->objectName().isEmpty())
            TransSecteurChooserFactory->setObjectName(QStringLiteral("TransSecteurChooserFactory"));
        TransSecteurChooserFactory->resize(243, 63);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransSecteurChooserFactory->sizePolicy().hasHeightForWidth());
        TransSecteurChooserFactory->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(TransSecteurChooserFactory);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(TransSecteurChooserFactory);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(TransSecteurChooserFactory);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);

        retranslateUi(TransSecteurChooserFactory);

        QMetaObject::connectSlotsByName(TransSecteurChooserFactory);
    } // setupUi

    void retranslateUi(QWidget *TransSecteurChooserFactory)
    {
        TransSecteurChooserFactory->setWindowTitle(QApplication::translate("TransSecteurChooserFactory", "Form", nullptr));
        label->setText(QApplication::translate("TransSecteurChooserFactory", "Pr\303\251visualiser :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransSecteurChooserFactory: public Ui_TransSecteurChooserFactory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSSECTEURCHOOSERFACTORY_H
