#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QDebug>
#include <QImage>
#include <QTimer>

#include <string>
#include <iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>

using namespace std;
using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_TurnOn_Button_clicked();

    void on_TurnOff_Button_clicked();

    void Display_Camera();

private:
    Ui::MainWindow *ui;

    QTimer *timer;
    VideoCapture cap;

    Mat frame;
    QImage qt_image;
};
#endif // MAINWINDOW_H
