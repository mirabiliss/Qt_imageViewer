#include "imageviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    imageViewer w;
    w.show();
    return a.exec();
}
