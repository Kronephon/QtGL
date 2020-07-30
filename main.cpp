#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "OpenGLWindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    QSurfaceFormat format;
    format.setSamples(16);
    OpenGLWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();


    return app.exec();
}
