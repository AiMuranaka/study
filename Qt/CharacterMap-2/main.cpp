#include "characterwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CharacterWidget w;
    w.show();
    return a.exec();
}
