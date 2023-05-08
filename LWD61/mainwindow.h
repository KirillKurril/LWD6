#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "pair.h"
#include "avltree.h"
#include <QTreeWidgetItem>


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void Obhod();
    void display(AVLTree<QString>::Node* node, QTreeWidgetItem* parent);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    AVLTree<QString> dub;
    Pair<size_t, QString>* arr;
    size_t arr_size = 0;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
