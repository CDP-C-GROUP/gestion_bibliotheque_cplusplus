/********************************************************************************
** Form generated from reading UI file 'enregistreclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENREGISTRECLIENT_H
#define UI_ENREGISTRECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_enregistrelivre
{
public:

    void setupUi(QWidget *enregistrelivre)
    {
        if (enregistrelivre->objectName().isEmpty())
            enregistrelivre->setObjectName(QString::fromUtf8("enregistrelivre"));
        enregistrelivre->resize(747, 375);

        retranslateUi(enregistrelivre);

        QMetaObject::connectSlotsByName(enregistrelivre);
    } // setupUi

    void retranslateUi(QWidget *enregistrelivre)
    {
        enregistrelivre->setWindowTitle(QApplication::translate("enregistrelivre", "enregistreclient", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enregistrelivre: public Ui_enregistrelivre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENREGISTRECLIENT_H
