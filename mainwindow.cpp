#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<sstream>
#include<string>
#include<QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->listWidget->close();
    ui->listWidget_2->close();
    ui->centralWidget->grabKeyboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//处理键盘事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int ch=event->key();
    if(isedit&&ch==Qt::Key_Left)//左右移动光标
    {
        edit=(edit>=now.size())?edit:edit+1;
        shownow();
    }
    else if(isedit&&ch==Qt::Key_Right)
    {
        edit=(edit<=0)?edit:edit-1;
        shownow();
    }
    else//其他按键
    {
        switch (ch) {
        case Qt::Key_0:
            on_pushButton_17_clicked();
            break;
        case Qt::Key_1:
            on_pushButton_8_clicked();
            break;
        case Qt::Key_2:
            on_pushButton_9_clicked();
            break;
        case Qt::Key_3:
            on_pushButton_10_clicked();
            break;
        case Qt::Key_4:
            on_pushButton_11_clicked();
            break;
        case Qt::Key_5:
            on_pushButton_12_clicked();
            break;
        case Qt::Key_6:
            on_pushButton_13_clicked();
            break;
        case Qt::Key_7:
            on_pushButton_14_clicked();
            break;
        case Qt::Key_8:
            on_pushButton_15_clicked();
            break;
        case Qt::Key_9:
            on_pushButton_16_clicked();
            break;
        case Qt::Key_Period:
            on_pushButton_18_clicked();
            break;
        case Qt::Key_ParenLeft:
            on_pushButton_19_clicked();
            break;
        case Qt::Key_ParenRight:
            on_pushButton_20_clicked();
            break;
        case Qt::Key_Equal:
            on_pushButton_5_clicked();
            break;
        case Qt::Key_Plus:
            on_pushButton_clicked();
            break;
        case Qt::Key_Minus:
            on_pushButton_3_clicked();
            break;
        case Qt::Key_E:
            on_pushButton_30_clicked();
            break;
        case Qt::Key_Asterisk:
            on_pushButton_2_clicked();
            break;
        case Qt::Key_Exclam:
            on_pushButton_31_clicked();
            break;
        case Qt::Key_Slash:
            on_pushButton_4_clicked();
            break;
        case Qt::Key_Backspace:
            on_pushButton_6_clicked();
            break;
        case Qt::Key_AsciiCircum:
            on_pushButton_25_clicked();
            break;
        case Qt::Key_G:
            on_pushButton_24_clicked();
            break;
        case Qt::Key_Percent:
            on_pushButton_26_clicked();
            break;
        case Qt::Key_Up:
            on_pushButton_35_clicked();
            break;
        case Qt::Key_S:
            on_pushButton_21_clicked();
            break;
        case Qt::Key_C:
            on_pushButton_22_clicked();
            break;
        case Qt::Key_T:
            on_pushButton_23_clicked();
            break;
        case Qt::Key_L:
            on_pushButton_27_clicked();
            break;
        case Qt::Key_P:
            on_pushButton_29_clicked();
            break;
        default:
            break;
        }
    }
}

void MainWindow::shownow()//根据当前键入的按键数组生成字符串形式的表达式并显示出来
{
    outs.clear();
    int l=now.size();
    for(int i=0;i<l;++i)
    {
        if(isedit&&i==l-edit)
            outs+="_";//光标
        else
            outs=outs+now[i];
    }
    ui->textBrowser->setText(outs);
}

void MainWindow::on_pushButton_clicked()//按键按下事件，此为“+”，下同
{
    now.insert(now.end()-edit,"+");
    shownow();
}

void MainWindow::on_pushButton_18_clicked()
{
    now.insert(now.end()-edit,".");
    shownow();
}

void MainWindow::on_pushButton_17_clicked()
{
    now.insert(now.end()-edit,"0");
    shownow();
}

void MainWindow::on_pushButton_19_clicked()
{
    now.insert(now.end()-edit,"(");
    shownow();
}

void MainWindow::on_pushButton_20_clicked()
{
    now.insert(now.end()-edit,")");
    shownow();
}

