#include "maskin.h"
#include "ui_maskin.h"
#include "mainwindow.h"

maskIn::maskIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::maskIn)
{
    ui->setupUi(this);
}

maskIn::~maskIn()
{
    delete ui;
}

void maskIn::on_pushButton_2_clicked(){
    MainWindow maskgeer;
    QString one = ui->lineEdit->text();
    QString two = ui->lineEdit_2->text();
    QString three = ui->lineEdit_5->text();
    QString four = ui->lineEdit_6->text();
    maskgeer.maska(one.toInt(),two.toInt(),three.toInt(),four.toInt());
    hide();
}

void maskIn::on_pushButton_clicked(){
   MainWindow maskgeer;
   maskgeer.maska(1,1,1,1);
   hide();
}
