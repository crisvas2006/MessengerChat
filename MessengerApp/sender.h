#ifndef SENDER_H
#define SENDER_H
#include <QWidget>
#include <QByteArray>

class QDialogButtonBox;
class QLabel;
class QPushButton;
class QTimer;
class QUdpSocket;

class Sender : public QWidget
{
    Q_OBJECT

public:
    Sender(QWidget *parent = 0);
    void sendMessage(QByteArray message);

private slots:
    void startBroadcasting();
    void broadcastDatagram();
    void broadcastMyDatagram(QByteArray datagram);

private:
    QLabel *statusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QUdpSocket *udpSocket;
    QTimer *timer;
    int messageNo;
};

#endif // SENDER_H
