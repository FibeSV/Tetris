#ifndef MULTIPLAYERBLOCK_H
#define MULTIPLAYERBLOCK_H

#include <QWidget>

#include "playerwidget.h"


#include <QAbstractSocket>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QHostAddress>
#include <QMessageBox>
#include <QMetaType>
#include <QString>
#include <QStandardPaths>
#include <QTcpSocket>
#include <QVector>
#include <QListWidget>
#include <QVBoxLayout>

class MultiplayerBlock : public QWidget
{
    Q_OBJECT
public:
    explicit MultiplayerBlock(QWidget *parent = nullptr);
    ~MultiplayerBlock();
    void SendToServer(int num);

signals:
        void newMessage(QString);

public slots:
        void slotReadyRead();
private slots:

        void on_connectB_clicked();


private:
        QTcpSocket *socket;
        QVector<playerwidget*> playerslist;
        QByteArray Data;

        quint16 nextBlockSize;
        QLabel *connection;
        QLabel *test_score;
        QLabel *statusLabel;
        QString name;
        QListWidget *listWidget;
        QVBoxLayout *layout;
};

#endif // MULTIPLAYERBLOCK_H
