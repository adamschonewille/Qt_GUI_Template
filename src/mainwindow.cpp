#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "this is a debug test statement";

    qInfo() << "Object is being constructed";

    // Connect pushbutton to slots
    connect(ui->pushButton_test, SIGNAL(pressed()) , SLOT( slot_buttonPushed() ) );
    connect(ui->pushButton_test, SIGNAL(released()) , SLOT( slot_buttonReleased() ) );

    QTimer *callbacktimer = new QTimer(this);
    connect(callbacktimer, SIGNAL(timeout()), this, SLOT(callbacks()));
    callbacktimer->start(callbackRefreshPeriod); //Default 200. Set to 20 ms for a faster 50Hz refresh rate

    // initialize label (or do via GUI editor)
    ui->label_test->setText("Push Button has not been pressed.");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::slot_buttonPushed(void)
{
    qDebug() << "Button is pressed";
    ui->label_test->setText("Push Button is pressed.");

}

void MainWindow::slot_buttonReleased(void)
{
    qDebug() << "Button is released";
    ui->label_test->setText("Push Button is released.");
}

void MainWindow::callbacks(void)
{
    // do whatever multiple times per second.
    counter += 1;
    ui->label_timer->setText( tr("%1").arg(counter) );
}
