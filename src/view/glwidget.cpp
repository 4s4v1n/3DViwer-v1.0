// Copyright 2022 Savin Anton and Dyagteryov Andrey

#include "glwidget.h"

#include <GLUT/glut.h>

#include <fstream>

static const double rotateSensative = 5.;
static const double translateSensative = 50.;

GlWidget::GlWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      _facade(new s21::SettingsData),
      _controller(nullptr) {}

GlWidget::~GlWidget() { delete _facade; }

void GlWidget::SetObject(QString fPath) { _controller->SetCurFile(fPath); }

void GlWidget::DrawObject() {
  QColor color = _facade->GetColor("edges");
  glLineWidth(_facade->GetEdgesThickness());
  glColor3f(color.red() / 255.0, color.green() / 255.0, color.blue() / 255.0);
  if (_facade->GetEdgesType() == "dashed") {
    glLineStipple(4, 0x1111);
  } else {
    glLineStipple(4, 0xFFFF);
  }
  for (qsizetype i = 0, size = _controller->GetFacesSize(); i < size; ++i) {
    glBegin(GL_LINE_LOOP);
    QVector<int> face = _controller->GetFace(i);
    for (qsizetype j = 0, fSize = face.size(); j < fSize; ++j) {
      QVector3D point = _controller->GetVertex(face[j] - 1);
      _controller->CalcNewVec(point);
      glVertex3f(static_cast<GLfloat>(point.x()),
                 static_cast<GLfloat>(point.y()),
                 static_cast<GLfloat>(point.z()));
    }
    glEnd();
  }
}

void GlWidget::DrawVertexes() {
  if (_facade->GetVerticesType() != "none") {
    if (_facade->GetVerticesType() == "circle") {
      glEnable(GL_POINT_SMOOTH);
    } else if (_facade->GetVerticesType() == "square") {
      glDisable(GL_POINT_SMOOTH);
      glEnable(GL_POINT);
    }
    glPointSize(_facade->GetVerticesSize());
    QColor color = _facade->GetColor("vertices");
    glColor3f(color.red() / 255.0, color.green() / 255.0, color.blue() / 255.0);
    for (qsizetype i = 0, size = _controller->GetFacesSize(); i < size; ++i) {
      glBegin(GL_POINTS);
      QVector<int> face = _controller->GetFace(i);
      for (qsizetype j = 0, fSize = face.size(); j < fSize; ++j) {
        QVector3D point = _controller->GetVertex(face[j] - 1);
        _controller->CalcNewVec(point);
        glVertex3f(static_cast<GLfloat>(point.x()),
                   static_cast<GLfloat>(point.y()),
                   static_cast<GLfloat>(point.z()));
      }
      glEnd();
    }
  }
}

void GlWidget::ApplySettings() {
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  QColor color = _facade->GetColor("background");
  glClearColor(color.red() / 255.0, color.green() / 255.0, color.blue() / 255.0,
               1.0);

  if (_facade->GetProjectionType() == "central") {
    gluPerspective(100, 1.2, 0.1, 1000.0);
  } else {
    glOrtho(_controller->GetXMin() * 2, _controller->GetXMax() * 2,
            _controller->GetYMin() * 2, _controller->GetYMax() * 2, -10, 10);
  }

  if (_facade) _controller->SetRenderMode(_facade->GetRenderMode());
}

s21::SettingsData *GlWidget::GetSettingsDataPtr() { return _facade; }

void GlWidget::initializeGL() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LINE_STIPPLE);
  glClearColor(0.7, 0.0, 0.7, 1.);
  _facade->GetDataFromConfig();
  ApplySettings();
}

void GlWidget::paintGL() {
  ApplySettings();
  DrawObject();
  DrawVertexes();
}

void GlWidget::SetController(s21::Controller *controller) {
  _controller = controller;
}

void GlWidget::mouseMoveEvent(QMouseEvent *mouse) {
  static int currentX = 0;
  static int currentY = 0;
  if (!currentX && !currentY) {
    currentX = mouse->pos().x();
    currentY = mouse->pos().y();
  }
  if (abs(mouse->pos().x() - currentX) < translateSensative &&
      abs(mouse->pos().y() - currentY) < translateSensative) {
    if (mouse->buttons() & Qt::LeftButton) {
      _controller->TranslateX(static_cast<double>(mouse->pos().x() - currentX) /
                              translateSensative);
      _controller->TranslateY(static_cast<double>(mouse->pos().y() - currentY) /
                              -translateSensative);
    } else {
      _controller->RotateY(static_cast<double>(mouse->pos().x() - currentX) /
                           -rotateSensative);
      _controller->RotateX(static_cast<double>(mouse->pos().y() - currentY) /
                           rotateSensative);
    }
  }
  currentX = mouse->pos().x();
  currentY = mouse->pos().y();
  this->update();
}

void GlWidget::wheelEvent(QWheelEvent *wheel) {
  if (wheel->angleDelta().y() > 0) {
    _controller->Scalate(1.1);
  } else {
    _controller->Scalate(0.9);
  }
  this->update();
}
