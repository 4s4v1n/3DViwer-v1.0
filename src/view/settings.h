// Copyright 2022 Savin Anton and Dyagteryov Andrey

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

#include "../controller/controller.h"
#include "../model/settingsmodel.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget {
  Q_OBJECT

 public:
  explicit Settings(QWidget *parent = nullptr);

  void SetController(s21::Controller *controller);
  void SetSettingsData(s21::SettingsData *data);
  void SetDataFromConfig();

  ~Settings();

 private slots:
  void on_apllySettings_clicked();
  void SetColor();

 private:
  QColor GetColor(std::string source);
  Ui::Settings *ui;
  s21::Controller *_controller = nullptr;
  s21::SettingsData *_facade;

  QColor _edgesColor;
  QColor _verticesColor;
  QColor _backgroundColor;
};

#endif  // SETTINGS_H
