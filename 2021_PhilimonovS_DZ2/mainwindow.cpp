#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QComboBox>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QColor>
#include <QObject>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow){
    ui->setupUi(this);
    del = false;
    arr = false;
    ui->btnFrame->setEnabled(false);
    ui->btndelotation->setEnabled(false);
    ui->btnArrozion->setEnabled(false);
    ui->btnLoad->setEnabled(false);
    ui->btnSave->setEnabled(false);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MainWindow::~MainWindow(){
    delete ui;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_btnMask_clicked(){
    matrixWork.SetAConditonMask(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt(), ui->lineEdit_3->text().toInt(), ui->lineEdit_4->text().toInt());
    ui->btnLoad->setEnabled(true);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_btnLoad_clicked(){
    QString file_load = QFileDialog::getOpenFileName(this, "Открыть файл");
    QPixmap pix(file_load);
    if (pix.isNull()){
        QMessageBox::warning(this, "Ошибка", "вы пытайтесь открыть не картинку");
    }
    else {
        matrixWork.InputImage(file_load);
        ui->btndelotation->setEnabled(true);
        ui->btnArrozion->setEnabled(true);
        ui->btnMask->setEnabled(false);
        ui->btnLoad->setEnabled(false);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_btndelotation_clicked(){
    matrixWork.Delotation();
    del = true;
    if(arr && del){
        ui->btnFrame->setEnabled(true);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_btnArrozion_clicked(){ 
    matrixWork.Arrozion();
    arr = true;
    if(arr && del){
        ui->btnFrame->setEnabled(true);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_btnFrame_clicked(){
    matrixWork.Frame();
    ui->btnSave->setEnabled(true);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_btnSave_clicked(){
    QString file_save = QFileDialog::getSaveFileName(this, "Открыть файл");
    if(!file_save.isEmpty()){
        matrixWork.OutputImage(file_save, ui->combo->currentIndex());
        ui->btnFrame->setEnabled(false);
        ui->btndelotation->setEnabled(false);
        ui->btnArrozion->setEnabled(false);
        ui->btnLoad->setEnabled(false);
        ui->btnSave->setEnabled(false);
        ui->btnMask->setEnabled(true);
    }
    else {
        QMessageBox::warning(this, "Ошибка", "картинки нет");
    }
}
