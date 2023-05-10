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


void MainWindow::on_pushButton_2_clicked()
{
    int key = ui->lineEdit_4->text().toInt();
    ui->lineEdit->setText(stol.get(key));
}


void MainWindow::on_pushButton_3_clicked()
{
    int key = ui->lineEdit_5->text().toInt();
    stol.remove(key);
    luk();
}


void MainWindow::on_pushButton_4_clicked()
{
    int min = INT32_MAX, num;
    for(int i = 0; i < stol.m_size; i++)
    {
        Node* ptr = stol.m_table[i].topElement();
        while(ptr)
        {
            if (ptr->element.first < min)
            {
                min = ptr->element.first;
                num = i;
            }

            ptr = ptr->prev;
        }
    }
    ui->lineEdit_6->setText("Min key value: " + QString::number(min) + " hash index: " + QString::number(num));
}

