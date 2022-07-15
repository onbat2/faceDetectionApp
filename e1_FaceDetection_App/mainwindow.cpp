#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_TurnOn_Button_clicked()
{
    cap.open(0);

    if(!cap.isOpened()){
        cout << "camera is not open now" << endl;
    }else{
        cout << "camera is open" << endl;
        connect(timer, SIGNAL(timeout()), this, SLOT(Display_Camera()));
        timer->start(20);
    }
}


void MainWindow::on_TurnOff_Button_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(Display_Camera()));
    cap.release();

    Mat image = Mat::zeros(frame.size(), CV_8UC3);

    qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);

    ui->Display->setPixmap(QPixmap::fromImage(qt_image));

    cout << "camera is closed" << endl;
}

void MainWindow::Display_Camera()
{
    cap >> frame;

    cvtColor(frame, frame, COLOR_BGR2RGB);

    cv::resize(frame, frame, cv::Size(frame.size().width/2, frame.size().height/2), cv::INTER_LINEAR);

    string DetectionPath = "/usr/local/share/opencv4/haarcascades/haarcascade_frontalface_alt.xml";
    CascadeClassifier faceDetector;
    faceDetector.load(DetectionPath);
    vector<Rect>faces;
    faceDetector.detectMultiScale(frame, faces, 1.1, 4, CASCADE_SCALE_IMAGE, Size(30, 30));
    for(int i = 0; i < faces.size(); i++){
                Mat faceROI = frame(faces[i]);
                int x = faces[i].x;
                int y = faces[i].y;
                int h = y + faces[i].height;
                int w = x + faces[i].width;
                rectangle(frame, Point(x, y), Point(w, h), Scalar(255, 0, 2550), 2, 8, 0);
            }

    qt_image = QImage((const unsigned char*) (frame.data),frame.cols, frame.rows, QImage::Format_RGB888);

    ui->Display->setPixmap(QPixmap::fromImage(qt_image));

}
