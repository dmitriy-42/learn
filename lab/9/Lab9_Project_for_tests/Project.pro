TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        lockcontroller.cpp \
        main.cpp \
        mockikeypad.cpp \
        mockilatch.cpp

HEADERS += \
    IKeypad.h \
    ILatch.h \
    lockcontroller.h \
    mockikeypad.h \
    mockilatch.h
