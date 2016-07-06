#ifndef RECEIVER_H
#define RECEIVER_H
#include <QWidget>
#include <QStringList>
#include <QObject>
class QLabel;
class QPushButton;
class QUdpSocket;
class QAction;

class Receiver : public QObject
{
    Q_OBJECT

public:
    //Receiver();
    Q_INVOKABLE QStringList messages;
    static Receiver* Instance();

protected:
    Receiver();

private slots:
    void processPendingDatagrams();
    void processMyPendingDatagrams();

private:
    QUdpSocket *udpSocket;
    static Receiver* _instance;

};

#endif // RECEIVER_H
