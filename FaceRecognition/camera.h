#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QThread>
#include <stdio.h>
#include <iostream>
#include <QPixmap>
#include <QTimer>

#include <QImage>
#include <QDebug>
//#include <QMutex>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class camera : public QThread //why used ": public QThread"
{
    Q_OBJECT
    QTimer m_timer;

public:
    camera();

    void runSlot();

    void started();

    void switchButton();

    void process(cv::Mat frame);

    QImage convert(cv::Mat frame);
    //Convert the Mat type from OpenCV to QImage

//    void run();
    //The thread on which the QThread actually resides

public slots:

    void stopped();


signals:


private:
    //Camera object
    cv::VideoCapture *m_cap;                //Tại sao cần dùng cv:: ?
    //Camera operation flag bit
    bool m_bCameraRunning;
    //Wire program lock
//    QMutex m_objMutex;
    //Mat of openCV
    cv::Mat m_objFrame;



};

#endif // CAMERA_H
