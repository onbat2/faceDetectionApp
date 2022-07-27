#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    QLabel *CameraDisplay = new QLabel;

    m_camera = new camera();

    m_cameraThread.start();

    m_camera->moveToThread(&m_cameraThread);

}


void MainWindow::on_pushButton_clicked()
{
    connect(m_camera, SIGNAL(runslot()), *CameraDisplay, SLOT(camera.started()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


