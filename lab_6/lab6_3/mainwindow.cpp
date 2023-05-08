#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    HashTable h(25);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->clear();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);
    for(int i = 0; i < 20;++i)
    {
        int key = dis(gen);
        h.add(QString::number(key).toStdString(), QString::number(key).toStdString());
    }

    QString s = h.print();
    QString information;
    int counter = 0;
    for(int i = 0;i < s.size();++i)
    {
        if(s[i]==' ')
        {
            ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(information));
            information.clear();
            continue;
        }
        if(s[i]=='\n')
        {
            ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(information));
            information.clear();
            ++counter;
            continue;
        }
        information.push_back(s[i]);
    }
}


void MainWindow::on_doTask_button_clicked()
{
    for(int i = -1;i>-11;--i)
    {
        h.remove(QString::number(i).toStdString());
    }
    ui->tableWidget->clear();
    QString s = h.print();
    QString information;
    int counter = 0;
    for(int i = 0;i < s.size();++i)
    {
        if(s[i]==' ')
        {
            ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(information));
            information.clear();
            continue;
        }
        if(s[i]=='\n')
        {
            ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(information));
            information.clear();
            ++counter;
            continue;
        }
        information.push_back(s[i]);
    }
}

