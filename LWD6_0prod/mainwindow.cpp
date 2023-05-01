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
       ui->tableWidget->setRowCount(arr_size);
       ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(arr[i].first())));
       ui->tableWidget->setItem(i, 1, new QTableWidgetItem(arr[i].second()));
   }
    QString situation;
    dub.pre_order_traversal(dub.GetRoot(), situation);
    situation += '\n';
    dub.in_order_traversal(dub.GetRoot(), situation);
    situation += '\n';
    dub.post_order_traversal(dub.GetRoot(), situation);
    situation += '\n';
    ui->plainTextEdit->setPlainText(situation);
}


void MainWindow::on_pushButton_2_clicked()
{
    size_t key = ui->lineEdit->text().toUInt();
    ui->lineEdit_2->setText(dub.RecSearch(key));
}


void MainWindow::on_pushButton_5_clicked()
{
    dub.Insert(6,"6");
    dub.Insert(2,"2");
    dub.Insert(7,"7");
    dub.Insert(1,"1");
    dub.Insert(4,"4");
    dub.Insert(9,"9");
    dub.Insert(3,"3");
    dub.Insert(5,"5");
    dub.Insert(8,"8");
    QString situation;
    dub.pre_order_traversal(dub.GetRoot(), situation);
    situation += '\n';
    dub.in_order_traversal(dub.GetRoot(), situation);
    situation += '\n';
    dub.post_order_traversal(dub.GetRoot(), situation);
    situation += '\n';
    ui->plainTextEdit->setPlainText(situation);
}

