/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

#include "view/glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
 public:
  QWidget *centralwidget;
  GlWidget *glscene;
  QPushButton *openFile;
  QPushButton *settings;
  QPushButton *translateButton;
  QPushButton *rotateButton;
  QPushButton *scaleButton;
  QDoubleSpinBox *xTranslate;
  QLabel *xTrLabel;
  QDoubleSpinBox *yTranslate;
  QLabel *yTrLabel;
  QDoubleSpinBox *zTranslate;
  QLabel *zTrLabel;
  QDoubleSpinBox *yRotate;
  QLabel *zRrLabel;
  QDoubleSpinBox *xRotate;
  QLabel *yRrLabel;
  QLabel *xRrLabel;
  QDoubleSpinBox *zRotate;
  QDoubleSpinBox *scalateSpinBox;
  QPushButton *gifButton;
  QPushButton *jpegButton;
  QPushButton *bmpButton;
  QSlider *sliderScalate;
  QSlider *sliderXRotate;
  QSlider *sliderYRotate;
  QSlider *sliderZRotate;
  QSlider *sliderXTranslate;
  QSlider *sliderZTranslate;
  QSlider *sliderYTranslate;
  QLabel *numberOfVertices;
  QLabel *numberOfEdges;
  QLabel *curFile;
  QLabel *degree0;
  QLabel *degree360;
  QLabel *percent10;
  QLabel *percent100;
  QLabel *percent200;
  QLabel *percent100_2;
  QLabel *percent100_3;
  QLabel *degree0_2;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->setWindowModality(Qt::ApplicationModal);
    MainWindow->resize(1280, 760);
    MainWindow->setMinimumSize(QSize(1280, 760));
    MainWindow->setMaximumSize(QSize(1280, 760));
    MainWindow->setStyleSheet(QString::fromUtf8(""));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setStyleSheet(
        QString::fromUtf8("background-color: #F5F5F5;\n"
                          "font: 18pt \"JetBrains Mono\";"));
    glscene = new GlWidget(centralwidget);
    glscene->setObjectName(QString::fromUtf8("glscene"));
    glscene->setGeometry(QRect(440, 0, 841, 761));
    openFile = new QPushButton(centralwidget);
    openFile->setObjectName(QString::fromUtf8("openFile"));
    openFile->setGeometry(QRect(10, 10, 421, 41));
    openFile->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "	font-size: 24px;\n"
                          "	border-width: 0px;\n"
                          "	border-color: rgb(90, 90,90 );\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	background-color: #F5F5F5;\n"
                          "	color: #ff033e;\n"
                          "}"));
    settings = new QPushButton(centralwidget);
    settings->setObjectName(QString::fromUtf8("settings"));
    settings->setGeometry(QRect(9, 710, 421, 40));
    settings->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "	font-size: 24px;\n"
                          "	border-width: 0px;\n"
                          "	border-color: rgb(90, 90,90 );\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	background-color: #F5F5F5;\n"
                          "	color: #ff033e;\n"
                          "}"));
    translateButton = new QPushButton(centralwidget);
    translateButton->setObjectName(QString::fromUtf8("translateButton"));
    translateButton->setGeometry(QRect(10, 270, 421, 41));
    translateButton->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "	font-size: 24px;\n"
                          "	border-width: 0px;\n"
                          "	border-color: rgb(90, 90,90 );\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	background-color: #F5F5F5;\n"
                          "	color: #ff033e;\n"
                          "}"));
    rotateButton = new QPushButton(centralwidget);
    rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
    rotateButton->setGeometry(QRect(10, 450, 421, 41));
    rotateButton->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "	font-size: 24px;\n"
                          "	border-width: 0px;\n"
                          "	border-color: rgb(90, 90,90 );\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	background-color: #F5F5F5;\n"
                          "	color: #ff033e;\n"
                          "}"));
    scaleButton = new QPushButton(centralwidget);
    scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
    scaleButton->setGeometry(QRect(10, 550, 421, 41));
    scaleButton->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "	font-size: 24px;\n"
                          "	border-width: 0px;\n"
                          "	border-color: rgb(90, 90,90 );\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	background-color: #F5F5F5;\n"
                          "	color: #ff033e;\n"
                          "}"));
    xTranslate = new QDoubleSpinBox(centralwidget);
    xTranslate->setObjectName(QString::fromUtf8("xTranslate"));
    xTranslate->setGeometry(QRect(230, 150, 200, 40));
    xTranslate->setFocusPolicy(Qt::ClickFocus);
    xTranslate->setStyleSheet(
        QString::fromUtf8("QDoubleSpinBox {\n"
                          "color: rgb(90, 90, 90);\n"
                          "font-size: 20px;\n"
                          "border-width: 0px;\n"
                          "border-radius: 12px;\n"
                          "border-color: rgb(90,90,90);\n"
                          "border-style: solid;\n"
                          "}\n"
                          "\n"
                          ""));
    xTranslate->setAlignment(Qt::AlignCenter);
    xTranslate->setPrefix(QString::fromUtf8(""));
    xTranslate->setDecimals(3);
    xTranslate->setMinimum(-999999.989999999990687);
    xTranslate->setMaximum(999999.989999999990687);
    xTrLabel = new QLabel(centralwidget);
    xTrLabel->setObjectName(QString::fromUtf8("xTrLabel"));
    xTrLabel->setGeometry(QRect(180, 150, 50, 40));
    xTrLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90,90,90);\n"
                          "font-size: 20px;"));
    xTrLabel->setAlignment(Qt::AlignCenter);
    yTranslate = new QDoubleSpinBox(centralwidget);
    yTranslate->setObjectName(QString::fromUtf8("yTranslate"));
    yTranslate->setGeometry(QRect(230, 190, 200, 40));
    yTranslate->setFocusPolicy(Qt::ClickFocus);
    yTranslate->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 20px;\n"
                          "border-width: 0px;\n"
                          "border-radius: 12px;\n"
                          "border-color: rgb(90,90,90);\n"
                          "border-style: solid;"));
    yTranslate->setAlignment(Qt::AlignCenter);
    yTranslate->setPrefix(QString::fromUtf8(""));
    yTranslate->setDecimals(3);
    yTranslate->setMinimum(-999999.989999999990687);
    yTranslate->setMaximum(999999.989999999990687);
    yTrLabel = new QLabel(centralwidget);
    yTrLabel->setObjectName(QString::fromUtf8("yTrLabel"));
    yTrLabel->setGeometry(QRect(180, 190, 50, 40));
    yTrLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90,90,90);\n"
                          "font-size: 20px;"));
    yTrLabel->setAlignment(Qt::AlignCenter);
    zTranslate = new QDoubleSpinBox(centralwidget);
    zTranslate->setObjectName(QString::fromUtf8("zTranslate"));
    zTranslate->setGeometry(QRect(230, 230, 200, 40));
    zTranslate->setFocusPolicy(Qt::ClickFocus);
    zTranslate->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 20px;\n"
                          "border-width: 0px;\n"
                          "border-radius: 12px;\n"
                          "border-color: rgb(90,90,90);\n"
                          "border-style: solid;"));
    zTranslate->setAlignment(Qt::AlignCenter);
    zTranslate->setPrefix(QString::fromUtf8(""));
    zTranslate->setDecimals(3);
    zTranslate->setMinimum(-999999.989999999990687);
    zTranslate->setMaximum(999999.989999999990687);
    zTrLabel = new QLabel(centralwidget);
    zTrLabel->setObjectName(QString::fromUtf8("zTrLabel"));
    zTrLabel->setGeometry(QRect(180, 230, 50, 40));
    zTrLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90,90,90);\n"
                          "font-size: 20px;"));
    zTrLabel->setAlignment(Qt::AlignCenter);
    yRotate = new QDoubleSpinBox(centralwidget);
    yRotate->setObjectName(QString::fromUtf8("yRotate"));
    yRotate->setGeometry(QRect(230, 360, 200, 40));
    yRotate->setFocusPolicy(Qt::ClickFocus);
    yRotate->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 20px;\n"
                          "border-width: 0px;\n"
                          "border-radius: 12px;\n"
                          "border-color: rgb(90,90,90);\n"
                          "border-style: solid;"));
    yRotate->setAlignment(Qt::AlignCenter);
    yRotate->setPrefix(QString::fromUtf8(""));
    yRotate->setDecimals(3);
    yRotate->setMinimum(-999999.989999999990687);
    yRotate->setMaximum(999999.989999999990687);
    zRrLabel = new QLabel(centralwidget);
    zRrLabel->setObjectName(QString::fromUtf8("zRrLabel"));
    zRrLabel->setGeometry(QRect(180, 400, 50, 40));
    zRrLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90,90,90);\n"
                          "font-size: 20px;"));
    zRrLabel->setAlignment(Qt::AlignCenter);
    xRotate = new QDoubleSpinBox(centralwidget);
    xRotate->setObjectName(QString::fromUtf8("xRotate"));
    xRotate->setGeometry(QRect(230, 320, 200, 40));
    xRotate->setFocusPolicy(Qt::ClickFocus);
    xRotate->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 20px;\n"
                          "border-width: 0px;\n"
                          "border-radius: 12px;\n"
                          "border-color: rgb(90,90,90);\n"
                          "border-style: solid;"));
    xRotate->setAlignment(Qt::AlignCenter);
    xRotate->setPrefix(QString::fromUtf8(""));
    xRotate->setDecimals(3);
    xRotate->setMinimum(-999999.989999999990687);
    xRotate->setMaximum(999999.989999999990687);
    yRrLabel = new QLabel(centralwidget);
    yRrLabel->setObjectName(QString::fromUtf8("yRrLabel"));
    yRrLabel->setGeometry(QRect(180, 360, 50, 40));
    yRrLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90,90,90);\n"
                          "font-size: 20px;"));
    yRrLabel->setAlignment(Qt::AlignCenter);
    xRrLabel = new QLabel(centralwidget);
    xRrLabel->setObjectName(QString::fromUtf8("xRrLabel"));
    xRrLabel->setGeometry(QRect(180, 320, 50, 40));
    xRrLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90,90,90);\n"
                          "font-size: 20px;"));
    xRrLabel->setAlignment(Qt::AlignCenter);
    zRotate = new QDoubleSpinBox(centralwidget);
    zRotate->setObjectName(QString::fromUtf8("zRotate"));
    zRotate->setGeometry(QRect(230, 400, 200, 40));
    zRotate->setFocusPolicy(Qt::ClickFocus);
    zRotate->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 20px;\n"
                          "border-width: 0px;\n"
                          "border-radius: 12px;\n"
                          "border-color: rgb(90,90,90);\n"
                          "border-style: solid;"));
    zRotate->setAlignment(Qt::AlignCenter);
    zRotate->setPrefix(QString::fromUtf8(""));
    zRotate->setDecimals(3);
    zRotate->setMinimum(-999999.989999999990687);
    zRotate->setMaximum(999999.989999999990687);
    scalateSpinBox = new QDoubleSpinBox(centralwidget);
    scalateSpinBox->setObjectName(QString::fromUtf8("scalateSpinBox"));
    scalateSpinBox->setGeometry(QRect(190, 500, 240, 40));
    scalateSpinBox->setFocusPolicy(Qt::ClickFocus);
    scalateSpinBox->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 20px;\n"
                          "border-width: 0px;\n"
                          "border-radius: 12px;\n"
                          "border-color: rgb(90,90,90);\n"
                          "border-style: solid;"));
    scalateSpinBox->setAlignment(Qt::AlignCenter);
    scalateSpinBox->setPrefix(QString::fromUtf8(""));
    scalateSpinBox->setDecimals(3);
    scalateSpinBox->setMinimum(0.000000000000000);
    scalateSpinBox->setMaximum(999999.989999999990687);
    scalateSpinBox->setSingleStep(0.100000000000000);
    gifButton = new QPushButton(centralwidget);
    gifButton->setObjectName(QString::fromUtf8("gifButton"));
    gifButton->setGeometry(QRect(10, 660, 421, 40));
    gifButton->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: #ff033e;\n"
                          "	border-color: #ff033e;\n"
                          "	border-width: 2px;\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "}"));
    jpegButton = new QPushButton(centralwidget);
    jpegButton->setObjectName(QString::fromUtf8("jpegButton"));
    jpegButton->setGeometry(QRect(9, 610, 201, 40));
    jpegButton->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: #ff033e;\n"
                          "	border-color: #ff033e;\n"
                          "	border-width: 2px;\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "}"));
    bmpButton = new QPushButton(centralwidget);
    bmpButton->setObjectName(QString::fromUtf8("bmpButton"));
    bmpButton->setGeometry(QRect(230, 610, 201, 40));
    bmpButton->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	color: #ff033e;\n"
                          "	border-color: #ff033e;\n"
                          "	border-width: 2px;\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "}"));
    sliderScalate = new QSlider(centralwidget);
    sliderScalate->setObjectName(QString::fromUtf8("sliderScalate"));
    sliderScalate->setGeometry(QRect(10, 510, 171, 31));
    sliderScalate->setStyleSheet(
        QString::fromUtf8("QSlider::groove:horizontal {  \n"
                          "            height: 10px;\n"
                          "            margin: 0px;\n"
                          "            border-radius: 5px;\n"
                          "            background: #B0AEB1;\n"
                          "}\n"
                          "QSlider::handle:horizontal {\n"
                          "            background: #fff;\n"
                          "            border: 1px solid #E3DEE2;\n"
                          "            width: 17px;\n"
                          "            margin: -5px 0; \n"
                          "            border-radius: 8px;\n"
                          "}\n"
                          "\n"
                          "QSlider::sub-page:qlineargradient {\n"
                          "           background: #ff033e;\n"
                          "           border-radius: 5px;\n"
                          "}\n"
                          "\n"
                          "QSlider::handle:horizontal:pressed {\n"
                          "	background:  #ff033e;\n"
                          "}"));
    sliderScalate->setMinimum(10);
    sliderScalate->setMaximum(200);
    sliderScalate->setSliderPosition(100);
    sliderScalate->setOrientation(Qt::Horizontal);
    sliderXRotate = new QSlider(centralwidget);
    sliderXRotate->setObjectName(QString::fromUtf8("sliderXRotate"));
    sliderXRotate->setGeometry(QRect(10, 330, 160, 25));
    sliderXRotate->setStyleSheet(
        QString::fromUtf8("QSlider::groove:horizontal {  \n"
                          "            height: 10px;\n"
                          "            margin: 0px;\n"
                          "            border-radius: 5px;\n"
                          "            background: #B0AEB1;\n"
                          "}\n"
                          "QSlider::handle:horizontal {\n"
                          "            background: #fff;\n"
                          "            border: 1px solid #E3DEE2;\n"
                          "            width: 17px;\n"
                          "            margin: -5px 0; \n"
                          "            border-radius: 8px;\n"
                          "}\n"
                          "\n"
                          "QSlider::sub-page:qlineargradient {\n"
                          "           background: #ff033e;\n"
                          "           border-radius: 5px;\n"
                          "}\n"
                          "\n"
                          "QSlider::handle:horizontal:pressed {\n"
                          "	background:  #ff033e;\n"
                          "}"));
    sliderXRotate->setMaximum(360);
    sliderXRotate->setOrientation(Qt::Horizontal);
    sliderYRotate = new QSlider(centralwidget);
    sliderYRotate->setObjectName(QString::fromUtf8("sliderYRotate"));
    sliderYRotate->setGeometry(QRect(10, 370, 160, 25));
    sliderYRotate->setStyleSheet(
        QString::fromUtf8("QSlider::groove:horizontal {  \n"
                          "            height: 10px;\n"
                          "            margin: 0px;\n"
                          "            border-radius: 5px;\n"
                          "            background: #B0AEB1;\n"
                          "}\n"
                          "QSlider::handle:horizontal {\n"
                          "            background: #fff;\n"
                          "            border: 1px solid #E3DEE2;\n"
                          "            width: 17px;\n"
                          "            margin: -5px 0; \n"
                          "            border-radius: 8px;\n"
                          "}\n"
                          "\n"
                          "QSlider::sub-page:qlineargradient {\n"
                          "           background: #ff033e;\n"
                          "           border-radius: 5px;\n"
                          "}\n"
                          "\n"
                          "QSlider::handle:horizontal:pressed {\n"
                          "	background:  #ff033e;\n"
                          "}"));
    sliderYRotate->setMaximum(360);
    sliderYRotate->setOrientation(Qt::Horizontal);
    sliderZRotate = new QSlider(centralwidget);
    sliderZRotate->setObjectName(QString::fromUtf8("sliderZRotate"));
    sliderZRotate->setGeometry(QRect(10, 410, 160, 25));
    sliderZRotate->setStyleSheet(
        QString::fromUtf8("QSlider::groove:horizontal {  \n"
                          "            height: 10px;\n"
                          "            margin: 0px;\n"
                          "            border-radius: 5px;\n"
                          "            background: #B0AEB1;\n"
                          "}\n"
                          "QSlider::handle:horizontal {\n"
                          "            background: #fff;\n"
                          "            border: 1px solid #E3DEE2;\n"
                          "            width: 17px;\n"
                          "            margin: -5px 0; \n"
                          "            border-radius: 8px;\n"
                          "}\n"
                          "\n"
                          "QSlider::sub-page:qlineargradient {\n"
                          "           background: #ff033e;\n"
                          "           border-radius: 5px;\n"
                          "}\n"
                          "\n"
                          "QSlider::handle:horizontal:pressed {\n"
                          "	background:  #ff033e;\n"
                          "}"));
    sliderZRotate->setMaximum(360);
    sliderZRotate->setOrientation(Qt::Horizontal);
    sliderXTranslate = new QSlider(centralwidget);
    sliderXTranslate->setObjectName(QString::fromUtf8("sliderXTranslate"));
    sliderXTranslate->setGeometry(QRect(10, 160, 160, 25));
    sliderXTranslate->setStyleSheet(
        QString::fromUtf8("QSlider::groove:horizontal {  \n"
                          "            height: 10px;\n"
                          "            margin: 0px;\n"
                          "            border-radius: 5px;\n"
                          "            background: #B0AEB1;\n"
                          "}\n"
                          "QSlider::handle:horizontal {\n"
                          "            background: #fff;\n"
                          "            border: 1px solid #E3DEE2;\n"
                          "            width: 17px;\n"
                          "            margin: -5px 0; \n"
                          "            border-radius: 8px;\n"
                          "}\n"
                          "\n"
                          "QSlider::sub-page:qlineargradient {\n"
                          "           background: #ff033e;\n"
                          "           border-radius: 5px;\n"
                          "}\n"
                          "\n"
                          "QSlider::handle:horizontal:pressed {\n"
                          "	background:  #ff033e;\n"
                          "}"));
    sliderXTranslate->setMinimum(-100);
    sliderXTranslate->setMaximum(100);
    sliderXTranslate->setOrientation(Qt::Horizontal);
    sliderZTranslate = new QSlider(centralwidget);
    sliderZTranslate->setObjectName(QString::fromUtf8("sliderZTranslate"));
    sliderZTranslate->setGeometry(QRect(10, 240, 160, 25));
    sliderZTranslate->setStyleSheet(
        QString::fromUtf8("QSlider::groove:horizontal {  \n"
                          "            height: 10px;\n"
                          "            margin: 0px;\n"
                          "            border-radius: 5px;\n"
                          "            background: #B0AEB1;\n"
                          "}\n"
                          "QSlider::handle:horizontal {\n"
                          "            background: #fff;\n"
                          "            border: 1px solid #E3DEE2;\n"
                          "            width: 17px;\n"
                          "            margin: -5px 0; \n"
                          "            border-radius: 8px;\n"
                          "}\n"
                          "\n"
                          "QSlider::sub-page:qlineargradient {\n"
                          "           background: #ff033e;\n"
                          "           border-radius: 5px;\n"
                          "}\n"
                          "\n"
                          "QSlider::handle:horizontal:pressed {\n"
                          "	background:  #ff033e;\n"
                          "}"));
    sliderZTranslate->setMinimum(-100);
    sliderZTranslate->setMaximum(100);
    sliderZTranslate->setOrientation(Qt::Horizontal);
    sliderYTranslate = new QSlider(centralwidget);
    sliderYTranslate->setObjectName(QString::fromUtf8("sliderYTranslate"));
    sliderYTranslate->setGeometry(QRect(10, 200, 160, 25));
    sliderYTranslate->setStyleSheet(
        QString::fromUtf8("QSlider::groove:horizontal {  \n"
                          "            height: 10px;\n"
                          "            margin: 0px;\n"
                          "            border-radius: 5px;\n"
                          "            background: #B0AEB1;\n"
                          "}\n"
                          "QSlider::handle:horizontal {\n"
                          "            background: #fff;\n"
                          "            border: 1px solid #E3DEE2;\n"
                          "            width: 17px;\n"
                          "            margin: -5px 0; \n"
                          "            border-radius: 8px;\n"
                          "}\n"
                          "\n"
                          "QSlider::sub-page:qlineargradient {\n"
                          "           background: #ff033e;\n"
                          "           border-radius: 5px;\n"
                          "}\n"
                          "\n"
                          "QSlider::handle:horizontal:pressed {\n"
                          "	background:  #ff033e;\n"
                          "}"));
    sliderYTranslate->setMinimum(-100);
    sliderYTranslate->setMaximum(100);
    sliderYTranslate->setOrientation(Qt::Horizontal);
    numberOfVertices = new QLabel(centralwidget);
    numberOfVertices->setObjectName(QString::fromUtf8("numberOfVertices"));
    numberOfVertices->setGeometry(QRect(220, 110, 201, 31));
    numberOfVertices->setStyleSheet(
        QString::fromUtf8("QLabel {\n"
                          "	color: #ff033e;\n"
                          "	border-color: #ff033e;\n"
                          "	border-width: 0px;\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}"));
    numberOfEdges = new QLabel(centralwidget);
    numberOfEdges->setObjectName(QString::fromUtf8("numberOfEdges"));
    numberOfEdges->setGeometry(QRect(10, 110, 201, 31));
    numberOfEdges->setStyleSheet(
        QString::fromUtf8("QLabel {\n"
                          "	color: #ff033e;\n"
                          "	border-color: #ff033e;\n"
                          "	border-width: 0px;\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}"));
    curFile = new QLabel(centralwidget);
    curFile->setObjectName(QString::fromUtf8("curFile"));
    curFile->setGeometry(QRect(10, 60, 421, 41));
    curFile->setStyleSheet(
        QString::fromUtf8("QLabel {\n"
                          "	color: #ff033e;\n"
                          "	border-color: #ff033e;\n"
                          "	border-width: 2px;\n"
                          "	border-style: solid;\n"
                          "	border-radius: 12px;\n"
                          "}"));
    curFile->setAlignment(Qt::AlignCenter);
    degree0 = new QLabel(centralwidget);
    degree0->setObjectName(QString::fromUtf8("degree0"));
    degree0->setGeometry(QRect(10, 315, 20, 15));
    degree0->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    degree0->setAlignment(Qt::AlignCenter);
    degree360 = new QLabel(centralwidget);
    degree360->setObjectName(QString::fromUtf8("degree360"));
    degree360->setGeometry(QRect(140, 315, 35, 15));
    degree360->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    degree360->setAlignment(Qt::AlignCenter);
    percent10 = new QLabel(centralwidget);
    percent10->setObjectName(QString::fromUtf8("percent10"));
    percent10->setGeometry(QRect(10, 500, 35, 15));
    percent10->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    percent10->setAlignment(Qt::AlignCenter);
    percent100 = new QLabel(centralwidget);
    percent100->setObjectName(QString::fromUtf8("percent100"));
    percent100->setGeometry(QRect(80, 500, 35, 15));
    percent100->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    percent100->setAlignment(Qt::AlignCenter);
    percent200 = new QLabel(centralwidget);
    percent200->setObjectName(QString::fromUtf8("percent200"));
    percent200->setGeometry(QRect(150, 500, 35, 15));
    percent200->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    percent200->setAlignment(Qt::AlignCenter);
    percent100_2 = new QLabel(centralwidget);
    percent100_2->setObjectName(QString::fromUtf8("percent100_2"));
    percent100_2->setGeometry(QRect(10, 145, 35, 15));
    percent100_2->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    percent100_2->setAlignment(Qt::AlignCenter);
    percent100_3 = new QLabel(centralwidget);
    percent100_3->setObjectName(QString::fromUtf8("percent100_3"));
    percent100_3->setGeometry(QRect(140, 145, 35, 15));
    percent100_3->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    percent100_3->setAlignment(Qt::AlignCenter);
    degree0_2 = new QLabel(centralwidget);
    degree0_2->setObjectName(QString::fromUtf8("degree0_2"));
    degree0_2->setGeometry(QRect(80, 145, 20, 15));
    degree0_2->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 14px;"));
    degree0_2->setAlignment(Qt::AlignCenter);
    MainWindow->setCentralWidget(centralwidget);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  }  // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(
        QCoreApplication::translate("MainWindow", "3DViewer 2.0", nullptr));
    openFile->setText(
        QCoreApplication::translate("MainWindow", "Open File", nullptr));
    settings->setText(
        QCoreApplication::translate("MainWindow", "Settings", nullptr));
    translateButton->setText(
        QCoreApplication::translate("MainWindow", "Translate", nullptr));
    rotateButton->setText(
        QCoreApplication::translate("MainWindow", "Rotate", nullptr));
    scaleButton->setText(
        QCoreApplication::translate("MainWindow", "Scalate", nullptr));
    xTranslate->setSpecialValueText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    xTrLabel->setText(
        QCoreApplication::translate("MainWindow", "x :", nullptr));
    yTranslate->setSpecialValueText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    yTrLabel->setText(
        QCoreApplication::translate("MainWindow", "y :", nullptr));
    zTranslate->setSpecialValueText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    zTrLabel->setText(
        QCoreApplication::translate("MainWindow", "z :", nullptr));
    yRotate->setSpecialValueText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    zRrLabel->setText(
        QCoreApplication::translate("MainWindow", "z :", nullptr));
    xRotate->setSpecialValueText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    yRrLabel->setText(
        QCoreApplication::translate("MainWindow", "y :", nullptr));
    xRrLabel->setText(
        QCoreApplication::translate("MainWindow", "x :", nullptr));
    zRotate->setSpecialValueText(
        QCoreApplication::translate("MainWindow", "x", nullptr));
    scalateSpinBox->setSpecialValueText(QString());
    gifButton->setText(
        QCoreApplication::translate("MainWindow", "Record gif", nullptr));
    jpegButton->setText(
        QCoreApplication::translate("MainWindow", "Save to jpeg", nullptr));
    bmpButton->setText(
        QCoreApplication::translate("MainWindow", "Save to bmp", nullptr));
    numberOfVertices->setText(
        QCoreApplication::translate("MainWindow", "Vertices:", nullptr));
    numberOfEdges->setText(
        QCoreApplication::translate("MainWindow", "Edges:", nullptr));
    curFile->setText(
        QCoreApplication::translate("MainWindow", "File name", nullptr));
    degree0->setText(
        QCoreApplication::translate("MainWindow", "0\302\260", nullptr));
    degree360->setText(
        QCoreApplication::translate("MainWindow", "360\302\260", nullptr));
    percent10->setText(
        QCoreApplication::translate("MainWindow", "50%", nullptr));
    percent100->setText(
        QCoreApplication::translate("MainWindow", "100%", nullptr));
    percent200->setText(
        QCoreApplication::translate("MainWindow", "200%", nullptr));
    percent100_2->setText(
        QCoreApplication::translate("MainWindow", "min", nullptr));
    percent100_3->setText(
        QCoreApplication::translate("MainWindow", "max", nullptr));
    degree0_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
  }  // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_MAINWINDOW_H
