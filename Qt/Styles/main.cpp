#include "widgetgallery.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetGallery w;
    w.show();
    return a.exec();
}
