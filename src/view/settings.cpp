// Copyright 2022 Savin Anton and Dyagteryov Andrey

#include "settings.h"

#include <QColorDialog>
#include <QDir>
#include <fstream>
#include <string>

#include "ui/ui_settings.h"

Settings::Settings(QWidget *parent) : QWidget(parent), ui(new Ui::Settings) {
  ui->setupUi(this);
  connect(ui->backColor, SIGNAL(clicked()), this, SLOT(SetColor()));
  connect(ui->edgesColor, SIGNAL(clicked()), this, SLOT(SetColor()));
  connect(ui->vertColor, SIGNAL(clicked()), this, SLOT(SetColor()));
}

void Settings::SetController(s21::Controller *controller) {
  _controller = controller;
}

void Settings::SetSettingsData(s21::SettingsData *data) { _facade = data; }

void Settings::SetDataFromConfig() {
  QString styleSheet = "QLabel {background-color: rgb(";
  if (_facade->GetProjectionType() == "central") {
    ui->centralRBUtton->setChecked(true);
  } else {
    ui->paralelRButton->setChecked(true);
  }

  if (_facade->GetEdgesType() == "dashed") {
    ui->dashedRButton->setChecked(true);
  } else {
    ui->solidRButton->setChecked(true);
  }

  if (_facade->GetVerticesType() == "none") {
    ui->noneRButton->setChecked(true);
  } else if (_facade->GetVerticesType() == "circle") {
    ui->circleRButton->setChecked(true);
  } else {
    ui->squareRButton->setChecked(true);
  }

  if (_facade->GetRenderMode() == "CPU") {
    ui->CPURButton->setChecked(true);
  } else {
    ui->GPURButton->setChecked(true);
  }

  ui->edgesWidthidthSpinbox->setValue(_facade->GetEdgesThickness());
  ui->verexSizeSpinbox->setValue(_facade->GetVerticesSize());

  QColor color = _facade->GetColor("edges");
  _edgesColor = color;
  ui->edgesColorLabel->setStyleSheet(styleSheet + QString::number(color.red()) +
                                     ", " + QString::number(color.green()) +
                                     ", " + QString::number(color.blue()) +
                                     ");}");

  color = _facade->GetColor("vertices");
  _verticesColor = color;
  ui->vertrexColorLabel->setStyleSheet(styleSheet +
                                       QString::number(color.red()) + ", " +
                                       QString::number(color.green()) + ", " +
                                       QString::number(color.blue()) + ");}");

  color = _facade->GetColor("background");
  _backgroundColor = color;
  ui->backgroundColorLabel->setStyleSheet(
      styleSheet + QString::number(color.red()) + ", " +
      QString::number(color.green()) + ", " + QString::number(color.blue()) +
      ");}");
}

Settings::~Settings() { delete ui; }

void Settings::on_apllySettings_clicked() {
  _facade->SetColor("edges", _edgesColor);
  _facade->SetColor("background", _backgroundColor);
  _facade->SetColor("vertices", _verticesColor);

  if (ui->centralRBUtton->isChecked())
    _facade->SetProjectionType("central");
  else
    _facade->SetProjectionType("parallel");

  if (ui->circleRButton->isChecked()) {
    _facade->SetVerticesType("circle");
  } else if (ui->squareRButton->isChecked()) {
    _facade->SetVerticesType("square");
  } else {
    _facade->SetVerticesType("none");
  }

  if (ui->dashedRButton->isChecked()) {
    _facade->SetEdgesType("dashed");
  } else {
    _facade->SetEdgesType("solid");
  }

  if (ui->CPURButton->isChecked()) {
    _facade->SetRenderMode("CPU");
  } else {
    _facade->SetRenderMode("GPU");
  }

  _facade->SetEdgesThickness(ui->edgesWidthidthSpinbox->text().toInt());
  _facade->SetVerticesSize(ui->verexSizeSpinbox->text().toInt());
  _facade->WriteDataInConfig();
  this->close();
}

void Settings::SetColor() {
  QColorDialog colorDialog;
  QColor color;
  QPushButton *button = static_cast<QPushButton *>(sender());
  color = colorDialog.getColor();
  //    background-color: rgb(255, 209, 226);
  QString colorCSS = "QLabel { background-color: rgb(" +
                     QString::number(color.red()) + ", " +
                     QString::number(color.green()) + ", " +
                     QString::number(color.blue()) + ");}";
  if (color.isValid()) {
    if (button->text() == "Set vertices color") {
      // поставить цвет вершин
      ui->vertrexColorLabel->setStyleSheet(colorCSS);
      _verticesColor = color;
    } else if (button->text() == "Set edges color") {
      // поставить цвет ребер
      ui->edgesColorLabel->setStyleSheet(colorCSS);
      _edgesColor = color;
    } else if (button->text() == "Set background color") {
      ui->backgroundColorLabel->setStyleSheet(colorCSS);
      _backgroundColor = color;
      // поставить цвет заднего плана
    }
  }
}

QColor Settings::GetColor(std::string source) {
  std::string line;
  int r = std::stoi(source);
  line = source.substr(source.find(' ') + 1);
  int g = std::stoi(line);
  int b = std::stoi(line.substr(source.find(' ') + 1));
  QColor out(r, g, b);
  return out;
}
