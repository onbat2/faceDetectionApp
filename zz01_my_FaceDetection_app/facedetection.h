#ifndef FACEDETECTION_H
#define FACEDETECTION_H

#include <QObject>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QPixmap>
#include <QImage>
#include <QString>
#include <stdio.h>
#include <iostream>
#include <QMetaType>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class faceDetection : public QObject
{
    Q_OBJECT
    QString m_facecascade_filepath;
    cv::CascadeClassifier faceCascade;
    void loadFiles(cv::String faceCascadeFilename);
    bool processAll_;
    void queue(const cv::Mat & frame);
    void timerEvent(QTimerEvent* ev);
    void process(cv::Mat frame);
    static void matDeleter(void* mat);

public:
    faceDetection(QObject* parent=0) : QObject(parent), processAll_(true){
        m_facecascade_filepath = "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml";
        loadFiles(m_facecascade_filepath.toStdString().c_str());
    }
    void setProcessAll(bool all);
    ~faceDetection();

signals:
    void image_signal(QPixmap image);

public slots:
    void processFrame(const cv::Mat& frame);

private:
    QBasicTimer timer_FD;
    cv::Mat frame_FD;
};

#endif // FACEDETECTION_H
//٩(◕‿◕｡)۶
