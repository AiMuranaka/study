#include "mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName(MainWindow::tr("Icons"));
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);
    QCommandLineParser commandLineParser;
    commandLineParser.setSingleDashWordOptionMode(QCommandLineParser::ParseAsLongOptions);
    commandLineParser.addHelpOption();
    commandLineParser.addVersionOption();
    QCommandLineOption noHighDpiPixmapOption("no-highdpi-pixmaps",
                                             "Disable High DPI image loading (Qt::AA_UseHighDpiPixmaps)");
    commandLineParser.addOption(noHighDpiPixmapOption);
        commandLineParser.addPositionalArgument(MainWindow::tr("[file]"), MainWindow::tr("Icon file(s) to open."));
    commandLineParser.process(QCoreApplication::arguments());

    if (!commandLineParser.isSet(noHighDpiPixmapOption)){
        QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    }

    MainWindow mainWin;
    if (!commandLineParser.positionalArguments().isEmpty()){
        mainWin.loadImages(commandLineParser.positionalArguments());
    }

    const QRect availableGeometry = mainWin.screen()->availableGeometry();
    mainWin.resize(availableGeometry.width() / 2, availableGeometry.height() * 2 / 3);
    mainWin.move((availableGeometry.width() - mainWin.width()) / 2, (availableGeometry.height() - mainWin.height()) / 2);

    mainWin.show();
    return app.exec();
}
