#include "tetriswindow.h"
#include "mainmenu.h"

#include <QApplication>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TetrisWindow twindow;
    MainMenu window(&twindow);

    QPixmap logoPixmap(":/img/Tetris.jpg");
    //qDebug() << QDir::toNativeSeparators(QApplication::applicationDirPath()) + ".../images/Tetris.jpg";
    window.setWindowIcon(QIcon(logoPixmap));

    window.show();
    return app.exec();
}
