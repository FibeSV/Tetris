#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QString>



class playerwidget : public QWidget
{
    Q_OBJECT

public:
    explicit playerwidget(QWidget *parent = nullptr);
    ~playerwidget();
    void set_name(QString str);
    void set_score(int num);
    QString get_name(){ return name;}
    int get_score(){ return score;}
private:
    QLabel *player_name;
    QString name;
    int score;
    QLCDNumber *player_score;

};

#endif // PLAYERWIDGET_H
