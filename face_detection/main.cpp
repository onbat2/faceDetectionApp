#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<string>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
    Mat video_stream;
    //Declaring a matrix hold frames from video stream
    VideoCapture real_time(0);
    //Capturing video from default webcam
    namedWindow("Face Detection");
    //Declaring an window to show the result
    string trained_classifier_location = "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml";
    CascadeClassifier faceDetector;
    faceDetector.load(trained_classifier_location);
    vector<Rect>faces;
    while(true){
        faceDetector.detectMultiScale(video_stream, faces, 1.1, 4, CASCADE_SCALE_IMAGE, Size(30, 30));
        real_time.read(video_stream);
        for(int i = 0; i < faces.size(); i++){
            Mat faceROI = video_stream(faces[i]);
            int x = faces[i].x;
            int y = faces[i].y;
            int h = y + faces[i].height;
            int w = x + faces[i].width;
            rectangle(video_stream, Point(x, y), Point(w, h), Scalar(255, 0, 2550), 2, 8, 0);
        }
        imshow("Face Detection", video_stream);
        if(waitKey(10) == 27){
            break;
        }
    }
    return 0;
}
