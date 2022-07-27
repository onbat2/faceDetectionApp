#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QObject>
#include <QMainWindow>
#include <QThread>
#include <QTimer>
#include <QLabel>

#include <iostream>
#include <stdio.h>
#include "camera.h"

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
    void open();


    void on_pushButton_clicked();

    private:
    Ui::MainWindow *ui;

    QTimer *timer;
    cv::VideoCapture cap;

    cv::Mat frame;
    QImage qt_image;

    camera* m_camera;

    QThread m_cameraThread;

    QLabel *CameraDisplay;
};
#endif // MAINWINDOW_H
