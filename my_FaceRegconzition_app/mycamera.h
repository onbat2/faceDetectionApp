#ifndef MYCAMERA_H
#define MYCAMERA_H

#include <QObject>
#include <QImage>
#include <QTimer>
#include <iostream>
#include <QPixmap>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class myCamera : public QObject
{
    Q_OBJECT
public:
    myCamera();

public:
    void videoStreaming();

public slots:
    void openVideoCamera();

private:
    cv::VideoCapture m_cap;
    cv::Mat frame;
    QTimer timeUpdate;
    QImage img;

signals:
    void newImage(QPixmap img);
};

#endif // MYCAMERA_H
