#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include "tetrisboard.h"
#include "multiplayerblock.h"
#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H


class TetrisWindow : public QWidget /*Définition de la classe TetrisWindow*/

{
Q_OBJECT

public:
    TetrisWindow( QWidget *parent = nullptr);
    void setName(QString str);
    void Connect(QString name="player1",QString hostname="127.0.0.1",int port=2323);

private: //ici on définit tout les éléments visuels que l'on veut voir apparaitre
    QLabel *createLabel(const QString &text);

    TetrisBoard *board; //notre grille de jeu

    MultiplayerBlock *my_block;

    QHBoxLayout *mlayout;

    QLabel *nextPieceLabel; //l'affichage de la pièce suivante
    QLabel *gameOverLabel;//l'affichage gameover
    QLabel *heldPieceLabel;//l'affichage de la piece en stock
    QLCDNumber *score;
    QLCDNumber *lignes;

    QPushButton *start;
    QPushButton *quit;
    QPushButton *pause;
};

#endif // TETRISWINDOW_H
