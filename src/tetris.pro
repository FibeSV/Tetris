QT += widgets core gui network

HEADERS       = tetrisboard.h \
                mainmenu.h \
                playerwidget.h \
                multiplayerblock.h \
                tetrispiece.h \
                tetriswindow.h
SOURCES       = main.cpp \
                mainmenu.cpp \
                playerwidget.cpp \
                multiplayerblock.cpp \
                tetrisboard.cpp \
                tetrispiece.cpp \
                tetriswindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/tetrix
INSTALLS += target

FORMS += \
    mainmenu.ui
