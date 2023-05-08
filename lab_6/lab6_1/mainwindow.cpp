#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=0;i<9;++i)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(""));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(""));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushInfo_button_clicked()
{
    int counter = 0;
    while(!ui->tableWidget->item(counter,1)->text().isEmpty())
    {
        tree.root = tree.insert(tree.root,ui->tableWidget->item(counter,0)->text().toInt(),ui->tableWidget->item(counter,1)->text().toStdString());
        ++counter;
    }

}

void MainWindow::on_delete_button_clicked()
{
    tree.deleteNode(tree.root, ui->plainTextEdit->toPlainText().toInt());
}

void MainWindow::on_find_button_clicked()
{
    QMessageBox::information(this,"Find",tree.findNode(tree.root,ui->plainTextEdit_2->toPlainText().toInt())->value.c_str());
}

void MainWindow::on_printTree_button_clicked()
{
    std::vector<std::string> vector;
    tree.directBypass(tree.root, vector);
    std::string information;
    while(!vector.empty())
    {
        information += (vector.at(vector.size() - 1));
        vector.pop_back();
    }
    QMessageBox::information(this,"Print",information.c_str());
}

