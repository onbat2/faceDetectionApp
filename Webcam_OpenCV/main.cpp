#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(){
    Mat image;
    namedWindow("Display window");

    cout << "Hello :)";

    VideoCapture cap(0);

    if(!cap.isOpened()){
        cout << "cannot open camera";
    }

    while(true){
        cap >> image;
        imshow("Dispay window", image);
        waitKey(25);
    }
    return 0;
}
