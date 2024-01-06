/********************************************************************************
** Form generated from reading UI file 'EnregLivre.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENREGLIVRE_H
#define UI_ENREGLIVRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EnregLivre
{
public:
    QLineEdit *NomduLivre;
    QLabel *labelnomlivre;
    QLabel *labelauteur;
    QLineEdit *NomduLivre_2;
    QLabel *labelcodelivre;
    QLineEdit *CodeduLivre;
    QLabel *labeldateparution;
    QDateEdit *dateParition;
    QTableWidget *tableWidget;

    void setupUi(QWidget *EnregLivre)
    {
        if (EnregLivre->objectName().isEmpty())
            EnregLivre->setObjectName(QString::fromUtf8("EnregLivre"));
        EnregLivre->resize(761, 380);
        NomduLivre = new QLineEdit(EnregLivre);
        NomduLivre->setObjectName(QString::fromUtf8("NomduLivre"));
        NomduLivre->setGeometry(QRect(90, 50, 361, 20));
        labelnomlivre = new QLabel(EnregLivre);
        labelnomlivre->setObjectName(QString::fromUtf8("labelnomlivre"));
        labelnomlivre->setGeometry(QRect(20, 50, 71, 21));
        labelauteur = new QLabel(EnregLivre);
        labelauteur->setObjectName(QString::fromUtf8("labelauteur"));
        labelauteur->setGeometry(QRect(20, 80, 71, 21));
        NomduLivre_2 = new QLineEdit(EnregLivre);
        NomduLivre_2->setObjectName(QString::fromUtf8("NomduLivre_2"));
        NomduLivre_2->setGeometry(QRect(90, 80, 361, 20));
        labelcodelivre = new QLabel(EnregLivre);
        labelcodelivre->setObjectName(QString::fromUtf8("labelcodelivre"));
        labelcodelivre->setGeometry(QRect(20, 20, 71, 21));
        CodeduLivre = new QLineEdit(EnregLivre);
        CodeduLivre->setObjectName(QString::fromUtf8("CodeduLivre"));
        CodeduLivre->setGeometry(QRect(90, 20, 361, 20));
        labeldateparution = new QLabel(EnregLivre);
        labeldateparution->setObjectName(QString::fromUtf8("labeldateparution"));
        labeldateparution->setGeometry(QRect(20, 110, 71, 21));
        dateParition = new QDateEdit(EnregLivre);
        dateParition->setObjectName(QString::fromUtf8("dateParition"));
        dateParition->setGeometry(QRect(90, 110, 110, 22));
        tableWidget = new QTableWidget(EnregLivre);
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
        tableWidget->setGeometry(QRect(20, 160, 731, 211));

        retranslateUi(EnregLivre);

        QMetaObject::connectSlotsByName(EnregLivre);
    } // setupUi

    void retranslateUi(QWidget *EnregLivre)
    {
        EnregLivre->setWindowTitle(QApplication::translate("EnregLivre", "Interface d'enregistrement d'un Livre", nullptr));
        labelnomlivre->setText(QApplication::translate("EnregLivre", "Nom du Livre", nullptr));
        labelauteur->setText(QApplication::translate("EnregLivre", "Auteur", nullptr));
        labelcodelivre->setText(QApplication::translate("EnregLivre", "Code Livre", nullptr));
        labeldateparution->setText(QApplication::translate("EnregLivre", "Date Parution", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("EnregLivre", "Code Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("EnregLivre", "Nom Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("EnregLivre", "Auteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("EnregLivre", "Date Parution", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnregLivre: public Ui_EnregLivre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGLIVRE_H
