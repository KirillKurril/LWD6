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


void MainWindow::on_firstTable_button_clicked()
{
    HashTable h(16);
    while(ui->gridLayout->count() > 0)
    {
        QLayoutItem* item = ui->gridLayout->takeAt(0);
        delete item->widget();
        delete item;
    }
    wGraphic = new QCustomPlot();
    ui->gridLayout->addWidget(wGraphic,1,0,1,1);
    QVector<double> x1(5),y1(5);
    for(int i = 0;i<16;++i)
    {
        std::string s = QString::number(rand()%5).toStdString();
        h.add(s,s);
    }
    int times = 0;
    for(int i = 500; times < 4; i *= 5)
    {
        QElapsedTimer timer;
        timer.start();
        for(int j = 0 ; j < i; ++j)
        {
            h.find(QString::number(rand()%5).toStdString());
        }
        x1[times] = i;
        y1[times] = timer.elapsed();
        qDebug() << "Elapsed time:" << timer.elapsed() << "milliseconds";
        ++times;
    }
    wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
    wGraphic->graph(0)->setData(x1,y1);
    wGraphic->xAxis->setLabel("count of finds");
    wGraphic->yAxis->setLabel("time, ms");
    wGraphic->xAxis->setRange(0,x1.at(3));
    wGraphic->yAxis->setRange(0,y1.at(3));
    wGraphic->replot();

}


void MainWindow::on_secondTable_button_clicked()
{
    HashTable h(64);
    while(ui->gridLayout->count() > 0)
    {
        QLayoutItem* item = ui->gridLayout->takeAt(0);
        delete item->widget();
        delete item;
    }
    wGraphic = new QCustomPlot();
    ui->gridLayout->addWidget(wGraphic,1,0,1,1);
    QVector<double> x1(5),y1(5);
    for(int i = 0;i<64;++i)
    {
        std::string s = QString::number(rand()%20).toStdString();
        h.add(s,s);
    }
    int times = 0;
    for(int i = 500; times < 4; i *= 5)
    {
        QElapsedTimer timer;
        timer.start();
        for(int j = 0 ; j < i; ++j)
        {
            h.find(QString::number(rand()%20).toStdString());
        }
        x1[times] = i;
        y1[times] = timer.elapsed();
        qDebug() << "Elapsed time:" << timer.elapsed() << "milliseconds";
        ++times;
    }
    wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
    wGraphic->graph(0)->setData(x1,y1);
    wGraphic->xAxis->setLabel("count of finds");
    wGraphic->yAxis->setLabel("time, ms");
    wGraphic->xAxis->setRange(0,x1.at(3));
    wGraphic->yAxis->setRange(0,y1.at(3));
    wGraphic->replot();
}


void MainWindow::on_thirdTable_button_clicked()
{
    HashTable h(128);
    while(ui->gridLayout->count() > 0)
    {
        QLayoutItem* item = ui->gridLayout->takeAt(0);
        delete item->widget();
        delete item;
    }
    wGraphic = new QCustomPlot();
    ui->gridLayout->addWidget(wGraphic,1,0,1,1);
    QVector<double> x1(5),y1(5);
    for(int i = 0;i<128;++i)
    {
        std::string s = QString::number(rand()%40).toStdString();
        h.add(s,s);
    }
    int times = 0;
    for(int i = 500; times < 4; i *= 5)
    {
        QElapsedTimer timer;
        timer.start();
        for(int j = 0 ; j < i; ++j)
        {
            h.find(QString::number(rand()%40).toStdString());
        }
        x1[times] = i;
        y1[times] = timer.elapsed();
        qDebug() << "Elapsed time:" << timer.elapsed() << "milliseconds";
        ++times;
    }
    wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
    wGraphic->graph(0)->setData(x1,y1);
    wGraphic->xAxis->setLabel("count of finds");
    wGraphic->yAxis->setLabel("time, ms");
    wGraphic->xAxis->setRange(0,x1.at(3));
    wGraphic->yAxis->setRange(0,y1.at(3));
    wGraphic->replot();
}


void MainWindow::on_fourthTable_button_clicked()
{
    HashTable h(2048);
    while(ui->gridLayout->count() > 0)
    {
        QLayoutItem* item = ui->gridLayout->takeAt(0);
        delete item->widget();
        delete item;
    }
    wGraphic = new QCustomPlot();
    ui->gridLayout->addWidget(wGraphic,1,0,1,1);
    QVector<double> x1(5),y1(5);
    for(int i = 0;i<2048;++i)
    {
        std::string s = QString::number(rand()%640).toStdString();
        h.add(s,s);
    }
    int times = 0;
    for(int i = 500; times < 4; i *= 5)
    {
        QElapsedTimer timer;
        timer.start();
        for(int j = 0 ; j < i; ++j)
        {
            h.find(QString::number(rand()%640).toStdString());
        }
        x1[times] = i;
        y1[times] = timer.elapsed();
        qDebug() << "Elapsed time:" << timer.elapsed() << "milliseconds";
        ++times;
    }
    wGraphic->addGraph(wGraphic->xAxis, wGraphic->yAxis);
    wGraphic->graph(0)->setData(x1,y1);
    wGraphic->xAxis->setLabel("count of finds");
    wGraphic->yAxis->setLabel("time, ms");
    wGraphic->xAxis->setRange(0,x1.at(3));
    wGraphic->yAxis->setRange(0,y1.at(3));
    wGraphic->replot();
}

