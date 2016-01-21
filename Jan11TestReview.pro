#-------------------------------------------------
#
# Project created by QtCreator 2016-01-12T10:29:08
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Jan11TestReview
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.cpp
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -std=c++14
CONFIG += qt debug

HEADERS += \
    Array.h \
    fmod.h \
    count_if.h \
    copy_ctor.h \
    array1.h \
    ostream.h \
    ostream1.h \
    jan14ostreamsum.h \
    jan14virtualfunctorpointer.h \
    Jan15DynamicArrayABC \
    Jan15CatDogDynamicArraysmartpointerABC.h \
    jan15smartpointerrawpointer.h \
    jan16datastructlinkedlistqueue.h \
    jan16datastructarray.h \
    jan16bstschoolcode.h \
    jan16bstschoolcode1.h \
    jan16linkedlistqueue.h \
    jan16datastructvector.h \
    jan16datastructarrayqueue1.h \
    jan16datastructarraystlqueue.h \
    ADT.h
