QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LoginWindow.cpp \
    framestyledelegate.cpp \
    lframedatainit.cpp \
    main.cpp \
    mainwindow.cpp \
    networkmanager.cpp \
    recordcontent.cpp \
    recordgrid.cpp \
    recordgridtitle.cpp \
    recordwindow.cpp \
    registwindow.cpp

HEADERS += \
    LoginWindow.h \
    framestyledelegate.h \
    lframedatainit.h \
    mainwindow.h \
    networkmanager.h \
    publishMsg.h \
    recordcontent.h \
    recordgrid.h \
    recordgridtitle.h \
    recordwindow.h \
    registwindow.h

FORMS += \
    LoginWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
