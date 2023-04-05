#include "server.h"

// Constructeur de la classe Server
Server::Server()
{
    // Ecoute sur l'adresse IP 'Any' et le port 2323
    if(this->listen(QHostAddress::Any,2323)){
        qDebug() <<"start";
    }
    else{
        qDebug() <<"error";
    }
    nextBlockSize = 0;
}

// Gestion des nouvelles connexions entrantes
void Server::incomingConnection(qintptr socketDiscriptor)
{
    // Création d'un nouveau socket et association au descripteur
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDiscriptor);
    // Connexion des signaux aux slots
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    // Ajout du socket à la liste des sockets
    Sockets.push_back(socket);
    qDebug() << "socket connecté " << socketDiscriptor;
}

// Slot pour lire les données entrantes
void Server::slotReadyRead()
{
    // Récupération du socket émetteur
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok){
        // Lecture des données
        for (;;){
            // Vérification de la taille du bloc
            if (nextBlockSize == 0) {
                qDebug() <<"nbs = 0";
                if (socket->bytesAvailable()<2){
                    qDebug() <<"data <2, break";
                    break;
                }
                in>> nextBlockSize;
                qDebug() <<"next = " << nextBlockSize;
            }
            // Vérification si toutes les données sont disponibles
            if (socket->bytesAvailable()<nextBlockSize){
                qDebug() <<"not full";
                break;
            }
            // Lecture des données
            int num;
            QString nickname;
            in >> num;
            in >> nickname;
            nextBlockSize = 0;
            qDebug() <<num;
            qDebug() <<num;
            // Envoi des données aux clients
            SendToClient(num , nickname);
            break;
        }
    }
    else{
        qDebug() <<"DataStream error";
    }
}

// Envoi des données aux clients
void Server::SendToClient(int num, QString nickname)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    // Préparation des données à envoyer
    out << quint16(0) << num << nickname;
    out.device()->seek(0);
    out << quint16(Data.size()-sizeof(quint16));
    // Envoi des données à tous les clients connectés
    for (int i=0;i<Sockets.size();i++){
        Sockets[i]->write(Data);
    }
}
