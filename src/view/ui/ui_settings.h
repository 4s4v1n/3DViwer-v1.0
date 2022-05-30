/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings {
 public:
  QLabel *projectionLabel;
  QPushButton *apllySettings;
  QLabel *edgesTypeLabel;
  QLabel *edgesColorLabel;
  QLabel *edgesWidthLabel;
  QPushButton *edgesColor;
  QPushButton *backColor;
  QLabel *backgroundColorLabel;
  QLabel *vertexSizeLabel;
  QLabel *vertrexColorLabel;
  QPushButton *vertColor;
  QSpinBox *edgesWidthidthSpinbox;
  QWidget *horizontalLayoutWidget;
  QHBoxLayout *edgesLayout;
  QRadioButton *dashedRButton;
  QRadioButton *solidRButton;
  QWidget *horizontalLayoutWidget_3;
  QHBoxLayout *vertexLayout;
  QRadioButton *noneRButton;
  QRadioButton *circleRButton;
  QRadioButton *squareRButton;
  QLabel *vertexTypeLabel;
  QWidget *horizontalLayoutWidget_2;
  QHBoxLayout *projectionLayout;
  QRadioButton *centralRBUtton;
  QRadioButton *paralelRButton;
  QSpinBox *verexSizeSpinbox;
  QLabel *edgesTypeLabel_2;
  QWidget *horizontalLayoutWidget_4;
  QHBoxLayout *RenderModeLayout;
  QRadioButton *CPURButton;
  QRadioButton *GPURButton;

  void setupUi(QWidget *Settings) {
    if (Settings->objectName().isEmpty())
      Settings->setObjectName(QString::fromUtf8("Settings"));
    Settings->setWindowModality(Qt::ApplicationModal);
    Settings->resize(540, 560);
    Settings->setMinimumSize(QSize(540, 560));
    Settings->setMaximumSize(QSize(540, 560));
    Settings->setStyleSheet(
        QString::fromUtf8("background-color: #F5F5F5;\n"
                          "font: 18pt \"JetBrains Mono\";"));
    projectionLabel = new QLabel(Settings);
    projectionLabel->setObjectName(QString::fromUtf8("projectionLabel"));
    projectionLabel->setGeometry(QRect(0, 0, 540, 40));
    projectionLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 24px;"));
    projectionLabel->setAlignment(Qt::AlignCenter);
    apllySettings = new QPushButton(Settings);
    apllySettings->setObjectName(QString::fromUtf8("apllySettings"));
    apllySettings->setGeometry(QRect(10, 510, 521, 40));
    apllySettings->setStyleSheet(
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
    edgesTypeLabel = new QLabel(Settings);
    edgesTypeLabel->setObjectName(QString::fromUtf8("edgesTypeLabel"));
    edgesTypeLabel->setGeometry(QRect(0, 89, 540, 31));
    edgesTypeLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 24px;\n"
                          "border-width: 3px 0px 0px 0px;\n"
                          "border-style: solid;\n"
                          "border-color: rgb(90, 90,90);"));
    edgesTypeLabel->setAlignment(Qt::AlignCenter);
    edgesColorLabel = new QLabel(Settings);
    edgesColorLabel->setObjectName(QString::fromUtf8("edgesColorLabel"));
    edgesColorLabel->setGeometry(QRect(270, 200, 270, 40));
    edgesColorLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 24px;"));
    edgesColorLabel->setAlignment(Qt::AlignCenter);
    edgesWidthLabel = new QLabel(Settings);
    edgesWidthLabel->setObjectName(QString::fromUtf8("edgesWidthLabel"));
    edgesWidthLabel->setGeometry(QRect(0, 160, 270, 31));
    edgesWidthLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 20px;"));
    edgesWidthLabel->setAlignment(Qt::AlignCenter);
    edgesColor = new QPushButton(Settings);
    edgesColor->setObjectName(QString::fromUtf8("edgesColor"));
    edgesColor->setGeometry(QRect(10, 200, 251, 41));
    edgesColor->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	border-style: solid;\n"
                          "	border-width: 2px;\n"
                          "	border-color: #ff033e;\n"
                          "	border-radius: 12px;\n"
                          "	color: #ff033e;\n"
                          "	font-size: 20px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "}"));
    backColor = new QPushButton(Settings);
    backColor->setObjectName(QString::fromUtf8("backColor"));
    backColor->setGeometry(QRect(10, 390, 251, 41));
    backColor->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	border-style: solid;\n"
                          "	border-width: 2px;\n"
                          "	border-color: #ff033e;\n"
                          "	border-radius: 12px;\n"
                          "	color: #ff033e;\n"
                          "	font-size: 20px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "}"));
    backgroundColorLabel = new QLabel(Settings);
    backgroundColorLabel->setObjectName(
        QString::fromUtf8("backgroundColorLabel"));
    backgroundColorLabel->setGeometry(QRect(270, 390, 270, 41));
    backgroundColorLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 24px;"));
    backgroundColorLabel->setAlignment(Qt::AlignCenter);
    vertexSizeLabel = new QLabel(Settings);
    vertexSizeLabel->setObjectName(QString::fromUtf8("vertexSizeLabel"));
    vertexSizeLabel->setGeometry(QRect(0, 365, 271, 21));
    vertexSizeLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 20px;"));
    vertexSizeLabel->setAlignment(Qt::AlignCenter);
    vertrexColorLabel = new QLabel(Settings);
    vertrexColorLabel->setObjectName(QString::fromUtf8("vertrexColorLabel"));
    vertrexColorLabel->setGeometry(QRect(270, 320, 270, 40));
    vertrexColorLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 24px;"));
    vertrexColorLabel->setAlignment(Qt::AlignCenter);
    vertColor = new QPushButton(Settings);
    vertColor->setObjectName(QString::fromUtf8("vertColor"));
    vertColor->setGeometry(QRect(10, 319, 251, 41));
    vertColor->setStyleSheet(
        QString::fromUtf8("QPushButton {\n"
                          "	border-style: solid;\n"
                          "	border-width: 2px;\n"
                          "	border-color: #ff033e;\n"
                          "	border-radius: 12px;\n"
                          "	color: #ff033e;\n"
                          "	font-size: 20px;\n"
                          "}\n"
                          "\n"
                          "QPushButton:pressed {\n"
                          "	color: rgb(255, 255, 255);\n"
                          "	background-color: #ff033e;\n"
                          "}"));
    edgesWidthidthSpinbox = new QSpinBox(Settings);
    edgesWidthidthSpinbox->setObjectName(
        QString::fromUtf8("edgesWidthidthSpinbox"));
    edgesWidthidthSpinbox->setGeometry(QRect(270, 160, 270, 40));
    edgesWidthidthSpinbox->setStyleSheet(
        QString::fromUtf8("border-style: none;\n"
                          "color: rgb(90,90,90);\n"
                          ""));
    edgesWidthidthSpinbox->setAlignment(Qt::AlignCenter);
    horizontalLayoutWidget = new QWidget(Settings);
    horizontalLayoutWidget->setObjectName(
        QString::fromUtf8("horizontalLayoutWidget"));
    horizontalLayoutWidget->setGeometry(QRect(0, 120, 541, 41));
    edgesLayout = new QHBoxLayout(horizontalLayoutWidget);
    edgesLayout->setObjectName(QString::fromUtf8("edgesLayout"));
    edgesLayout->setContentsMargins(0, 0, 0, 0);
    dashedRButton = new QRadioButton(horizontalLayoutWidget);
    dashedRButton->setObjectName(QString::fromUtf8("dashedRButton"));
    dashedRButton->setLayoutDirection(Qt::LeftToRight);
    dashedRButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));
    dashedRButton->setChecked(false);
    dashedRButton->setAutoExclusive(true);

    edgesLayout->addWidget(dashedRButton);

    solidRButton = new QRadioButton(horizontalLayoutWidget);
    solidRButton->setObjectName(QString::fromUtf8("solidRButton"));
    solidRButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));
    solidRButton->setChecked(true);
    solidRButton->setAutoExclusive(true);

    edgesLayout->addWidget(solidRButton);

    horizontalLayoutWidget_3 = new QWidget(Settings);
    horizontalLayoutWidget_3->setObjectName(
        QString::fromUtf8("horizontalLayoutWidget_3"));
    horizontalLayoutWidget_3->setGeometry(QRect(0, 280, 541, 31));
    vertexLayout = new QHBoxLayout(horizontalLayoutWidget_3);
    vertexLayout->setObjectName(QString::fromUtf8("vertexLayout"));
    vertexLayout->setContentsMargins(0, 0, 0, 0);
    noneRButton = new QRadioButton(horizontalLayoutWidget_3);
    noneRButton->setObjectName(QString::fromUtf8("noneRButton"));
    noneRButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));
    noneRButton->setChecked(true);

    vertexLayout->addWidget(noneRButton);

    circleRButton = new QRadioButton(horizontalLayoutWidget_3);
    circleRButton->setObjectName(QString::fromUtf8("circleRButton"));
    circleRButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));

    vertexLayout->addWidget(circleRButton);

    squareRButton = new QRadioButton(horizontalLayoutWidget_3);
    squareRButton->setObjectName(QString::fromUtf8("squareRButton"));
    squareRButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));

    vertexLayout->addWidget(squareRButton);

    vertexTypeLabel = new QLabel(Settings);
    vertexTypeLabel->setObjectName(QString::fromUtf8("vertexTypeLabel"));
    vertexTypeLabel->setGeometry(QRect(0, 249, 541, 31));
    vertexTypeLabel->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90, 90);\n"
                          "font-size: 24px;\n"
                          "border-width: 3px 0px 0px 0px;\n"
                          "border-style: solid;\n"
                          "border-color: rgb(90, 90,90);"));
    vertexTypeLabel->setAlignment(Qt::AlignCenter);
    horizontalLayoutWidget_2 = new QWidget(Settings);
    horizontalLayoutWidget_2->setObjectName(
        QString::fromUtf8("horizontalLayoutWidget_2"));
    horizontalLayoutWidget_2->setGeometry(QRect(0, 40, 541, 41));
    projectionLayout = new QHBoxLayout(horizontalLayoutWidget_2);
    projectionLayout->setObjectName(QString::fromUtf8("projectionLayout"));
    projectionLayout->setContentsMargins(0, 0, 0, 0);
    centralRBUtton = new QRadioButton(horizontalLayoutWidget_2);
    centralRBUtton->setObjectName(QString::fromUtf8("centralRBUtton"));
    centralRBUtton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));
    centralRBUtton->setChecked(false);
    centralRBUtton->setAutoExclusive(true);

    projectionLayout->addWidget(centralRBUtton);

    paralelRButton = new QRadioButton(horizontalLayoutWidget_2);
    paralelRButton->setObjectName(QString::fromUtf8("paralelRButton"));
    paralelRButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));
    paralelRButton->setChecked(true);
    paralelRButton->setAutoExclusive(true);

    projectionLayout->addWidget(paralelRButton);

    verexSizeSpinbox = new QSpinBox(Settings);
    verexSizeSpinbox->setObjectName(QString::fromUtf8("verexSizeSpinbox"));
    verexSizeSpinbox->setGeometry(QRect(270, 360, 270, 31));
    verexSizeSpinbox->setStyleSheet(
        QString::fromUtf8("border-style: none;\n"
                          "color: rgb(90,90,90);\n"
                          ""));
    verexSizeSpinbox->setAlignment(Qt::AlignCenter);
    edgesTypeLabel_2 = new QLabel(Settings);
    edgesTypeLabel_2->setObjectName(QString::fromUtf8("edgesTypeLabel_2"));
    edgesTypeLabel_2->setGeometry(QRect(0, 439, 540, 31));
    edgesTypeLabel_2->setStyleSheet(
        QString::fromUtf8("color: rgb(90, 90,90);\n"
                          "font-size: 24px;\n"
                          "border-width: 3px 0px 0px 0px;\n"
                          "border-style: solid;\n"
                          "border-color: rgb(90, 90,90);"));
    edgesTypeLabel_2->setAlignment(Qt::AlignCenter);
    horizontalLayoutWidget_4 = new QWidget(Settings);
    horizontalLayoutWidget_4->setObjectName(
        QString::fromUtf8("horizontalLayoutWidget_4"));
    horizontalLayoutWidget_4->setGeometry(QRect(0, 470, 541, 41));
    RenderModeLayout = new QHBoxLayout(horizontalLayoutWidget_4);
    RenderModeLayout->setObjectName(QString::fromUtf8("RenderModeLayout"));
    RenderModeLayout->setContentsMargins(0, 0, 0, 0);
    CPURButton = new QRadioButton(horizontalLayoutWidget_4);
    CPURButton->setObjectName(QString::fromUtf8("CPURButton"));
    CPURButton->setLayoutDirection(Qt::LeftToRight);
    CPURButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));
    CPURButton->setChecked(false);
    CPURButton->setAutoExclusive(true);

    RenderModeLayout->addWidget(CPURButton);

    GPURButton = new QRadioButton(horizontalLayoutWidget_4);
    GPURButton->setObjectName(QString::fromUtf8("GPURButton"));
    GPURButton->setStyleSheet(QString::fromUtf8("color: #ff033e;"));
    GPURButton->setChecked(true);
    GPURButton->setAutoExclusive(true);

    RenderModeLayout->addWidget(GPURButton);

    retranslateUi(Settings);

    QMetaObject::connectSlotsByName(Settings);
  }  // setupUi

  void retranslateUi(QWidget *Settings) {
    Settings->setWindowTitle(
        QCoreApplication::translate("Settings", "Settings", nullptr));
    projectionLabel->setText(
        QCoreApplication::translate("Settings", "Projection type", nullptr));
    apllySettings->setText(
        QCoreApplication::translate("Settings", "Apply", nullptr));
    edgesTypeLabel->setText(
        QCoreApplication::translate("Settings", "Edges type", nullptr));
    edgesColorLabel->setText(QString());
    edgesWidthLabel->setText(
        QCoreApplication::translate("Settings", "Edges width", nullptr));
    edgesColor->setText(
        QCoreApplication::translate("Settings", "Set edges color", nullptr));
    backColor->setText(QCoreApplication::translate(
        "Settings", "Set background color", nullptr));
    backgroundColorLabel->setText(QString());
    vertexSizeLabel->setText(
        QCoreApplication::translate("Settings", "Vertices size", nullptr));
    vertrexColorLabel->setText(QString());
    vertColor->setText(
        QCoreApplication::translate("Settings", "Set vertices color", nullptr));
    dashedRButton->setText(
        QCoreApplication::translate("Settings", "Dashed", nullptr));
    solidRButton->setText(
        QCoreApplication::translate("Settings", "Solid", nullptr));
    noneRButton->setText(
        QCoreApplication::translate("Settings", "None", nullptr));
    circleRButton->setText(
        QCoreApplication::translate("Settings", "Circle", nullptr));
    squareRButton->setText(
        QCoreApplication::translate("Settings", "Square", nullptr));
    vertexTypeLabel->setText(
        QCoreApplication::translate("Settings", "Vertexes type", nullptr));
    centralRBUtton->setText(
        QCoreApplication::translate("Settings", "Central", nullptr));
    paralelRButton->setText(
        QCoreApplication::translate("Settings", "Paralel", nullptr));
    edgesTypeLabel_2->setText(
        QCoreApplication::translate("Settings", "Render Mode", nullptr));
    CPURButton->setText(
        QCoreApplication::translate("Settings", "CPU", nullptr));
    GPURButton->setText(
        QCoreApplication::translate("Settings", "GPU", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Settings : public Ui_Settings {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_SETTINGS_H
