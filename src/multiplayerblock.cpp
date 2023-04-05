#include "multiplayerblock.h"
#include "playerwidget.h"


#include <QLabel>
#include <QGridLayout>


MultiplayerBlock::MultiplayerBlock(QString name,QString hostname,int port,  QWidget *parent)
    : QWidget{parent}
{
    //playerwidget newplayer;
    //playerslist->push_back(newplayer);
    this->name = name;

    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MultiplayerBlock::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    nextBlockSize = 0;

    //name = "playern1";

    socket->connectToHost(hostname, port);


    if(socket->waitForConnected())
        qDebug() << ("Connected to Server");
    else{
        QMessageBox::critical(this,"QTCPClient", QString("The following error occurred: %1.").arg(socket->errorString()));
        exit(EXIT_FAILURE);
    }


    layout = new QVBoxLayout;
    setLayout(layout);

}

MultiplayerBlock::~MultiplayerBlock()
{
    if(socket->isOpen())
        socket->close();
}

void MultiplayerBlock::on_connectB_clicked()
{
    socket->connectToHost("127.0.0.1", 2323);
}

void MultiplayerBlock::SendToServer(int num)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint16(0) << num << name ;
    out.device()->seek(0);
    out << quint16(Data.size()-sizeof(quint16));
    socket->write(Data);
}

void MultiplayerBlock::set_name(QString name)
{
    this->name = name;
}

void MultiplayerBlock::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok){
        for (;;){
            if (nextBlockSize == 0) {
                if (socket->bytesAvailable()<2){
                    break;
                }
                in>> nextBlockSize;
            }
            if (socket->bytesAvailable()<nextBlockSize){
                break;
            }
            int num;
            QString nickname;
            in >> num;
            in >> nickname;
            nextBlockSize = 0;
            qDebug() <<"receive:"<< num;
            qDebug() << nickname;
            bool flag = false;
            for (int i =0; i<playerslist.size(); i++){
                if (nickname==playerslist[i]->get_name()){
                    playerslist[i]->set_score(num);

                    flag= true;
                    break;
                }
                if (playerslist[i]->get_name()=="TOI" and nickname==this->name){
                    playerslist[i]->set_score(num);

                    flag= true;
                    break;
                }
            }

            if (!flag){
                playerwidget *newp = new playerwidget;
                if (nickname==this->name)
                    newp->set_name("TOI");
                else
                    newp->set_name(nickname);
                newp->set_score(num);
                playerslist.push_back(newp);
                qDebug() <<"player was added" << nickname;
                layout->addWidget(newp);
            }
            //test_score->setText(QString::number(num));
        }

    }
    else{
        qDebug() << ("read error");
    }
}
