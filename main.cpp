#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "OpenGLWindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    OpenGLWindow window;
    window.show();

    return app.exec();
}
