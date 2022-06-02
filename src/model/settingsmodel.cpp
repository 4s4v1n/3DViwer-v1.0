// Copyright 2022 Savin Anton and Dyagteryov Andrey

#include "settingsmodel.h"

#include <QDir>
#include <QFile>
#include <fstream>
#include <string>

namespace s21 {

SettingsData::SettingsData()
    : edgesThickness(0), verticesSize(0), renderMode("GPU") {}

/* settings setters && getters */

void SettingsData::SetColor(QString whatColor, QColor color) {
  if (whatColor == "background") {
    backgroundColor = color;
  } else if (whatColor == "edges") {
    edgesColor = color;
  } else if (whatColor == "vertices") {
    verticesColor = color;
  }
}

void SettingsData::SetProjectionType(QString type) {
  if (type == "parallel" || type == "central") projectionType = type;
}

void SettingsData::SetEdgesType(QString type) {
  if (type == "solid" || type == "dashed") edgesType = type;
}

void SettingsData::SetVerticesType(QString type) {
  if (type == "none" || type == "square" || type == "circle")
    verticesType = type;
}

void SettingsData::SetEdgesThickness(int thickness) {
  if (thickness > 0) edgesThickness = thickness;
}

void SettingsData::SetVerticesSize(int size) {
  if (size >= 0) verticesSize = size;
}

void SettingsData::SetRenderMode(QString mode) { renderMode = mode; }

QColor SettingsData::GetColor(QString whatColor) {
  if (whatColor == "background") {
    return backgroundColor;
  } else if (whatColor == "edges") {
    return edgesColor;
  } else if (whatColor == "vertices") {
    return verticesColor;
  }
  return QColor(0, 0, 0);
}

QString SettingsData::GetEdgesType() { return edgesType; }

QString SettingsData::GetVerticesType() { return verticesType; }

QString SettingsData::GetProjectionType() { return projectionType; }

int SettingsData::GetEdgesThickness() { return edgesThickness; }

int SettingsData::GetVerticesSize() { return verticesSize; }

// подается строка вида "255 255 255"
QColor SettingsData::GetColorFromFile(std::string source) {
  std::string line;
  int currentIndex = 0;
  int r =
      std::stoi(source.substr(currentIndex, source.find(' ') - currentIndex));
  currentIndex = source.find(' ') + 1;
  line = source.substr(currentIndex,
                       source.find(' ', currentIndex) - currentIndex);
  int g = std::stoi(line);
  currentIndex = source.find(' ', currentIndex) + 1;
  line = source.substr(currentIndex);
  int b = std::stoi(line);
  QColor out(r, g, b);
  return out;
}

QString SettingsData::GetRenderMode() { return renderMode; }

void SettingsData::WriteDataInConfig() {
  QString path = pathToConfig;
  std::fstream config;
  config.open(path.toStdString(), config.out);

  config << "projection_type: " + projectionType.toStdString() + '\n';
  config << "edges color: " + GetColorStr(edgesColor) + '\n';
  config << "vertices color: " + GetColorStr(verticesColor) + '\n';
  config << "background color: " + GetColorStr(backgroundColor) + '\n';
  config << "edges type: " + edgesType.toStdString() + '\n';
  config << "vertices type: " + verticesType.toStdString() + '\n';
  config << "edges thickness: " + std::to_string(edgesThickness) + '\n';
  config << "vertices size: " + std::to_string(verticesSize) + '\n';
  config << "render mode: " + renderMode.toStdString() + '\n';
}

std::string SettingsData::GetColorStr(QColor color) {
  std::string str;
  str = std::to_string(color.red()) + " " + std::to_string(color.green()) +
        " " + std::to_string(color.blue());
  return str;
}

void SettingsData::GetDataFromConfig() {
  QString path = pathToConfig;
  bool exist = QFile::exists(path);

  std::fstream config;
  config.open(path.toStdString(), config.in | config.out);

  if (exist) {
    std::string line;

    // projection type
    std::getline(config, line, '\n');
    if (line.find("central") != std::string::npos) {
      projectionType = "central";
    } else {
      projectionType = "parallel";
    }

    // edgesColor
    std::getline(config, line, '\n');
    QColor color = GetColorFromFile(line.substr(line.find(':') + 2));
    edgesColor = color;

    // vertices color
    std::getline(config, line, '\n');
    color = GetColorFromFile(line.substr(line.find(':') + 2));
    verticesColor = color;

    // back color
    std::getline(config, line, '\n');
    color = GetColorFromFile(line.substr(line.find(':') + 2));
    backgroundColor = color;

    // edges type
    std::getline(config, line, '\n');
    if (line.find("solid") != std::string::npos) {
      edgesType = "solid";
    } else {
      edgesType = "dashed";
    }

    // vertex type
    std::getline(config, line, '\n');
    if (line.find("none") != std::string::npos) {
      verticesType = "none";
    } else if (line.find("circle") != std::string::npos) {
      verticesType = "circle";
    } else if (line.find("square") != std::string::npos) {
      verticesType = "square";
    }

    // edges size
    std::getline(config, line, '\n');
    int thickness = std::stoi(line.substr(line.find(':') + 2));
    edgesThickness = thickness;

    // vertices size
    std::getline(config, line, '\n');
    thickness = std::stoi(line.substr(line.find(':') + 2));
    verticesSize = thickness;

    // render mode
    std::getline(config, line, '\n');
    if (line.find("CPU") != std::string::npos) {
      renderMode = "CPU";
    } else {
      renderMode = "GPU";
    }
  } else {
    projectionType = "central";
    edgesType = "solid";
    verticesType = "circle";
    edgesThickness = 2;
    verticesSize = 5;
    renderMode = "GPU";
    edgesColor = QColor(255, 5, 62);
    backgroundColor = QColor(245, 245, 245);
    verticesColor = QColor(57, 38, 255);

    config << "projection_type: " + projectionType.toStdString() + '\n';
    config << "edges color: " + GetColorStr(edgesColor) + '\n';
    config << "vertices color: " + GetColorStr(verticesColor) + '\n';
    config << "background color: " + GetColorStr(backgroundColor) + '\n';
    config << "edges type: " + edgesType.toStdString() + '\n';
    config << "vertices type: " + verticesType.toStdString() + '\n';
    config << "edges thickness: " + std::to_string(edgesThickness) + '\n';
    config << "vertices size: " + std::to_string(verticesSize) + '\n';
    config << "render mode: " + renderMode.toStdString() + '\n';
  }

  config.close();
}

}  // namespace s21
