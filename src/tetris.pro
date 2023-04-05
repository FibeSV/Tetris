QT += widgets core gui network

HEADERS       = tetrisboard.h \
                mainmenu.h \
                playerwidget.h \
                multiplayerblock.h \
                tetriswindow.h \
                tetromino.h
SOURCES       = main.cpp \
                mainmenu.cpp \
                playerwidget.cpp \
                multiplayerblock.cpp \
                tetrisboard.cpp \
                tetriswindow.cpp \
                tetromino.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/tetrix
INSTALLS += target

FORMS += \
    mainmenu.ui

RESOURCES += \
    res.qrc
