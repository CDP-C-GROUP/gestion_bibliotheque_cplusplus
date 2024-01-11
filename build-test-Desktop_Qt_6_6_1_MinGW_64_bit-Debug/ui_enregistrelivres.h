/********************************************************************************
** Form generated from reading UI file 'enregistrelivres.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
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
#include <QtWidgets/QSpinBox>
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
    QLabel *labelquantite;
    QSpinBox *SAIQuantiteLivre;

    void setupUi(QWidget *enregistrelivres)
    {
        if (enregistrelivres->objectName().isEmpty())
            enregistrelivres->setObjectName("enregistrelivres");
        enregistrelivres->resize(779, 456);
        enregistrelivres->setFocusPolicy(Qt::TabFocus);
        SAIdateParition = new QDateEdit(enregistrelivres);
        SAIdateParition->setObjectName("SAIdateParition");
        SAIdateParition->setGeometry(QRect(100, 150, 341, 22));
        SAIdateParition->setCursor(QCursor(Qt::ArrowCursor));
        SAIdateParition->setFocusPolicy(Qt::ClickFocus);
        SAICodeduLivre = new QLineEdit(enregistrelivres);
        SAICodeduLivre->setObjectName("SAICodeduLivre");
        SAICodeduLivre->setGeometry(QRect(100, 10, 341, 20));
        SAICodeduLivre->setFocusPolicy(Qt::WheelFocus);
        labelauteur = new QLabel(enregistrelivres);
        labelauteur->setObjectName("labelauteur");
        labelauteur->setGeometry(QRect(10, 70, 71, 21));
        labeldateparution = new QLabel(enregistrelivres);
        labeldateparution->setObjectName("labeldateparution");
        labeldateparution->setGeometry(QRect(10, 150, 71, 21));
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
        TableLivres->setObjectName("TableLivres");
        TableLivres->setGeometry(QRect(10, 190, 761, 261));
        labelcodelivre = new QLabel(enregistrelivres);
        labelcodelivre->setObjectName("labelcodelivre");
        labelcodelivre->setGeometry(QRect(10, 10, 71, 21));
        labelnomlivre = new QLabel(enregistrelivres);
        labelnomlivre->setObjectName("labelnomlivre");
        labelnomlivre->setGeometry(QRect(10, 40, 71, 21));
        SAINomduLivre = new QLineEdit(enregistrelivres);
        SAINomduLivre->setObjectName("SAINomduLivre");
        SAINomduLivre->setGeometry(QRect(100, 40, 341, 20));
        SAINomduLivre->setFocusPolicy(Qt::ClickFocus);
        BTNValider = new QPushButton(enregistrelivres);
        BTNValider->setObjectName("BTNValider");
        BTNValider->setGeometry(QRect(450, 40, 75, 23));
        SAIAuteurduLivre = new QLineEdit(enregistrelivres);
        SAIAuteurduLivre->setObjectName("SAIAuteurduLivre");
        SAIAuteurduLivre->setGeometry(QRect(100, 70, 341, 20));
        SAIAuteurduLivre->setFocusPolicy(Qt::ClickFocus);
        BTNNouveau = new QPushButton(enregistrelivres);
        BTNNouveau->setObjectName("BTNNouveau");
        BTNNouveau->setGeometry(QRect(450, 10, 75, 23));
        infolivre = new QTextBrowser(enregistrelivres);
        infolivre->setObjectName("infolivre");
        infolivre->setGeometry(QRect(530, 0, 241, 181));
        labelquantite = new QLabel(enregistrelivres);
        labelquantite->setObjectName("labelquantite");
        labelquantite->setGeometry(QRect(10, 110, 55, 16));
        SAIQuantiteLivre = new QSpinBox(enregistrelivres);
        SAIQuantiteLivre->setObjectName("SAIQuantiteLivre");
        SAIQuantiteLivre->setGeometry(QRect(100, 110, 341, 22));

        retranslateUi(enregistrelivres);

        QMetaObject::connectSlotsByName(enregistrelivres);
    } // setupUi

    void retranslateUi(QWidget *enregistrelivres)
    {
        enregistrelivres->setWindowTitle(QCoreApplication::translate("enregistrelivres", "Interface d'enregistrement des livres", nullptr));
        labelauteur->setText(QCoreApplication::translate("enregistrelivres", "Auteur", nullptr));
        labeldateparution->setText(QCoreApplication::translate("enregistrelivres", "Date Parution", nullptr));
        QTableWidgetItem *___qtablewidgetitem = TableLivres->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("enregistrelivres", "Code Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = TableLivres->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("enregistrelivres", "Nom Livre", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = TableLivres->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("enregistrelivres", "Auteur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = TableLivres->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("enregistrelivres", "Date Parution", nullptr));
        labelcodelivre->setText(QCoreApplication::translate("enregistrelivres", "Code Livre", nullptr));
        labelnomlivre->setText(QCoreApplication::translate("enregistrelivres", "Nom du Livre", nullptr));
        BTNValider->setText(QCoreApplication::translate("enregistrelivres", "Valider", nullptr));
        BTNNouveau->setText(QCoreApplication::translate("enregistrelivres", "Nouveau", nullptr));
        labelquantite->setText(QCoreApplication::translate("enregistrelivres", "Quantit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enregistrelivres: public Ui_enregistrelivres {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGISTRELIVRES_H
