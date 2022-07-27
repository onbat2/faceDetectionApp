#include "camera.h"

camera::camera(){
    m_cap = new cv::VideoCapture();
}

void camera::runSlot(){
    if(!m_cap->isOpened()){
        m_cap->open(0);
    }

    *m_cap >> m_objFrame;
    QImage img = convert( m_objFrame );
    m_timer.start(20);
    emit camera::started();
}

QImage camera::convert(cv::Mat frame){
    QImage img;

    cvtColor(frame, frame, cv::COLOR_BGR2RGB);
    img = QImage((const unsigned char *)(frame.data), frame.cols, frame.rows,
                  QImage::Format_RGB888);
    return img;
}

void camera::stopped(){
    m_timer.stop();
}








































//void camera::run(){
//    if(!m_cap->isOpened()){          //Tại sao cần dùng -> chứ không phải !cap.isOpened ?
//        m_cap->open(0);              //Sao ko dùng cap.open(0) ?
//    }
//    m_bCameraRunning = true;
//    while(true){
//        m_objMutex.lock();
//        if(!m_bCameraRunning){
//            m_objMutex.unlock();
//            break;
//        }
//        m_objMutex.unlock();
//        *m_cap >> m_objFrame;
//        QImage img = convert( m_objFrame );
//        QThread::msleep( 20 );

//    }
//    m_cap->release();
//    m_bCameraRunning = false;
//}
////Tại sao cần dùng QMutex và Thread để lưu trữ 1 frame sau 1 time-event?

//void camera::closeCamera()
//{
//    m_objMutex.lock();
//    m_bCameraRunning = false;
//    m_objMutex.unlock();
//}

//QImage camera::convert(cv::Mat frame){
//    QImage img;

//    cvtColor(frame, frame, cv::COLOR_BGR2RGB);
//    img = QImage((const unsigned char *)(frame.data), frame.cols, frame.rows,
//                  QImage::Format_RGB888);
//    return img;
//}
