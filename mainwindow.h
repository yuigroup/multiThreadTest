#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include "clean/classdataclean.h"

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
    int num = 0;
};

#endif // MAINWINDOW_H
