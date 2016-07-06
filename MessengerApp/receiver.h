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
    Q_PROPERTY(QStringList string READ string WRITE setString NOTIFY stringChanged)
public:
    void setString(QStringList var){
        myQStr=var;
    }
    QStringList string(){
        return myQStr;
    }
    void addText();
    //Receiver();
    //Q_INVOKABLE QStringList myQStr;
    Q_INVOKABLE QStringList messages;
    static Receiver* Instance();

protected:
    Receiver();

private slots:
    void processPendingDatagrams();
    void processMyPendingDatagrams();
//public slots:
//    void addText();

private:
    QUdpSocket *udpSocket;
    static Receiver* _instance;
    Q_INVOKABLE QStringList myQStr;
signals:
    void stringChanged();
};

#endif // RECEIVER_H
