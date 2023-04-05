#include "playerwidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>

playerwidget::playerwidget(QWidget *parent) :
    QWidget(parent)

{
    player_name = new QLabel("night_killer9979");
    player_name->setFrameStyle(QFrame::Box | QFrame::Raised);
    player_name->setAlignment(Qt::AlignCenter);
    player_name->setFont(QFont("8514OEM", 15, QFont::Bold));
    player_name->setStyleSheet("color: #fac898;");

    player_score = new QLCDNumber(5);
    player_score->display(999999);

    QGridLayout *layout = new QGridLayout; //need to change some values here.

    layout->addWidget(player_name, 0, 0);
    layout->addWidget(player_score, 1, 0);
    setLayout(layout);
    this->setFixedHeight(100);
    //setStyleSheet("background-color: #2aa198;");

}
void playerwidget::set_name(QString str){
    this->name = str;
    player_name->setText(str);

}

void playerwidget::set_score(int num)
{
    this->score = num;
    player_score->display(num);
}

playerwidget::~playerwidget()
{

}
