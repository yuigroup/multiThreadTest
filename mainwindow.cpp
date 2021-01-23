#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << QThread::currentThreadId();
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    if(cdc == nullptr)
    {
        cdc = new ClassDataClean;
        cdc->moveToThread(pClean);
        pClean->start();
    }
    if(tm == nullptr)
    {
        tm = new QTimer();
        QObject::connect(tm, SIGNAL(timeout()), this, SLOT(slot_timeout()));
    }
}

void MainWindow::resetValue()
{
    curMs = 0;
    curSec = 0;
    curMin = 0;
    curHour = 0;
    num = 0;
}

void MainWindow::slot_timeout()
{
    qDebug() << QString("%1:%2").arg(__FUNCTION__).arg(__LINE__);
    qDebug() << QThread::currentThreadId();
    num++;
    curMs = num%CONV_SEC;
    curSec = num/CONV_SEC;
    curMin = curSec/CONV_MIN;
    curHour = curMin/CONV_HOUR;
    ui->lcdNumber_ms->display(QString::number(curMs));
    ui->lcdNumber_s->display(QString::number(curSec%CONV_MIN));
    ui->lcdNumber_m->display(QString::number(curMin%CONV_MIN));
    ui->lcdNumber_h->display(QString::number(curHour));
}

void MainWindow::on_pushButton_start_clicked()
{
    if(!tm->isActive())
        tm->start(1);
}

void MainWindow::on_pushButton_stop_clicked()
{
    if(tm->isActive())
        tm->stop();
    resetValue();
}
