/********************************************************************************
** Form generated from reading UI file 'enregistrelivres.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENREGISTRELIVRES_H
#define UI_ENREGISTRELIVRES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enregistrelivres
{
public:
    QDateEdit *dateParition;
    QLineEdit *CodeduLivre;
    QLabel *labelauteur;
    QLabel *labeldateparution;
    QTableWidget *tableWidget;
    QLabel *labelcodelivre;
    QLabel *labelnomlivre;
    QLineEdit *NomduLivre;
    QPushButton *BTNValider;
    QLineEdit *NomduLivre_2;

    void setupUi(QWidget *enregistrelivres)
    {
        if (enregistrelivres->objectName().isEmpty())
            enregistrelivres->setObjectName(QString::fromUtf8("enregistrelivres"));
        enregistrelivres->resize(779, 425);
        dateParition = new QDateEdit(enregistrelivres);
        dateParition->setObjectName(QString::fromUtf8("dateParition"));
        dateParition->setGeometry(QRect(80, 100, 110, 22));
        CodeduLivre = new QLineEdit(enregistrelivres);
        CodeduLivre->setObjectName(QString::fromUtf8("CodeduLivre"));
        CodeduLivre->setGeometry(QRect(80, 10, 361, 20));
        labelauteur = new QLabel(enregistrelivres);
        labelauteur->setObjectName(QString::fromUtf8("labelauteur"));
        labelauteur->setGeometry(QRect(10, 70, 71, 21));
        labeldateparution = new QLabel(enregistrelivres);
        labeldateparution->setObjectName(QString::fromUtf8("labeldateparution"));
        labeldateparution->setGeometry(QRect(10, 100, 71, 21));
        tableWidget = new QTableWidget(enregistrelivres);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 150, 731, 261));
        labelcodelivre = new QLabel(enregistrelivres);
        labelcodelivre->setObjectName(QString::fromUtf8("labelcodelivre"));
        labelcodelivre->setGeometry(QRect(10, 10, 71, 21));
        labelnomlivre = new QLabel(enregistrelivres);
        labelnomlivre->setObjectName(QString::fromUtf8("labelnomlivre"));
        labelnomlivre->setGeometry(QRect(10, 40, 71, 21));
        NomduLivre = new QLineEdit(enregistrelivres);
        NomduLivre->setObjectName(QString::fromUtf8("NomduLivre"));
        NomduLivre->setGeometry(QRect(80, 40, 361, 20));
        BTNValider = new QPushButton(enregistrelivres);
        BTNValider->setObjectName(QString::fromUtf8("BTNValider"));
        BTNValider->setGeometry(QRect(370, 100, 75, 23));
        NomduLivre_2 = new QLineEdit(enregistrelivres);
        NomduLivre_2->setObjectName(QString::fromUtf8("NomduLivre_2"));
        NomduLivre_2->setGeometry(QRect(80, 70, 361, 20));

        retranslateUi(enregistrelivres);

        QMetaObject::connectSlotsByName(enregistrelivres);
    } // setupUi

    void retranslateUi(QWidget *enregistrelivres)
    {
        enregistrelivres->setWindowTitle(QApplication::translate("enregistrelivres", "Interface d'enregistrement des livres", nullptr));
        labelauteur->setText(QApplication::translate("enregistrelivres", "Auteur", nullptr));
        labeldateparution->setText(QApplication::translate("enregistrelivres", "Date Parution", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("enregistrelivres", "Code Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("enregistrelivres", "Nom Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("enregistrelivres", "Auteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("enregistrelivres", "Date Parution", nullptr));
        labelcodelivre->setText(QApplication::translate("enregistrelivres", "Code Livre", nullptr));
        labelnomlivre->setText(QApplication::translate("enregistrelivres", "Nom du Livre", nullptr));
        BTNValider->setText(QApplication::translate("enregistrelivres", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enregistrelivres: public Ui_enregistrelivres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGISTRELIVRES_H