void MainWindow::on_pushButton_29_clicked()
{
    now.insert(now.end()-edit,"π");
    shownow();
}

void MainWindow::on_pushButton_8_clicked()
{
    now.insert(now.end()-edit,"1");
    shownow();
}

void MainWindow::on_pushButton_9_clicked()
{
    now.insert(now.end()-edit,"2");
    shownow();
}

void MainWindow::on_pushButton_10_clicked()
{
    now.insert(now.end()-edit,"3");
    shownow();
}

void MainWindow::on_pushButton_30_clicked()
{
    now.insert(now.end()-edit,"e");
    shownow();
}

void MainWindow::on_pushButton_11_clicked()
{
    now.insert(now.end()-edit,"4");
    shownow();
}

void MainWindow::on_pushButton_12_clicked()
{
    now.insert(now.end()-edit,"5");
    shownow();
}

void MainWindow::on_pushButton_13_clicked()
{
    now.insert(now.end()-edit,"6");
    shownow();
}

void MainWindow::on_pushButton_3_clicked()
{
    now.insert(now.end()-edit,"-");
    shownow();
}

void MainWindow::on_pushButton_31_clicked()
{
    now.insert(now.end()-edit,"!");
    shownow();
}

void MainWindow::on_pushButton_14_clicked()
{
    now.insert(now.end()-edit,"7");
    shownow();
}

void MainWindow::on_pushButton_15_clicked()
{
    now.insert(now.end()-edit,"8");
    shownow();
}

void MainWindow::on_pushButton_16_clicked()
{
    now.insert(now.end()-edit,"9");
    shownow();
}

void MainWindow::on_pushButton_2_clicked()
{
    now.insert(now.end()-edit,"×");
    shownow();
}

void MainWindow::on_pushButton_24_clicked()
{
    now.insert(now.end()-edit,"√");
    shownow();
}

void MainWindow::on_pushButton_25_clicked()
{
    now.insert(now.end()-edit,"^");
    shownow();
}

void MainWindow::on_pushButton_4_clicked()
{
    now.insert(now.end()-edit,"÷");
    shownow();
}

void MainWindow::on_pushButton_21_clicked()
{
    now.insert(now.end()-edit,"sin(");
    shownow();
}

void MainWindow::on_pushButton_32_clicked()
{
    now.insert(now.end()-edit,"asin(");
    shownow();
}

void MainWindow::on_pushButton_22_clicked()
{
    now.insert(now.end()-edit,"cos(");
    shownow();
}

void MainWindow::on_pushButton_33_clicked()
{
    now.insert(now.end()-edit,"acos(");
    shownow();
}

void MainWindow::on_pushButton_23_clicked()
{
    now.insert(now.end()-edit,"tan(");
    shownow();
}

void MainWindow::on_pushButton_34_clicked()
{
    now.insert(now.end()-edit,"atan(");
    shownow();
}

void MainWindow::on_pushButton_27_clicked()
{
    now.insert(now.end()-edit,"ln(");
    shownow();
}

void MainWindow::on_pushButton_28_clicked()
{
    now.insert(now.end()-edit,"log(");
    shownow();
}

void MainWindow::on_pushButton_26_clicked()
{
    now.insert(now.end()-edit,"%");
    shownow();
}

void MainWindow::on_pushButton_6_clicked()//backspace键，根据变量edit的值决定删除的位置
{
    if(!now.empty()&&edit<now.size()) now.erase(now.end()-edit-1,now.end()-edit),shownow();
}

void MainWindow::on_pushButton_7_clicked()//clear键
{
    now.clear();
    outs.clear();
    ui->textBrowser->clear();
    edit=0;
}

