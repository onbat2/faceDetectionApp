#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <mycamera.h>
#include <facedetection.h>
#include <QThread>
#include <QObject>
#include <QPixmap>
#include <QMetaType>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    myCamera* m_camera;
    faceDetection* m_FD;
    QThread myCamera_Thread;
    QThread FD_Thread;
};
#endif // MAINWINDOW_H
