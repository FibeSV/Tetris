#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>

#include "tetriswindow.h"

namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(TetrisWindow *window,QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_startButton_clicked();

    void on_singleButton_clicked();

private:
    Ui::MainMenu *ui;
    TetrisWindow *twindow;
};

#endif // MAINMENU_H
