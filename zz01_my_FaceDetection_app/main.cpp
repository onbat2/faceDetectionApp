#include "mainwindow.h"

#include <QApplication>

Q_DECLARE_METATYPE(cv::Mat)
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType< cv::Mat >("cv::Mat");
    MainWindow w;
    w.show();
    return a.exec();
}
