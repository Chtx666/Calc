#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(490, 460);
    this->setMinimumSize(490, 460);
    this->setWindowTitle("Calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_oneButton_clicked()
{
    expression += "1";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_zeroButton_clicked()
{
    expression += "0";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_leftButton_clicked()
{
    expression += "(";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_rightButton_clicked()
{
    expression += ")";
    ui->lineEdit->setText(expression);
}

int evaluateExpression(const string& expression) {
    stack<int> values;        // 存储操作数
    stack<char> operators;    // 存储运算符

    // 运算符优先级
    unordered_map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
    };

    // 运算符计算
    auto applyOperator = [](int a, int b, char op) -> int {
        switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw invalid_argument("Division by zero");
            return a / b;
        default: throw invalid_argument("Unknown operator");
        }
    };

    for (int i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (isspace(c)) continue; // 忽略空格

        if (isdigit(c)) { // 如果是数字
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; // 回退一个位置，因为for循环还会递增i
            values.push(num);
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperator(val1, val2, op));
            }
            operators.pop(); // 弹出 '('
        }
        else if (precedence.find(c) != precedence.end()) { // 运算符 + - * /
            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperator(val1, val2, op));
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOperator(val1, val2, op));
    }

    return values.top();  // 最后栈中只有一个值，就是结果
}

void MainWindow::on_equalButton_clicked()
{
    expression = QString::number(evaluateExpression(expression.toStdString()));
    ui->lineEdit->setText(expression);
}


void MainWindow::on_threeButton_clicked()
{
    expression += "3";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_twoButton_clicked()
{
    expression += "2";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_sixButton_clicked()
{
    expression += "6";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_fiveButton_clicked()
{
    expression += "5";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_fourButton_clicked()
{
    expression += "4";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_nineButton_clicked()
{
    expression += "9";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_eightButton_clicked()
{
    expression += "8";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_multiButton_clicked()
{
    expression += "*";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_divideButton_clicked()
{
    expression += "/";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_sevenButton_clicked()
{
    expression += "7";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_subButton_clicked()
{
    expression += "-";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_addButton_clicked()
{
    expression += "+";
    ui->lineEdit->setText(expression);
}


void MainWindow::on_clrButton_clicked()
{
    expression.clear();
    ui->lineEdit->clear();
}


void MainWindow::on_delButton_clicked()
{
    expression.chop(1);
    ui->lineEdit->setText(expression);
}