void MainWindow::change(QString &cs)//将当前按下的键组成的数组转化成cal()函数使用的字符串
{
    cs.clear();
    int l=now.size();
    for(int i=0;i<l;++i)
    {
        if(now[i]=="π") cs+="P";
        else if(now[i]=="e") cs+="E";
        else if(now[i]=="×") cs+="*";
        else if(now[i]=="÷") cs+="/";
        else if(now[i]=="√") cs+="g";
        else if(now[i]=="sin(") cs+="s(";
        else if(now[i]=="asin(") cs+="S(";
        else if(now[i]=="cos(") cs+="c(";
        else if(now[i]=="acos(") cs+="C(";
        else if(now[i]=="tan(") cs+="t(";
        else if(now[i]=="atan(") cs+="T(";
        else if(now[i]=="ln(") cs+="l(";
        else if(now[i]=="log(") cs+="L(";
        else cs+=now[i];
    }
}

void MainWindow::on_pushButton_5_clicked()//等于“=”键按下
{
    if(isedit)//强制edit归零，清除光标
    {
        edit=0;
        shownow();
    }

    std::stringstream ss;
    change(s);
    if(!checkparen())//检查可能导致程序终止的括号不匹配情况，并给予修改机会
    {
        ui->textBrowser_2->setText("括号未匹配");
        return;
    }

    s.push_back('#');//增加结束标识
    QChar ch;
    while(true)//开始计算
    {
        ch=s[cur++];//每次读取一个字符
        if ((ch >= '0'&&ch <= '9') || ch == '.') ss << (char)ch.unicode();
        else if (ch == 'E') ss <<std::setprecision(1000)<< E;
        else if (ch == 'P') ss <<std::setprecision(1000)<< P;
        else//当ch不是数字：
        {
            double temp = 0;
            if (ss >> std::setprecision(1000) >> temp) num.push(temp);//数字入栈
            ss.str("");
            ss.clear();

            if (ch == ')' || ch == '#')//遇到右括号或终止符
            {
                while (!op.empty() && op.top() != '(')
                {
                    QChar ch0 = op.top();
                    cal(ch0);
                    op.pop();
                }
                if (ch == '#') break;
                else op.pop();
            }
            else if (ch != '(' && !op.empty())//忽略左括号或无操作符情况
            {
                QChar ch0 = op.top();
                while (cmp(ch0, ch))
                {
                    op.pop();
                    cal(ch0);
                    if (op.empty()) break;
                    ch0 = op.top();
                }
            }

            if (ch != ')') op.push(ch);//操作符入栈
            if(ch=='+'||ch=='-') pos.push(cur-1);//记录加减的位置，判断其是一元还是二元运算
        }
    }
    if(!num.empty())//组织答案
    {
        double ans=num.top();
        if(fabs(ans - 0)<Exp) ans=0;
        QString tempp;
        std::string tem;
        ss<<std::setprecision(15)<<ans;
        ss>>tem;
        tempp=QString::fromStdString(tem);
        ui->textBrowser_2->setText(tempp);

        //加入历史记录
        now_his.push_back(now);
        ui->listWidget->addItem(outs);
        ui->listWidget_2->addItem(tempp);

    }

    //清尾工作
    ss.str("");
    ss.clear();
    while (!num.empty()) num.pop();
    while (!op.empty()) op.pop();
    while (!pos.empty()) pos.pop();
    cur = 0;
    s.clear();
    outs.clear();
    now.clear();
}

bool MainWindow::cmp(QChar ch0,QChar ch1)//比较操作符优先级
{
    if (ch0 == '(') return false;
        if (ch1 == '+' || ch1 == '-')
        {
            QChar ch = s[cur - 2];
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == 'g'||ch=='%') return false;
            return true;
        }
        else if ((ch1 == '*' || ch1 == '/' || ch1 == '%') && (ch0 != '+'&&ch0 != '-')) return true;
        else if ((ch1 == '^') && (ch0=='!'||ch0 == 's' || ch0 == 'c' || ch0 == 't' || ch0 == 'L' || ch0 == 'l' || ch0 == 'g')) return true;
        else if (ch1 == '!'&&(ch0=='!'|| ch0 == 's' || ch0 == 'c' || ch0 == 't' || ch0 == 'L' || ch0 == 'l' || ch0 == 'g')) return true;
        return false;
}

double MainWindow::jie(double n)//阶乘
{
    long long num1 = n;
    long long ans = 1;
    while ((num1--) > 0) ans *= (num1 + 1);
    return ans;
}

