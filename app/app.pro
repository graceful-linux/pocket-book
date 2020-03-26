TEMPLATE = app
TARGET = pocket-book

QT += core gui widgets

CONFIG += no_keywords c++11 debug

INCLUDEPATH += \
    $$PWD/widget/

FORMS += \
    $$PWD/widget/login.ui

HEADERS += \
    $$PWD/widget/login.h \
    $$PWD/widget/app.h \
    $$PWD/widget/nav.h

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/widget/login.cpp \
    $$PWD/widget/app.cpp \
    $$PWD/widget/nav.cpp
