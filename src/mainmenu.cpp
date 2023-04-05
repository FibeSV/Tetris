#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(TetrisWindow *window,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    twindow = window;

    setWindowTitle(tr("TETRIS"));
    resize(760, 500);
    QPixmap bkgnd(":/img/img/bg1.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_startButton_clicked()
{
    //TetrisWindow tetriswindow(ui->lineEdit->text());
    //TetrisWindow tetriswindow("trickster");
    twindow->Connect(ui->uLE->text(), ui->ipLE->text(), ui->portLE->text().toInt());
    twindow->show();
    this->close();

}


void MainMenu::on_singleButton_clicked()
{
    twindow->show();
    this->close();
}

