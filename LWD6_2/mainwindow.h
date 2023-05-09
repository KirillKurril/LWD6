#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <qcustomplot.h>
#include "hashtable.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_firstTable_button_clicked();

    void on_secondTable_button_clicked();

    void on_thirdTable_button_clicked();

    void on_fourthTable_button_clicked();

private:
    Ui::MainWindow *ui;
    QCustomPlot *wGraphic;
};
#endif // MAINWINDOW_H
