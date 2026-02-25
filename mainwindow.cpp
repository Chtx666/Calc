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

double evaluateExpression(const string& expression) {
    stack<double> values;        // 存储操作数
    stack<char> operators;       // 存储运算符

    // 运算符优先级
    unordered_map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
        {'/', 2}
    };

    // 运算符计算
    auto applyOperator = [](double a, double b, char op) -> double {
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

    bool lastWasOperatorOrLeftParen = true; // 记录上一个字符是否是运算符或左括号

    for (int i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (isspace(c)) continue; // 忽略空格

        if (isdigit(c) || c == '.') { // 处理数字和小数点
            double num = 0;
            double fraction = 0;
            int fracDiv = 1;
            bool isFraction = false;

            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                if (expression[i] == '.') {
                    if (isFraction) throw invalid_argument("Invalid number format: multiple decimal points"); // 避免多次小数点
                    isFraction = true;
                } else {
                    if (!isFraction) {
                        num = num * 10 + (expression[i] - '0');
                    } else {
                        fraction = fraction * 10 + (expression[i] - '0');
                        fracDiv *= 10;
                    }
                }
                i++;
            }
            i--; // 回退一个位置，因为while会继续递增i
            num += fraction / fracDiv;
            values.push(num);

            lastWasOperatorOrLeftParen = false; // 数字之后不能接运算符
        }
        else if (c == '(') {
            operators.push(c);
            lastWasOperatorOrLeftParen = true; // 左括号后可以接数字或左括号
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperator(val1, val2, op));
            }
            if (operators.empty()) throw invalid_argument("Mismatched parentheses: no matching '(' for ')'");
            operators.pop(); // 弹出 '('
            lastWasOperatorOrLeftParen = false; // 右括号后必须接运算符
        }
        else if (precedence.find(c) != precedence.end()) { // 运算符 + - * /
            if (lastWasOperatorOrLeftParen) throw invalid_argument("Invalid syntax: operator cannot follow another operator or left parenthesis");

            while (!operators.empty() && precedence[operators.top()] >= precedence[c]) {
                double val2 = values.top(); values.pop();
                double val1 = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperator(val1, val2, op));
            }
            operators.push(c);
            lastWasOperatorOrLeftParen = true; // 运算符后面可以接数字或左括号
        } else {
            throw invalid_argument(string("Invalid character: ") + c); // 非法字符
        }
    }

    while (!operators.empty()) {
        double val2 = values.top(); values.pop();
        double val1 = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperator(val1, val2, op));
    }

    if (operators.empty()) return values.top();  // 最后栈中只有一个值，就是结果

    throw invalid_argument("Invalid expression: unbalanced operators or operands");
}

void MainWindow::on_equalButton_clicked()
{
    if (expression == "\0") return;
    try {
        expression = QString::number(evaluateExpression(expression.toStdString()));
    }
    catch (const exception& e) {
        expression = e.what();
    }
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


void MainWindow::on_dotButton_clicked()
{
    expression += ".";
    ui->lineEdit->setText(expression);
}

