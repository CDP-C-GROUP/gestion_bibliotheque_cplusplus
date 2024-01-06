#include "enregistrelivres.h"
#include "ui_enregistrelivres.h"

enregistrelivres::enregistrelivres(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::enregistrelivres)
{
    ui->setupUi(this);
}

enregistrelivres::~enregistrelivres()
{
    delete ui;
}
void enregistrelivres::on_BTNValider_clicked()
{

}

