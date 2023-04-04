#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>


class playerwidget : public QWidget
{
    Q_OBJECT

public:
    explicit playerwidget(QWidget *parent = nullptr);
    ~playerwidget();

private:
    QLabel *player_name;
    QLCDNumber *player_score;
};

#endif // PLAYERWIDGET_H
