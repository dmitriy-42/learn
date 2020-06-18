include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        ../../Lab9_Project_for_tests/IKeypad.h \
        ../../Lab9_Project_for_tests/ILatch.h \
        ../../Lab9_Project_for_tests/lockcontroller.h \
        ../../Lab9_Project_for_tests/mockikeypad.h \
        ../../Lab9_Project_for_tests/mockilatch.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ../../Lab9_Project_for_tests/lockcontroller.cpp \
        ../../Lab9_Project_for_tests/mockikeypad.cpp \
        ../../Lab9_Project_for_tests/mockilatch.cpp \
        gmock.cpp \
        main.cpp


INCLUDEPATH += \
        /home/dmitriy/C++/lab/9/Lab9_Project_for_tests/
