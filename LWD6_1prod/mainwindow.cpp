#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->resizeColumnsToContents();
    arr = new Pair<size_t, QString>[10];
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   size_t key = ui->lineEdit->text().toUInt();
   QString value = ui->lineEdit_2->text();
   Pair<size_t, QString> pair(key, value);
   arr[arr_size++] = pair;
   dub.Insert(key, value);
   for(int i = 0; i < arr_size; i++)
   {
       ui->tableWidget->setRowCount(i);
       ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(arr[i].first())));
       ui->tableWidget->setItem(i, 0, new QTableWidgetItem(arr[i].second()));
   }
}

