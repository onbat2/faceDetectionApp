#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QScopedPointer>
#include <QTimerEvent>
#include <iostream>
#include <QImage>
#include <QBasicTimer>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

class camera : public QObject
{
    Q_OBJECT
    QScopedPointer<VideoCapture> videoCapture_;
    QBasicTimer timer_;
    bool rub_;
    bool cameraIndex_;
    String videoFileName_;

public:
    camera(int camera_index = 0, QObject* parent = 0) : QObject(parent)
    {
        cameraIndex_ =camera_index;
        usingVideoCamera_ = true;
    }
};

#endif // CAMERA_H
