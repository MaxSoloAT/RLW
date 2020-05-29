QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addprog.cpp \
    logset.cpp \
    main.cpp \
    mainwindow.cpp \
    startprog.cpp \
    student_log.cpp

INCLUDEPATH += E:\Open\opencv\realase\install\include

LIBS += E:\Open\opencv\realase\bin\libopencv_core343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_highgui343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_imgcodecs343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_imgproc343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_features2d343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_calib3d343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_calib3d343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_dnn343.dll
LIBS += E:\Open\opencv\realase\bin\opencv_ffmpeg343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_flann343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_ml343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_objdetect343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_photo343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_shape343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_stitching343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_superres343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_video343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_videoio343.dll
LIBS += E:\Open\opencv\realase\bin\libopencv_videostab343.dll


HEADERS += \
    addprog.h \
    logset.h \
    mainwindow.h \
    startprog.h \
    student_log.h

FORMS += \
    addprog.ui \
    logset.ui \
    mainwindow.ui \
    startprog.ui \
    student_log.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc
