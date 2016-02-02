/********************************************************************************
** Form generated from reading UI file 'adressbuch.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADRESSBUCH_H
#define UI_ADRESSBUCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdressbuchClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *menuWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *adressButton;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *contentWidget;
    QWidget *controlWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdressbuchClass)
    {
        if (AdressbuchClass->objectName().isEmpty())
            AdressbuchClass->setObjectName(QStringLiteral("AdressbuchClass"));
        AdressbuchClass->resize(600, 400);
        centralWidget = new QWidget(AdressbuchClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        menuWidget = new QWidget(centralWidget);
        menuWidget->setObjectName(QStringLiteral("menuWidget"));
        verticalLayout = new QVBoxLayout(menuWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        adressButton = new QPushButton(menuWidget);
        adressButton->setObjectName(QStringLiteral("adressButton"));

        verticalLayout->addWidget(adressButton);

        pushButton = new QPushButton(menuWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(menuWidget);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        contentWidget = new QWidget(layoutWidget);
        contentWidget->setObjectName(QStringLiteral("contentWidget"));

        verticalLayout_2->addWidget(contentWidget);

        controlWidget = new QWidget(layoutWidget);
        controlWidget->setObjectName(QStringLiteral("controlWidget"));

        verticalLayout_2->addWidget(controlWidget);

        verticalLayout_2->setStretch(0, 9);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addWidget(layoutWidget);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 9);
        AdressbuchClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdressbuchClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        AdressbuchClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdressbuchClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AdressbuchClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdressbuchClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AdressbuchClass->setStatusBar(statusBar);

        retranslateUi(AdressbuchClass);

        QMetaObject::connectSlotsByName(AdressbuchClass);
    } // setupUi

    void retranslateUi(QMainWindow *AdressbuchClass)
    {
        AdressbuchClass->setWindowTitle(QApplication::translate("AdressbuchClass", "Adressbuch", 0));
        adressButton->setText(QApplication::translate("AdressbuchClass", "Adressen", 0));
        pushButton->setText(QApplication::translate("AdressbuchClass", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class AdressbuchClass: public Ui_AdressbuchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADRESSBUCH_H
