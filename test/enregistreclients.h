#ifndef ENREGISTRECLIENTS_H
#define ENREGISTRECLIENTS_H


#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class enregistreclients; }
QT_END_NAMESPACE

class enregistreclients : public QWidget
{
    Q_OBJECT

public:
    enregistreclients(QWidget *parent = nullptr);
    ~enregistreclients();

private slots:
    void on_BTNValider_clicked();

    void on_BTNNouveau_clicked();

    void on_enregistreclients_windowTitleChanged(const QString &title);

private:
    Ui::enregistreclients *ui;
};




#endif // ENREGISTRECLIENTS_H
