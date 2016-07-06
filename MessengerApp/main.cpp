#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include "sender.h"
#include "receiver.h"
#include <QStringList>
#include <QDebug>
#include <QThread>
#include <QQmlContext>
#include <QTimer>
#include <QObject>

	// salut baieti

void refresh();
void myWait();
int main(int argc, char *argv[])

{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    //QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QQmlContext *root=engine.rootContext();

    Sender sender;
    Receiver::Instance()->messages.append("Salut");

    root-> setContextProperty("messagesModel",QVariant(Receiver::Instance()->messages));
    root-> setContextProperty("messagesModel2",Receiver::Instance());

    sender.sendMessage("<h5><b>Andrei:</b></h5> theMessage12");
    sender.sendMessage("<h5><b>Gigi:</b></h5> ma abtin");
    sender.sendMessage("theMessage3");
    sender.sendMessage("theMessage4");
    sender.sendMessage("theMessage5");
    sender.sendMessage("theMessage6");

    //myWait();
    root-> setContextProperty("messagesModel",QVariant(Receiver::Instance()->messages));

    Receiver::Instance()->messages.append("Salut 2");

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    return app.exec();
}
void myWait(){
    QThread th;
    qDebug()<<"starting wait";
    th.sleep(3);
    qDebug()<<"waited";
    return;
}

//void refresh(){
//    timer = new QTimer();
//    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(addText()));
//    timer->start(1200);
//}
