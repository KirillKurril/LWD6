#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mystack.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_5_clicked()
{
    for(int i = 0; i < 5; i++)
    {
        int key = std::rand()%100;
        QString value = QString::number(key);
        stol.insert(key, value);
    }
    luk();
}

void MainWindow::luk()
{
    ui->tableWidget->clear();

    int j = 0;
    for(int i = 0; i < 5; ++i)
    {
        Node* ptr = stol.m_table[i].topElement();
        for(; ptr; j++, ptr = ptr->prev)
        {
            ui->tableWidget->setItem(j, 0, new QTableWidgetItem(QString::number(ptr->element.first)));
            ui->tableWidget->setItem(j, 1, new QTableWidgetItem(ptr->element.second));

        }
        j++;
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit_3->text();
    int key = ui->lineEdit_2->text().toInt();
    stol.insert(key, str);
    luk();
}

