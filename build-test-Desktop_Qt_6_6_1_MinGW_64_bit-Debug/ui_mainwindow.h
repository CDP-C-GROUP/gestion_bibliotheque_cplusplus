/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *PBEnregistrelivre;
    QPushButton *PBEnregistreclient;
    QPushButton *PBEmprunt;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        PBEnregistrelivre = new QPushButton(centralwidget);
        PBEnregistrelivre->setObjectName("PBEnregistrelivre");
        PBEnregistrelivre->setGeometry(QRect(20, 10, 131, 91));
        QFont font;
        font.setBold(true);
        PBEnregistrelivre->setFont(font);
        PBEnregistreclient = new QPushButton(centralwidget);
        PBEnregistreclient->setObjectName("PBEnregistreclient");
        PBEnregistreclient->setGeometry(QRect(20, 110, 131, 91));
        PBEnregistreclient->setFont(font);
        PBEmprunt = new QPushButton(centralwidget);
        PBEmprunt->setObjectName("PBEmprunt");
        PBEmprunt->setGeometry(QRect(20, 210, 131, 91));
        PBEmprunt->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Menu Principal [ Logiciel de gestion de la biblioth\303\250que ]", nullptr));
        PBEnregistrelivre->setText(QCoreApplication::translate("MainWindow", "Enregistrer les livres", nullptr));
        PBEnregistreclient->setText(QCoreApplication::translate("MainWindow", "Enregistrer les clients", nullptr));
        PBEmprunt->setText(QCoreApplication::translate("MainWindow", "Effectuer un emprunt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
