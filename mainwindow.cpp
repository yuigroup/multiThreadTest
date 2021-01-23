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
        tm = new QTimer(pTimer);
        QObject::connect(tm, SIGNAL(timeout()), this, SLOT(slot_timeout()));
        tm->setInterval(1);
//        tm->start();
        tm->moveToThread(pTimer);
        pTimer->start();
    }
}

void MainWindow::slot_timeout()
{
    qDebug() << QString("%1:%2").arg(__FUNCTION__).arg(__LINE__);
    qDebug() << QThread::currentThreadId();
    num++;
    ui->lcdNumber->display(QString::number(num));
}

void MainWindow::on_pushButton_start_clicked()
{
//    if(!pTimer->isRunning())
//        pTimer->start();
if(!tm->isActive())
    tm->start();
}

void MainWindow::on_pushButton_stop_clicked()
{
//    if(pTimer->isRunning())
//        pTimer->quit();

if(tm->isActive())
    tm->stop();
    num = 0;
}
