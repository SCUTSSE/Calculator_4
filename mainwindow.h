#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<cmath>
#include<iomanip>
#include<QStack>
#include<QVector>
#include<QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    bool cmp(QChar,QChar);

    double jie(double);

    void cal(QChar);

    void shownow();

    void on_pushButton_35_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

    void on_listWidget_2_clicked(const QModelIndex &index);

    void change(QString&);

    void keyPressEvent(QKeyEvent *event);

    void on_checkBox_clicked();

    bool checkparen();

    void on_action_4_triggered();

    void on_checkBox_2_clicked();

private:
    Ui::MainWindow *ui;
    QString s;//计算用字符串
    QString outs;//显示用字符串

    //一些常量
    const double Exp=1e-12;
    const double E = exp(1);
    const double P = acos(-1);

    //一些容器
    QStack<double>num;
    QStack<QChar>op;
    QStack<int>pos;
    int cur = 0;

    //历史记录
    QVector<QString>now;
    QVector<QVector<QString>>now_his;

    //一些变量
    bool clicked=0;
    unsigned int edit=0;
    bool isedit=false;
    bool isangle=false;
};

#endif // MAINWINDOW_H
