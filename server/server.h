#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    Server();
    QTcpSocket *socket;

private:
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    void SendToClient(int num, QString nickname);
    quint16 nextBlockSize;

public slots:
    void incomingConnection(qintptr socketDiscriptor);
    void slotReadyRead();

};

#endif // SERVER_H
