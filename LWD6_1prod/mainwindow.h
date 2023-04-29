#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "searchtree.h"
#include "pair.h"
#include "vector.h"
#include "searchtree.cpp"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    SearchTree<QString> dub;
    Pair<size_t, QString>* arr;
    size_t arr_size = 0;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
