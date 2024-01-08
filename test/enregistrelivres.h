#ifndef ENREGISTRELIVRES_H
#define ENREGISTRELIVRES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class enregistrelivres; }
QT_END_NAMESPACE

class enregistrelivres : public QWidget
{
    Q_OBJECT

public:
    enregistrelivres(QWidget *parent = nullptr);
    ~enregistrelivres();

private slots:
    void on_BTNValider_clicked();

    void on_BTNNouveau_clicked();

    void on_enregistrelivres_windowTitleChanged(const QString &title);

private:
    Ui::enregistrelivres *ui;
};
#endif // ENREGISTRELIVRES_H
