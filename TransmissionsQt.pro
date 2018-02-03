#-------------------------------------------------
#
# Project created by QtCreator 2014-02-21T23:24:12
#
#-------------------------------------------------

QT += core gui xml printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Transmissions
TEMPLATE = app

CONFIG += c++11 static
#QTPLUGIN += windowsprintersupport
SOURCES += main.cpp\
        transmain.cpp \
    TransTabWidget.cpp \
    chambrepanel.cpp \
    secteur.cpp \
    gestiontabwidget.cpp \
    lecturexml.cpp \
    ecriturexml.cpp \
    clearformdialog.cpp \
    qlabeldate.cpp \
    exitformdialog.cpp \
    aboutformdialog.cpp \
    clickableqlabel.cpp \
    switchrooms.cpp \
    transdocument.cpp \
    qmaintextedit.cpp \
    qmisctextedit.cpp \
    qmainlineedit.cpp \
    qnomlineedit.cpp \
    transprintpreview.cpp \
    transprintmarginsdialog.cpp \
    qmainatcdtextedit.cpp \
    qmainallergiestextedit.cpp \
    splashscreendialog.cpp \
    qgroupboxstyleimage.cpp \
    transprinterfactory.cpp \
    transsecteurchooserfactory.cpp

HEADERS  += transmain.h \
    transtabwidget.h \
    chambrepanel.h \
    secteur.h \
    gestiontabwidget.h \
    lecturexml.h \
    ecriturexml.h \
    clearformdialog.h \
    qlabeldate.h \
    exitformdialog.h \
    aboutformdialog.h \
    clickableqlabel.h \
    switchrooms.h \
    transdocument.h \
    qmaintextedit.h \
    qmisctextedit.h \
    qmainlineedit.h \
    qnomlineedit.h \
    transprintpreview.h \
    transprintmarginsdialog.h \
    qmainatcdtextedit.h \
    qmainallergiestextedit.h \
    splashscreendialog.h \
    qgroupboxstyleimage.h \
    transprinterfactory.h \
    transsecteurchooserfactory.h

FORMS    += transmain.ui \
    chambrepanel.ui \
    clearformdialog.ui \
    exitformdialog.ui \
    aboutformdialog.ui \
    switchrooms.ui \
    transprintmarginsdialog.ui \
    splashscreendialog.ui \
    transsecteurchooserfactory.ui \
    transprinterfactory.ui

RESOURCES += \
    images.qrc

RC_FILE = transmissions.rc
