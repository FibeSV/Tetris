
#include "tetriswindow.h"
#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TetrisWindow twindow;
    MainMenu window(&twindow);
    window.show();
    return app.exec();
}
