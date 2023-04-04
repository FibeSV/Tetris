QT += widgets

HEADERS       = tetrisboard.h \
                playerwidget.h \
                tetrispiece.h \
                tetriswindow.h
SOURCES       = main.cpp \
                playerwidget.cpp \
                tetrisboard.cpp \
                tetrispiece.cpp \
                tetriswindow.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/tetrix
INSTALLS += target

FORMS += \
    playerwidget.ui
