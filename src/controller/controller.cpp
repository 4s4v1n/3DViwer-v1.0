// Copyright 2022 Savin Anton Degtyaryov Andrey

#include "controller.h"

#include <QMatrix4x4>

namespace s21 {

Controller::Controller() {}

Controller::~Controller() {}

bool Controller::SetCurFile(QString fPath) {
  bool open = _engine._object.LoadObject(fPath.toStdString());
  _engine.InitData();
  return open;
}

QVector3D Controller::GetVertex(const int i) {
  return _engine._object._vertexes[i];
}

QVector<int> Controller::GetFace(const int i) {
  return _engine._object._surfaces[i];
}

qsizetype Controller::GetFacesSize() {
  return _engine._object._surfaces.size();
}

/* extreme values */

double Controller::GetXMin() { return _engine._object.GetExtremeValue("xmin"); }
double Controller::GetXMax() { return _engine._object.GetExtremeValue("xmax"); }
double Controller::GetYMin() { return _engine._object.GetExtremeValue("ymin"); }
double Controller::GetYMax() { return _engine._object.GetExtremeValue("ymax"); }
double Controller::GetZMin() { return _engine._object.GetExtremeValue("zmin"); }
double Controller::GetZMax() { return _engine._object.GetExtremeValue("zmax"); }

/* Change rotate matrix */
void Controller::RotateX(double angle) {
  _engine.ChangeRotateMatrix(angle, 0, 0);
}
void Controller::RotateY(double angle) {
  _engine.ChangeRotateMatrix(0, angle, 0);
}
void Controller::RotateZ(double angle) {
  _engine.ChangeRotateMatrix(0, 0, angle);
}

/* change translate vector */
void Controller::TranslateX(const double x) {
  _engine.ChangeTranslateVector(x, 0, 0);
}
void Controller::TranslateY(const double y) {
  _engine.ChangeTranslateVector(0, y, 0);
}
void Controller::TranslateZ(const double z) {
  _engine.ChangeTranslateVector(0, 0, z);
}

/* scale rotate matrix */
void Controller::Scalate(const double scale) { _engine.ChangeScale(scale); }

/* change object coordinates via Rotate matrix and translate vector */
void Controller::CalcNewVec(QVector3D &vec) {
  _engine.AffineTransformation(vec);
}

qsizetype Controller::GetNumberOfEdges() {
  return _engine._object.GetNumberOfEdges();
}

void Controller::SetRenderMode(QString mode) {
  if (mode == "CPU")
    _engine.SetDrawModeCPU(true);
  else
    _engine.SetDrawModeCPU(false);
}

}  // namespace s21
