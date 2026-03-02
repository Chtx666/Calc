#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <string.h>
#include <QByteArray>
#include <stack>
#include <cctype>
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <QTimer>
#include <QMessageBox>
#include <QMenuBar>
#include <QFileDialog>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_oneButton_clicked();

    void on_sevenButton_clicked();

    void on_zeroButton_clicked();

    void on_leftButton_clicked();

    void on_rightButton_clicked();

    void on_equalButton_clicked();

    void on_threeButton_clicked();

    void on_twoButton_clicked();

    void on_sixButton_clicked();

    void on_fiveButton_clicked();

    void on_fourButton_clicked();

    void on_nineButton_clicked();

    void on_multiButton_clicked();

    void on_divideButton_clicked();

    void on_eightButton_clicked();

    void on_subButton_clicked();

    void on_addButton_clicked();

    void on_clrButton_clicked();

    void on_delButton_clicked();

    void on_dotButton_clicked();

    void on_startButton_clicked();

    void timeoutSlot();

    void on_pauseButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void dealNewAction();

    void dealOpenAction();

private:
    Ui::MainWindow *ui;
    QString expression;
    QTimer *timer;
};
#endif // MAINWINDOW_H
