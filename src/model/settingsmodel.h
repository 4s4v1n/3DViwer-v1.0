// Copyright 2022 Savin Anton and Dyagteryov Andrey

#ifndef SETTINGSDATA_H
#define SETTINGSDATA_H
#include <QColor>

namespace s21 {

class SettingsData {
 public:
  SettingsData();

  void SetColor(QString whatColor, QColor color);
  void SetProjectionType(QString type);
  void SetEdgesType(QString type);
  void SetVerticesType(QString type);
  void SetEdgesThickness(int thickness);
  void SetVerticesSize(int size);
  void SetRenderMode(QString mode);

  QColor GetColor(QString whatColor);
  QString GetEdgesType();
  QString GetVerticesType();
  QString GetProjectionType();

  int GetEdgesThickness();
  int GetVerticesSize();
  void GetDataFromConfig();
  QColor GetColorFromFile(std::string source);
  QString GetRenderMode();

  void WriteDataInConfig();

 private:
  QString projectionType;
  QColor edgesColor;
  QColor verticesColor;
  QColor backgroundColor;
  QString edgesType;
  QString verticesType;
  int edgesThickness;
  int verticesSize;
  QString renderMode;

  std::string GetColorStr(QColor color);

  QString pathToConfig = "./settings.conf";
};

}  // namespace s21

#endif  // SETTINGSDATA_H
