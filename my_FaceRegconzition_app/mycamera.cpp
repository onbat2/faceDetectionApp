#include "mycamera.h"

myCamera::myCamera()
{
    connect(&timeUpdate, &QTimer::timeout, this, &myCamera::videoStreaming);
}

void myCamera :: videoStreaming(){
    m_cap >> frame;

    cvtColor(frame, frame, cv::COLOR_BGR2RGB);

    cv::resize(frame, frame, cv::Size(frame.size().width/2,
                       frame.size().height/2), cv::INTER_LINEAR);

    img = QImage((const unsigned char*) (frame.data),frame.cols, frame.rows, QImage::Format_RGB888);
    emit newImage(QPixmap::fromImage(img));
}

void myCamera :: openVideoCamera(){
    if(!m_cap.isOpened()){
        m_cap.open(0);

        timeUpdate.start(20);
    }
}
