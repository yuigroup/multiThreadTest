#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include "clean/classdataclean.h"
#define CONV_HOUR 60
#define CONV_MIN 60
#define CONV_SEC 1000

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();
    void resetValue();
public slots:
    void slot_timeout();
public:
    QThread *pClean = new QThread();
    QThread *pTimer = new QThread();
    ClassDataClean *cdc = nullptr;
    QTimer *tm = nullptr;
private slots:
    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

private:
    Ui::MainWindow *ui;
    int curMs = 0;
    int curSec = 0;
    int curMin = 0;
    int curHour = 0;
    int num = 0;
};

#endif // MAINWINDOW_H
