#include "facedetection.h"

faceDetection::~faceDetection()
{

}

void faceDetection::loadFiles(cv::String faceCascadeFilename)
{
    if(!faceCascade.load(faceCascadeFilename)){
        std::cout << "Error Loading " << faceCascadeFilename << std::endl;
    }
}

void faceDetection::setProcessAll(bool all)
{
    processAll_ = all;
}


void faceDetection::processFrame(const cv::Mat &frame)
{
    if(processAll_){
        process(frame);
    }else{
        queue(frame);
    }
}

void faceDetection::timerEvent(QTimerEvent *ev)
{
    if(ev->timerId() != timer_FD.timerId()){
        return;
    }
    process(frame_FD);
    frame_FD.release();
    timer_FD.stop();
}

void faceDetection::queue(const cv::Mat &frame)
{
    frame_FD = frame;
    if(!timer_FD.isActive()){
        timer_FD.start(20, this);
    }
}

void faceDetection::matDeleter(void *mat)
{
    delete static_cast<cv::Mat*>(mat);
}

void faceDetection::process(cv::Mat frame)
{
    cv::Mat grey_image;
    cv::cvtColor(frame, grey_image, cv::COLOR_BGR2GRAY);
//    cv::equalizeHist(grey_image, grey_image);

    std::vector<cv::Rect> faces;

    faceCascade.detectMultiScale(grey_image, faces, 1.1, 2, cv::CASCADE_SCALE_IMAGE,
                                    cv::Size(frame.cols/4, frame.rows/4));

    for(size_t i = 0; i < faces.size(); i++){
        cv::rectangle(frame, faces[i], cv::Scalar(255, 0, 255));

        cv::Point center( faces[i].x + faces[i].width*0.5,
                          faces[i].y + faces[i].height*0.5);

        ellipse( frame, center, cv::Size( faces[i].width*0.5, faces[i].height*0.5 ),
                     0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0);
    }

    cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB);

    cv::resize(frame, frame, cv::Size(frame.size().width/2, frame.size().height/2), cv::INTER_LINEAR);

    const QImage image((const unsigned char*)frame.data, frame.cols, frame.rows, frame.step,
                           QImage::Format_RGB888, &matDeleter, new cv::Mat(frame));
    image.rgbSwapped();
        Q_ASSERT(image.constBits() == frame.data);
        emit image_signal(QPixmap::fromImage(image));
}


