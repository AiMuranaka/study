#include <QApplication>
#include <QLocale>
#include "languagechooser.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(i18n);

    QApplication app(argc, argv);
    LanguageChooser chooser(QLocale::system().name());
    chooser.show();
    return app.exec();
}
