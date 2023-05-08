#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    dub.root = dub.insert(dub.root, 6,"6");
    ui->tableWidget->setItem(0,0, new QTableWidgetItem("6"));
    ui->tableWidget->setItem(0,1, new QTableWidgetItem("6"));
    dub.root = dub.insert(dub.root, 2,"2");
    ui->tableWidget->setItem(1,0, new QTableWidgetItem("2"));
    ui->tableWidget->setItem(1,1, new QTableWidgetItem("2"));
    dub.root = dub.insert(dub.root, 7,"7");
    ui->tableWidget->setItem(2,0, new QTableWidgetItem("7"));
    ui->tableWidget->setItem(2,1, new QTableWidgetItem("7"));
    dub.root = dub.insert(dub.root, 1,"1");
    ui->tableWidget->setItem(3,0, new QTableWidgetItem("1"));
    ui->tableWidget->setItem(3,1, new QTableWidgetItem("1"));
    dub.root = dub.root = dub.insert(dub.root, 4,"4");
    ui->tableWidget->setItem(4,0, new QTableWidgetItem("4"));
    ui->tableWidget->setItem(4,1, new QTableWidgetItem("4"));
    dub.root = dub.insert(dub.root, 9,"9");
    ui->tableWidget->setItem(5,0, new QTableWidgetItem("9"));
    ui->tableWidget->setItem(5,1, new QTableWidgetItem("9"));
    dub.root = dub.insert(dub.root, 3,"3");
    ui->tableWidget->setItem(6,0, new QTableWidgetItem("3"));
    ui->tableWidget->setItem(6,1, new QTableWidgetItem("3"));
    dub.root = dub.insert(dub.root, 5,"5");
    ui->tableWidget->setItem(7,0, new QTableWidgetItem("5"));
    ui->tableWidget->setItem(7,1, new QTableWidgetItem("5"));
    dub.root = dub.insert(dub.root, 8,"8");
    ui->tableWidget->setItem(8,0, new QTableWidgetItem("8"));
    ui->tableWidget->setItem(8,1, new QTableWidgetItem("8"));
    Obhod();
}

void MainWindow::on_pushButton_clicked()
{
    for (int i = 0; ui->tableWidget->rowCount(); i++)
    {
        if (ui->tableWidget->item(i, 0) == nullptr || ui->tableWidget->item(i, 0)->text().isEmpty()) {
                    break;
                }
        dub.root = dub.insert(dub.root, ui->tableWidget->item(i,0)->text().toInt(),ui->tableWidget->item(i,1)->text());
    }
    Obhod();
}


void MainWindow::on_pushButton_6_clicked()
{
    dub.root = nullptr;
    ui->tableWidget->clear();
    Obhod();
}

void MainWindow::display(Node* node, QTreeWidgetItem* parent) {
    if (node == nullptr) {
        return;
    }
    QTreeWidgetItem* item = new QTreeWidgetItem(parent);
    item->setText(0, node->data_);
    display(node->left, item);
    display(node->right, item);
}

void MainWindow::Obhod()
{
    size_t ct = 0;
    QString situation, counter;
    dub.pre_order_traversal(dub.root, situation, ct);
    counter = QString::number(ct);
    situation += '\n';
    dub.in_order_traversal(dub.root, situation, ct);
    situation += '\n';
    dub.post_order_traversal(dub.root, situation,ct);
    situation += "\nAmount of chars: " + counter;
    ui->plainTextEdit->setPlainText(situation);

    ui->treeWidget->clear();
        QTreeWidgetItem* rootItem = new QTreeWidgetItem(ui->treeWidget);
        rootItem->setText(0, "Root");

        display(dub.root, rootItem);

        ui->treeWidget->expandAll();
}

void MainWindow::on_pushButton_3_clicked()
{
    dub.deleteNode(dub.root,ui->lineEdit->text().toInt());
    Obhod();
}


void MainWindow::on_pushButton_2_clicked()
{
    Node* nd = dub.findNode(dub.root, ui->lineEdit->text().toInt());
     if(nd)ui->lineEdit_2->setText(nd->data_);
}

