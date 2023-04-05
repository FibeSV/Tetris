QT += widgets core gui network

HEADERS       = tetrisboard.h \
                multiplayerblock.h \
                playerwidget.h \
                tetrispiece.h \
                tetriswindow.h
SOURCES       = main.cpp \
                multiplayerblock.cpp \
                playerwidget.cpp \
                tetrisboard.cpp \
                tetrispiece.cpp \
                tetriswindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/tetrix
INSTALLS += target

FORMS += \
    playerwidget.ui
