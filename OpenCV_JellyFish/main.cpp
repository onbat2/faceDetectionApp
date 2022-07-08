#include <opencv2/highgui.hpp>

#include <stdio.h>

int main(){
    cv::Mat img = cv ::imread("/home/duke/Pictures/Jelly_fish.jpg");
    cv::imshow("Jelly_Fish",img);
    cv::waitKey(0);

    return 0;
}
