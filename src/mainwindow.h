#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//for debugging
#include "QDebug"
// for serial ports
#include <QtSerialPort/QSerialPort>
// for callbacks
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // added variables
    bool button_state;
    int counter = 0;
    int callbackRefreshPeriod = 20; //milliseconds


private:
    Ui::MainWindow *ui;

public slots:

    // added slots
    void slot_buttonPushed( void );
    void slot_buttonReleased( void );
    void callbacks( void );

private slots:

};
#endif // MAINWINDOW_H
