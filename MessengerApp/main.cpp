#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include "sender.h"
#include "receiver.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    Sender sender;
    sender.show();
    //Receiver re;
    Receiver receiver;
    receiver.show();

    return app.exec();
}
