#ifndef MYCAMERA_H
#define MYCAMERA_H

#include <QObject>
#include <QImage>
#include <QTimerEvent>
#include <QBasicTimer>
#include <stdio.h>
#include <iostream>
#include <QMetaType>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>


class myCamera : public QObject
{
    Q_OBJECT
    bool m_usingVideoCamera;
    void timerEvent(QTimerEvent *ev);

public:
    myCamera(QObject* parent=0) : QObject(parent){
        m_usingVideoCamera = true;
    }
    ~myCamera();

public slots:
    void openVideoCamera();
    void stopped();

signals:
    void started();
    void matReady(const cv::Mat &);

private:
    QBasicTimer timer_myCamera;
    cv::Mat frame_myCamera;
    cv::VideoCapture m_cap;
    cv::Mat m_frame;
};

#endif // MYCAMERA_H
