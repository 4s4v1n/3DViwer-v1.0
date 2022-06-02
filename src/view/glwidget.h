// Copyright 2022 Savin Anton and Dyagteryov Andrey

#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QColor>
#include <QObject>
#include <QVector3D>
#include <QVector>
#include <QWidget>
#include <QtOpenGLWidgets/QtOpenGLWidgets>

#include "../controller/controller.h"
#include "../model/settingsmodel.h"

constexpr double verticesShift = 0.01;
constexpr double rotateSensative = 5.;
constexpr double translateSensative = 50.;

namespace Ui {
class GlWidget;
}

class GlWidget : public QOpenGLWidget {
  Q_OBJECT
 public:
  GlWidget(QWidget *parent = nullptr);
  ~GlWidget();

  void SetObject(QString fPath);

  void DrawObject();

  void DrawVertexes();

  void ApplySettings();

  s21::SettingsData *GetSettingsDataPtr();
  void SetController(s21::Controller *controller);

 protected:
  void initializeGL() override;
  void paintGL() override;

 private:
  s21::SettingsData *_facade;
  s21::Controller *_controller;
  void mouseMoveEvent(QMouseEvent *mouse) override;
  void wheelEvent(QWheelEvent *wheel) override;
};

#endif  // GLWIDGET_H
