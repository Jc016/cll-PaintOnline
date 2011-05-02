#include <QtGui/QApplication>
#include "paintonlineclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintOnlineClient w;
    w.show();

    return a.exec();
}
