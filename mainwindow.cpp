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

double evaluateExpression(const string& expr) {
    stack<double> values;
    stack<char> ops;

    unordered_map<char, int> prec = {
        {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}
    };

    auto apply = [](double a, double b, char op) -> double {
        switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw invalid_argument("Division by zero");
            return a / b;
        }
        throw invalid_argument("Unknown operator");
    };

    // 上一个 token 的类型
    // true  = 可以接一元负号（表达式开头、(、运算符后）
    // false = 只能接二元运算符
    bool expectUnary = true;

    for (size_t i = 0; i < expr.size(); ++i) {
        char c = expr[i];

        if (isspace(c)) continue;

        /* ---------- 处理数字（含小数） ---------- */
        if (isdigit(c) || c == '.') {
            double num = 0, frac = 0, div = 1;
            bool dot = false;

            while (i < expr.size() && (isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    if (dot) throw invalid_argument("Invalid number format");
                    dot = true;
                } else {
                    if (!dot) num = num * 10 + (expr[i] - '0');
                    else {
                        frac = frac * 10 + (expr[i] - '0');
                        div *= 10;
                    }
                }
                i++;
            }
            i--;
            values.push(num + frac / div);
            expectUnary = false;
        }

        /* ---------- 左括号 ---------- */
        else if (c == '(') {
            ops.push(c);
            expectUnary = true;
        }

        /* ---------- 右括号 ---------- */
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(apply(a, b, op));
            }
            if (ops.empty()) throw invalid_argument("Mismatched parentheses");
            ops.pop(); // pop '('
            expectUnary = false;
        }

        /* ---------- 运算符 ---------- */
        else if (prec.count(c)) {

            // 处理一元负号
            if (c == '-' && expectUnary) {
                values.push(0); // 转换为 0 - x
            } else if (expectUnary) {
                throw invalid_argument("Invalid operator sequence");
            }

            while (!ops.empty() && ops.top() != '(' &&
                   prec[ops.top()] >= prec[c]) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(apply(a, b, op));
            }

            ops.push(c);
            expectUnary = true;
        }

        /* ---------- 非法字符 ---------- */
        else {
            throw invalid_argument(string("Invalid character: ") + c);
        }
    }

    /* ---------- 计算剩余运算 ---------- */
    while (!ops.empty()) {
        if (ops.top() == '(') throw invalid_argument("Mismatched parentheses");
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(apply(a, b, op));
    }

    if (values.size() != 1)
        throw invalid_argument("Invalid expression");

    return values.top();
}


void MainWindow::on_equalButton_clicked()
{
    expression = ui->lineEdit->text();
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

