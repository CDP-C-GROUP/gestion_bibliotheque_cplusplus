/********************************************************************************
** Form generated from reading UI file 'enregistreclient.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENREGISTRECLIENT_H
#define UI_ENREGISTRECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enregistreclient
{
public:
    QTextBrowser *infoclient;
    QLabel *labelnomclient;
    QLineEdit *SAIPrenomduClient;
    QLabel *labeltel;
    QTableWidget *TableClients;
    QLabel *labelprenomclient;
    QLineEdit *SAINomduClient;
    QPushButton *BTNValider;
    QPushButton *BTNNouveau;
    QLineEdit *SAITelephone;

    void setupUi(QWidget *enregistreclient)
    {
        if (enregistreclient->objectName().isEmpty())
            enregistreclient->setObjectName("enregistreclient");
        enregistreclient->resize(747, 375);
        infoclient = new QTextBrowser(enregistreclient);
        infoclient->setObjectName("infoclient");
        infoclient->setGeometry(QRect(531, 23, 201, 111));
        labelnomclient = new QLabel(enregistreclient);
        labelnomclient->setObjectName("labelnomclient");
        labelnomclient->setGeometry(QRect(12, 24, 91, 21));
        SAIPrenomduClient = new QLineEdit(enregistreclient);
        SAIPrenomduClient->setObjectName("SAIPrenomduClient");
        SAIPrenomduClient->setGeometry(QRect(101, 54, 341, 20));
        SAIPrenomduClient->setFocusPolicy(Qt::ClickFocus);
        labeltel = new QLabel(enregistreclient);
        labeltel->setObjectName("labeltel");
        labeltel->setGeometry(QRect(11, 87, 71, 16));
        TableClients = new QTableWidget(enregistreclient);
        if (TableClients->columnCount() < 3)
            TableClients->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableClients->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableClients->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableClients->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        TableClients->setObjectName("TableClients");
        TableClients->setGeometry(QRect(11, 144, 721, 201));
        labelprenomclient = new QLabel(enregistreclient);
        labelprenomclient->setObjectName("labelprenomclient");
        labelprenomclient->setGeometry(QRect(12, 53, 70, 21));
        SAINomduClient = new QLineEdit(enregistreclient);
        SAINomduClient->setObjectName("SAINomduClient");
        SAINomduClient->setGeometry(QRect(101, 24, 341, 20));
        SAINomduClient->setFocusPolicy(Qt::ClickFocus);
        BTNValider = new QPushButton(enregistreclient);
        BTNValider->setObjectName("BTNValider");
        BTNValider->setGeometry(QRect(451, 24, 74, 23));
        BTNNouveau = new QPushButton(enregistreclient);
        BTNNouveau->setObjectName("BTNNouveau");
        BTNNouveau->setGeometry(QRect(452, 54, 75, 23));
        SAITelephone = new QLineEdit(enregistreclient);
        SAITelephone->setObjectName("SAITelephone");
        SAITelephone->setGeometry(QRect(102, 87, 340, 20));
        SAITelephone->setFocusPolicy(Qt::ClickFocus);

        retranslateUi(enregistreclient);

        QMetaObject::connectSlotsByName(enregistreclient);
    } // setupUi

    void retranslateUi(QWidget *enregistreclient)
    {
        enregistreclient->setWindowTitle(QCoreApplication::translate("enregistreclient", "enregistreclient", nullptr));
        labelnomclient->setText(QCoreApplication::translate("enregistreclient", "Nom", nullptr));
        labeltel->setText(QCoreApplication::translate("enregistreclient", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableClients->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("enregistreclient", "Nom Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableClients->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("enregistreclient", "Pr\303\251nom Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableClients->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("enregistreclient", "T\303\251l\303\251phone", nullptr));
        labelprenomclient->setText(QCoreApplication::translate("enregistreclient", "Pr\303\251nom", nullptr));
        BTNValider->setText(QCoreApplication::translate("enregistreclient", "Valider", nullptr));
        BTNNouveau->setText(QCoreApplication::translate("enregistreclient", "Nouveau", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enregistreclient: public Ui_enregistreclient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGISTRECLIENT_H
