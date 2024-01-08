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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enregistrelivres
{
public:
    QDateEdit *SAIdateParition;
    QLineEdit *SAICodeduLivre;
    QLabel *labelauteur;
    QLabel *labeldateparution;
    QTableWidget *TableLivres;
    QLabel *labelcodelivre;
    QLabel *labelnomlivre;
    QLineEdit *SAINomduLivre;
    QPushButton *BTNValider;
    QLineEdit *SAIAuteurduLivre;
    QPushButton *BTNNouveau;
    QTextBrowser *infolivre;

    void setupUi(QWidget *enregistrelivres)
    {
        if (enregistrelivres->objectName().isEmpty())
            enregistrelivres->setObjectName(QString::fromUtf8("enregistrelivres"));
        enregistrelivres->resize(779, 425);
        enregistrelivres->setFocusPolicy(Qt::TabFocus);
        SAIdateParition = new QDateEdit(enregistrelivres);
        SAIdateParition->setObjectName(QString::fromUtf8("SAIdateParition"));
        SAIdateParition->setGeometry(QRect(80, 100, 110, 22));
        SAIdateParition->setCursor(QCursor(Qt::ArrowCursor));
        SAIdateParition->setFocusPolicy(Qt::ClickFocus);
        SAICodeduLivre = new QLineEdit(enregistrelivres);
        SAICodeduLivre->setObjectName(QString::fromUtf8("SAICodeduLivre"));
        SAICodeduLivre->setGeometry(QRect(80, 10, 361, 20));
        SAICodeduLivre->setFocusPolicy(Qt::WheelFocus);
        labelauteur = new QLabel(enregistrelivres);
        labelauteur->setObjectName(QString::fromUtf8("labelauteur"));
        labelauteur->setGeometry(QRect(10, 70, 71, 21));
        labeldateparution = new QLabel(enregistrelivres);
        labeldateparution->setObjectName(QString::fromUtf8("labeldateparution"));
        labeldateparution->setGeometry(QRect(10, 100, 71, 21));
        TableLivres = new QTableWidget(enregistrelivres);
        if (TableLivres->columnCount() < 4)
            TableLivres->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        TableLivres->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        TableLivres->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        TableLivres->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        TableLivres->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        TableLivres->setObjectName(QString::fromUtf8("TableLivres"));
        TableLivres->setGeometry(QRect(10, 150, 761, 261));
        labelcodelivre = new QLabel(enregistrelivres);
        labelcodelivre->setObjectName(QString::fromUtf8("labelcodelivre"));
        labelcodelivre->setGeometry(QRect(10, 10, 71, 21));
        labelnomlivre = new QLabel(enregistrelivres);
        labelnomlivre->setObjectName(QString::fromUtf8("labelnomlivre"));
        labelnomlivre->setGeometry(QRect(10, 40, 71, 21));
        SAINomduLivre = new QLineEdit(enregistrelivres);
        SAINomduLivre->setObjectName(QString::fromUtf8("SAINomduLivre"));
        SAINomduLivre->setGeometry(QRect(80, 40, 361, 20));
        SAINomduLivre->setFocusPolicy(Qt::ClickFocus);
        BTNValider = new QPushButton(enregistrelivres);
        BTNValider->setObjectName(QString::fromUtf8("BTNValider"));
        BTNValider->setGeometry(QRect(450, 40, 75, 23));
        SAIAuteurduLivre = new QLineEdit(enregistrelivres);
        SAIAuteurduLivre->setObjectName(QString::fromUtf8("SAIAuteurduLivre"));
        SAIAuteurduLivre->setGeometry(QRect(80, 70, 361, 20));
        SAIAuteurduLivre->setFocusPolicy(Qt::ClickFocus);
        BTNNouveau = new QPushButton(enregistrelivres);
        BTNNouveau->setObjectName(QString::fromUtf8("BTNNouveau"));
        BTNNouveau->setGeometry(QRect(450, 10, 75, 23));
        infolivre = new QTextBrowser(enregistrelivres);
        infolivre->setObjectName(QString::fromUtf8("infolivre"));
        infolivre->setGeometry(QRect(530, 0, 241, 141));

        retranslateUi(enregistrelivres);

        QMetaObject::connectSlotsByName(enregistrelivres);
    } // setupUi

    void retranslateUi(QWidget *enregistrelivres)
    {
        enregistrelivres->setWindowTitle(QApplication::translate("enregistrelivres", "Interface d'enregistrement des livres", nullptr));
        labelauteur->setText(QApplication::translate("enregistrelivres", "Auteur", nullptr));
        labeldateparution->setText(QApplication::translate("enregistrelivres", "Date Parution", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableLivres->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("enregistrelivres", "Code Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableLivres->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("enregistrelivres", "Nom Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableLivres->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("enregistrelivres", "Auteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TableLivres->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("enregistrelivres", "Date Parution", nullptr));
        labelcodelivre->setText(QApplication::translate("enregistrelivres", "Code Livre", nullptr));
        labelnomlivre->setText(QApplication::translate("enregistrelivres", "Nom du Livre", nullptr));
        BTNValider->setText(QApplication::translate("enregistrelivres", "Valider", nullptr));
        BTNNouveau->setText(QApplication::translate("enregistrelivres", "Nouveau", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enregistrelivres: public Ui_enregistrelivres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGISTRELIVRES_H
