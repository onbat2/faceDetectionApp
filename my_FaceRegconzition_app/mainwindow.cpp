#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openButton, &QPushButton::clicked, &m_cam, &myCamera::openVideoCamera);

    connect(&m_cam, &myCamera::newImage, ui->cameraDisplay, &QLabel::setPixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

