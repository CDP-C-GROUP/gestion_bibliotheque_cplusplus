/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
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
    QAction *actionEnregistrer_Livre;
    QAction *actionEnregister_un_client;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuInterface_d_enregistrement_des_livres;
    QMenu *menuDonn_e_de_base;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionEnregistrer_Livre = new QAction(MainWindow);
        actionEnregistrer_Livre->setObjectName(QString::fromUtf8("actionEnregistrer_Livre"));
        actionEnregistrer_Livre->setCheckable(false);
        actionEnregistrer_Livre->setChecked(false);
        actionEnregister_un_client = new QAction(MainWindow);
        actionEnregister_un_client->setObjectName(QString::fromUtf8("actionEnregister_un_client"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuInterface_d_enregistrement_des_livres = new QMenu(menubar);
        menuInterface_d_enregistrement_des_livres->setObjectName(QString::fromUtf8("menuInterface_d_enregistrement_des_livres"));
        menuDonn_e_de_base = new QMenu(menubar);
        menuDonn_e_de_base->setObjectName(QString::fromUtf8("menuDonn_e_de_base"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuInterface_d_enregistrement_des_livres->menuAction());
        menubar->addAction(menuDonn_e_de_base->menuAction());
        menuDonn_e_de_base->addSeparator();
        menuDonn_e_de_base->addAction(actionEnregistrer_Livre);
        menuDonn_e_de_base->addSeparator();
        menuDonn_e_de_base->addAction(actionEnregister_un_client);
        menuDonn_e_de_base->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "G2 GESLIB", nullptr));
        actionEnregistrer_Livre->setText(QApplication::translate("MainWindow", "Enregistrer Livre", nullptr));
        actionEnregister_un_client->setText(QApplication::translate("MainWindow", "Enregister un client", nullptr));
        actionEnregister_un_client->setIconText(QApplication::translate("MainWindow", "Enregister client", nullptr));
#ifndef QT_NO_TOOLTIP
        actionEnregister_un_client->setToolTip(QApplication::translate("MainWindow", "Enregister client", nullptr));
#endif // QT_NO_TOOLTIP
        menuInterface_d_enregistrement_des_livres->setTitle(QApplication::translate("MainWindow", "Fichier", nullptr));
        menuDonn_e_de_base->setTitle(QApplication::translate("MainWindow", "Donn\303\251e de base", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
