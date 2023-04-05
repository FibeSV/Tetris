#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(TetrisWindow *window,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    twindow = window;

    setWindowTitle(tr("TETRIS"));
    resize(600, 350);
    //setStyleSheet("background-color: #2aa198;");
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

