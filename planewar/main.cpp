#include "mainscene.h"
#include <QApplication>
#include <QResource>
#include "config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QResource::registerResource("./plane.rcc");

    Mainscene w;
    w.show();

    return a.exec();
}
