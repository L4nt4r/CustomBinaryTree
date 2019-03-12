/********************************************************************************
** Form generated from reading UI file 'QtBinnaryTreeDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTBINNARYTREEDEMO_H
#define UI_QTBINNARYTREEDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtBinnaryTreeDemoClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtBinnaryTreeDemoClass)
    {
        if (QtBinnaryTreeDemoClass->objectName().isEmpty())
            QtBinnaryTreeDemoClass->setObjectName(QString::fromUtf8("QtBinnaryTreeDemoClass"));
        QtBinnaryTreeDemoClass->resize(600, 400);
        menuBar = new QMenuBar(QtBinnaryTreeDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtBinnaryTreeDemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtBinnaryTreeDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtBinnaryTreeDemoClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtBinnaryTreeDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtBinnaryTreeDemoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtBinnaryTreeDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtBinnaryTreeDemoClass->setStatusBar(statusBar);

        retranslateUi(QtBinnaryTreeDemoClass);

        QMetaObject::connectSlotsByName(QtBinnaryTreeDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtBinnaryTreeDemoClass)
    {
        QtBinnaryTreeDemoClass->setWindowTitle(QApplication::translate("QtBinnaryTreeDemoClass", "QtBinnaryTreeDemo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtBinnaryTreeDemoClass: public Ui_QtBinnaryTreeDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTBINNARYTREEDEMO_H
