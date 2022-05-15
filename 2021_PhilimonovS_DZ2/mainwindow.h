#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "picture.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    picture matrixWork;
    bool arr;
    bool del;
private slots:
    void on_btnLoad_clicked();
    void on_btnSave_clicked();
    void on_btnMask_clicked();
    void on_btndelotation_clicked();
    void on_btnArrozion_clicked();
    void on_btnFrame_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
