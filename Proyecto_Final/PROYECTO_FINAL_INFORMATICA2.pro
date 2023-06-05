QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemigos.cpp \
    fondo_niveles.cpp \
    juego.cpp \
    jugador_1.cpp \
    main.cpp \
    mainwindow.cpp \
    proyectil.cpp  \
    proyectil_en.cpp \
    puntaje.cpp   \

HEADERS += \
    enemigos.h \
    fondo_niveles.h \
    juego.h \
    jugador_1.h \
    mainwindow.h \
    proyectil.h \
    proyectil_en.h \
    puntaje.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc
