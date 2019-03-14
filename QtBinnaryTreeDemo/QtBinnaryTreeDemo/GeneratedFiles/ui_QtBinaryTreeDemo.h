/********************************************************************************
** Form generated from reading UI file 'QtBinaryTreeDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTBINARYTREEDEMO_H
#define UI_QTBINARYTREEDEMO_H

#include <PaintArea.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtBinaryTreeDemoClass
{
public:
    QAction *actionInteger;
    QAction *actionFloat;
    QAction *actionString;
    QWidget *centralWidget;
    QPushButton *AddElementButton;
    QPushButton *DeleteElementButton;
    QTextEdit *ObjectValueEditBox;
    QTextEdit *ObjectNameEditBox;
    QLabel *label;
    QLabel *label_2;
    RenderArea *TreeDisplay;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuNowe_Drzewo;

    void setupUi(QMainWindow *QtBinaryTreeDemoClass)
    {
        if (QtBinaryTreeDemoClass->objectName().isEmpty())
            QtBinaryTreeDemoClass->setObjectName(QString::fromUtf8("QtBinaryTreeDemoClass"));
        QtBinaryTreeDemoClass->resize(1620, 890);
        QtBinaryTreeDemoClass->setMinimumSize(QSize(1620, 890));
        QtBinaryTreeDemoClass->setMaximumSize(QSize(1620, 890));
        actionInteger = new QAction(QtBinaryTreeDemoClass);
        actionInteger->setObjectName(QString::fromUtf8("actionInteger"));
        actionFloat = new QAction(QtBinaryTreeDemoClass);
        actionFloat->setObjectName(QString::fromUtf8("actionFloat"));
        actionString = new QAction(QtBinaryTreeDemoClass);
        actionString->setObjectName(QString::fromUtf8("actionString"));
        centralWidget = new QWidget(QtBinaryTreeDemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AddElementButton = new QPushButton(centralWidget);
        AddElementButton->setObjectName(QString::fromUtf8("AddElementButton"));
        AddElementButton->setGeometry(QRect(30, 10, 101, 31));
        DeleteElementButton = new QPushButton(centralWidget);
        DeleteElementButton->setObjectName(QString::fromUtf8("DeleteElementButton"));
        DeleteElementButton->setGeometry(QRect(1300, 10, 101, 31));
        ObjectValueEditBox = new QTextEdit(centralWidget);
        ObjectValueEditBox->setObjectName(QString::fromUtf8("ObjectValueEditBox"));
        ObjectValueEditBox->setGeometry(QRect(210, 10, 460, 31));
        ObjectNameEditBox = new QTextEdit(centralWidget);
        ObjectNameEditBox->setObjectName(QString::fromUtf8("ObjectNameEditBox"));
        ObjectNameEditBox->setGeometry(QRect(780, 10, 441, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 40, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(970, 40, 81, 16));
        TreeDisplay = new RenderArea(centralWidget);
        TreeDisplay->setObjectName(QString::fromUtf8("TreeDisplay"));
        TreeDisplay->setGeometry(QRect(10, 59, 1600, 781));
        QtBinaryTreeDemoClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(QtBinaryTreeDemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtBinaryTreeDemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtBinaryTreeDemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtBinaryTreeDemoClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(QtBinaryTreeDemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1620, 21));
        menuNowe_Drzewo = new QMenu(menuBar);
        menuNowe_Drzewo->setObjectName(QString::fromUtf8("menuNowe_Drzewo"));
        QtBinaryTreeDemoClass->setMenuBar(menuBar);

        menuBar->addAction(menuNowe_Drzewo->menuAction());
        menuNowe_Drzewo->addAction(actionInteger);
        menuNowe_Drzewo->addAction(actionFloat);
        menuNowe_Drzewo->addAction(actionString);

        retranslateUi(QtBinaryTreeDemoClass);

        QMetaObject::connectSlotsByName(QtBinaryTreeDemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtBinaryTreeDemoClass)
    {
        QtBinaryTreeDemoClass->setWindowTitle(QApplication::translate("QtBinaryTreeDemoClass", "QtBinaryTreeDemo", nullptr));
        actionInteger->setText(QApplication::translate("QtBinaryTreeDemoClass", "Integer", nullptr));
        actionFloat->setText(QApplication::translate("QtBinaryTreeDemoClass", "Float", nullptr));
        actionString->setText(QApplication::translate("QtBinaryTreeDemoClass", "String", nullptr));
        AddElementButton->setText(QApplication::translate("QtBinaryTreeDemoClass", "Dodaj Warto\305\233\304\207", nullptr));
        DeleteElementButton->setText(QApplication::translate("QtBinaryTreeDemoClass", "Usu\305\204 Warto\305\233\304\207", nullptr));
        label->setText(QApplication::translate("QtBinaryTreeDemoClass", "Warto\305\233\304\207", nullptr));
        label_2->setText(QApplication::translate("QtBinaryTreeDemoClass", "Nazwa Obiektu", nullptr));
        menuNowe_Drzewo->setTitle(QApplication::translate("QtBinaryTreeDemoClass", "Nowe Drzewo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtBinaryTreeDemoClass: public Ui_QtBinaryTreeDemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTBINARYTREEDEMO_H
