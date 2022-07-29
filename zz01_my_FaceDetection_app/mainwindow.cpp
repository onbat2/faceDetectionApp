#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_camera = new myCamera();
    m_FD = new faceDetection();

    myCamera_Thread.start();
    FD_Thread.start();

    m_camera->moveToThread(&myCamera_Thread);
    m_FD->moveToThread(&FD_Thread);

    connect(ui->openButton, &QPushButton::clicked, m_camera, &myCamera::openVideoCamera);
    connect(m_camera, &myCamera::matReady, m_FD, &faceDetection::processFrame);
    connect(m_FD, &faceDetection::image_signal, ui->Display, &QLabel::setPixmap);
}

MainWindow::~MainWindow()
{
    m_FD->~faceDetection();
    m_camera->~myCamera();
    FD_Thread.quit();
    myCamera_Thread.quit();
    FD_Thread.wait();
    myCamera_Thread.wait();
    delete ui;
}

