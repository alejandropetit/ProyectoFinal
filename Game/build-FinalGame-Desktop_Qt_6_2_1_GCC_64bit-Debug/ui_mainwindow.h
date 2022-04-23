/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionMenu_Principal;
    QAction *actionDresden;
    QAction *actionSarajevo;
    QAction *actionGrozni;
    QAction *actionAleppo;
    QAction *actionSalir;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuNiveles;
    QMenu *menuMenu;
    QMenu *menuniveles;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);\n"
""));
        actionMenu_Principal = new QAction(MainWindow);
        actionMenu_Principal->setObjectName(QString::fromUtf8("actionMenu_Principal"));
        actionDresden = new QAction(MainWindow);
        actionDresden->setObjectName(QString::fromUtf8("actionDresden"));
        actionSarajevo = new QAction(MainWindow);
        actionSarajevo->setObjectName(QString::fromUtf8("actionSarajevo"));
        actionGrozni = new QAction(MainWindow);
        actionGrozni->setObjectName(QString::fromUtf8("actionGrozni"));
        actionAleppo = new QAction(MainWindow);
        actionAleppo->setObjectName(QString::fromUtf8("actionAleppo"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuNiveles = new QMenu(menubar);
        menuNiveles->setObjectName(QString::fromUtf8("menuNiveles"));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuniveles = new QMenu(menuMenu);
        menuniveles->setObjectName(QString::fromUtf8("menuniveles"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuNiveles->menuAction());
        menuMenu->addAction(menuniveles->menuAction());
        menuMenu->addAction(actionSalir);
        menuniveles->addSeparator();
        menuniveles->addAction(actionDresden);
        menuniveles->addSeparator();
        menuniveles->addAction(actionSarajevo);
        menuniveles->addSeparator();
        menuniveles->addAction(actionGrozni);
        menuniveles->addSeparator();
        menuniveles->addAction(actionAleppo);
        menuniveles->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionMenu_Principal->setText(QCoreApplication::translate("MainWindow", "Menu Principal", nullptr));
        actionDresden->setText(QCoreApplication::translate("MainWindow", "Dresden", nullptr));
        actionSarajevo->setText(QCoreApplication::translate("MainWindow", "Sarajevo", nullptr));
        actionGrozni->setText(QCoreApplication::translate("MainWindow", "Grozni", nullptr));
        actionAleppo->setText(QCoreApplication::translate("MainWindow", "Aleppo", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        menuNiveles->setTitle(QCoreApplication::translate("MainWindow", "Niveles", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
        menuniveles->setTitle(QCoreApplication::translate("MainWindow", "niveles", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
