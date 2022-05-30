QT       += core gui opengl openglwidgets 
include(QtGifImage/gifimage/qtgifimage.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    model/matrix/s21_help.cpp \
    model/matrix/s21_matrix_oop_constructors.cpp \
    model/matrix/s21_matrix_oop_methods.cpp \
    model/matrix/s21_matrix_oop_operators.cpp \
    model/geometryengine.cpp \
    model/object.cpp \
    model/settingsmodel.cpp \
    view/glwidget.cpp \
    view/main.cpp \
    view/mainwindow.cpp \
    view/settings.cpp \

HEADERS += \
    controller/controller.h \
    model/matrix/s21_matrix_oop.h \
    model/geometryengine.h \
    model/object.h \
    model/settingsmodel.h \
    view/glwidget.h \
    view/mainwindow.h \
    view/settings.h
    matrix/s21_matrix_oop.h \

#FORMS += \
#    mainwindow.ui \
#    settings.ui

ICON = icns/3DviewerLogo.icns

RESOURCES += icns/3DviewerLogo.icns

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
