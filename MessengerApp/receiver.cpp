#include <QtWidgets>
#include <QtNetwork>
#include <QStringList>

#include "receiver.h"

//Receiver::Receiver(QWidget *parent)
//    : QWidget(parent)
//{
//    //messages = new QStringList();

//    statusLabel = new QLabel(tr("Listening for broadcasted messages"));
//    statusLabel->setWordWrap(true);

//    quitButton = new QPushButton(tr("&Quit"));

//    udpSocket = new QUdpSocket(this);
//    udpSocket->bind(45454, QUdpSocket::ShareAddress);

//    connect(udpSocket, SIGNAL(readyRead()),
//            this, SLOT(processMyPendingDatagrams()));

//    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

//    QHBoxLayout *buttonLayout = new QHBoxLayout;
//    buttonLayout->addStretch(1);
//    buttonLayout->addWidget(quitButton);
//    buttonLayout->addStretch(1);

//    QVBoxLayout *mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(statusLabel);
//    mainLayout->addLayout(buttonLayout);
//    setLayout(mainLayout);

//    setWindowTitle(tr("Broadcast Receiver"));
//}

// Global static pointer used to ensure a single instance of the class.

Receiver* Receiver::_instance = 0;
Receiver* Receiver::Instance() {
    if (_instance == 0) {
        _instance = new Receiver;
    }
    return _instance;
}


Receiver::Receiver (){

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(45454, QUdpSocket::ShareAddress);

    connect(udpSocket, SIGNAL(readyRead()),
            this, SLOT(processMyPendingDatagrams()));

}

//void Receiver::addText(QString message){
//    myQStr.append(genString());
//    emit stringChanged();
//}

void Receiver::processMyPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        myQStr.append(datagram.data());
        emit stringChanged();
    }
}

void Receiver::processPendingDatagrams()
{
    while (udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
//        statusLabel->setText(tr("Received datagram: \"%1\"")
//                             .arg(datagram.data()));
    }
}
