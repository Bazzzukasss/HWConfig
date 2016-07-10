#include "hwconfigwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HWConfigWindow w;
    w.show();
    return a.exec();
}