void MainWindow::cal(QChar ch)//根据ch确定计算过程
{
    double num2 =0, num1 = 0;
    double res = 0;
    if(num.empty()) return;
    switch (ch.unicode())
    {
    case '+':
    case '-':
    {
        num2 = num.top(), num.pop();
        int p=pos.top();
        pos.pop();
        if (p==0||s[p-1]=='('||s[p-1]=='*'||s[p-1]=='/'||s[p-1]=='%'||s[p-1]=='g'||s[p-1]=='+'||s[p-1]=='-')//一元
        {
            if (ch == '+') res = num2;
            else if (ch == '-') res = -num2;
        }
        else//二元
        {
            if(num.empty()) break;
            num1 = num.top(), num.pop();
            if (ch == '+') res = num1 + num2;
            else res = num1 - num2;
        }
    }
    break;
    case '!':
    {
        num2 = num.top(), num.pop();
        res = jie(num2);
    }
    break;
    case 's':
        num2 = num.top(), num.pop();
        if(isangle) num2*=(P/180);
        res = sin(num2);
        break;
    case 'c':
        num2 = num.top(), num.pop();
        if(isangle) num2*=(P/180);
        res = cos(num2);
        break;
    case 't':
        num2 = num.top(), num.pop();
        if(isangle) num2*=(P/180);
        res = tan(num2);
        break;
    case 'L':
        num2 = num.top(), num.pop();
        res= log10(num2);
        break;
    case 'l':
        num2 = num.top(), num.pop();
        res = log(num2);
        break;
    case 'g':
        num2 = num.top(), num.pop();
        res = pow(num2, 0.5);
        break;
    case 'S':
        num2 = num.top(), num.pop();
        res = asin(num2);
        if(isangle) res=res/P*180;
        break;
    case 'C':
        num2 = num.top(), num.pop();
        res = acos(num2);
        if(isangle) res=res/P*180;
        break;
    case 'T':
        num2 = num.top(), num.pop();
        res = atan(num2);
        if(isangle) res=res/P*180;
        break;
    case '^':
    case '*':
    case '/':
    case '%':
        num2 = num.top(), num.pop();
        if(num.empty()) break;
        num1 = num.top(), num.pop();
        if (ch == '^') res = pow(num1, num2);
        else if (ch == '*') res = num1*num2;
        else if (ch == '/') res = num1 / num2;
        else res = fmod(num1, num2);
    }
    num.push(res);
}

void MainWindow::on_pushButton_35_clicked()//开启/关闭历史记录面板
{
    if(clicked) ui->listWidget->close(),ui->listWidget_2->close();
    else ui->listWidget->show(),ui->listWidget_2->show();
    clicked=!clicked;
}

void MainWindow::on_listWidget_clicked(const QModelIndex &index)//点击某条历史记录，下同
{
    edit=0;
    now=now_his[index.row()];
    shownow();
    clicked=!clicked;
    ui->listWidget->close();
    ui->listWidget_2->close();
}

void MainWindow::on_listWidget_2_clicked(const QModelIndex &index)
{
    edit=0;
    QString temp=ui->listWidget_2->item(index.row())->text();
    now.push_back(temp);
    shownow();
    clicked=!clicked;
    ui->listWidget->close();
    ui->listWidget_2->close();
}

void MainWindow::on_checkBox_clicked()//进入/退出编辑状态
{
    isedit=!isedit;
    edit=0;
    shownow();
}

bool MainWindow::checkparen()//检查括号不匹配情况
{
    int mark=0;
    int l=s.length();
    for(int i=0;i<l;++i)
    {
        if(s[i]=='(') ++mark;
        else if(s[i]==')') --mark;
    }
    if(mark==0) return true;
    else return false;
}

void MainWindow::on_action_4_triggered()//About
{
    QMessageBox msg;
    msg.setText("Version: v1.0\nSCUT, GuangZhou, China.\nAll rights reserved\n2018/7/13\nPowered by Qt");
    msg.exec();
}

void MainWindow::on_checkBox_2_clicked()//切换角度制/弧度制
{
    isangle=!isangle;
}
