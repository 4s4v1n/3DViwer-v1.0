// Copyright 2022 Savin Anton and Dyagteryov Andrey

#include "geometryengine.h"

#include <fstream>

namespace s21 {

GeometryEngine::GeometryEngine() : CPUMode(false) { InitData(); }

/* change drawing data */
void GeometryEngine::InitData() {
  _rotateMatrixCPU.SetToIdentity();
  _rotateMatrixGPU.setToIdentity();
  _translateVector.setX(0);
  _translateVector.setY(0);
  _translateVector.setZ(-5);
}

void GeometryEngine::ChangeRotateMatrix(double xAngle, double yAngle,
                                        double zAngle) {
  S21Matrix temp(3, 3);
  if (CPUMode) {
    if (xAngle != 0) {
      xAngle *= M_PI / 180.;
      temp.SetToIdentity();
      temp(1, 1) = cos(xAngle);
      temp(1, 2) = -sin(xAngle);
      temp(2, 1) = sin(xAngle);
      temp(2, 2) = cos(xAngle);
      _rotateMatrixCPU = _rotateMatrixCPU * temp;
    }
    if (yAngle != 0) {
      yAngle *= M_PI / 180.;
      temp.SetToIdentity();
      temp(0, 0) = cos(yAngle);
      temp(0, 2) = sin(yAngle);
      temp(2, 0) = -sin(yAngle);
      temp(2, 2) = cos(yAngle);
      _rotateMatrixCPU = _rotateMatrixCPU * temp;
    }
    if (zAngle != 0) {
      zAngle *= M_PI / 180.;
      temp.SetToIdentity();
      temp(0, 0) = cos(zAngle);
      temp(0, 1) = -sin(zAngle);
      temp(1, 0) = sin(zAngle);
      temp(1, 1) = cos(zAngle);
      _rotateMatrixCPU = _rotateMatrixCPU * temp;
    }
  } else {
    if (xAngle != 0) {
      _rotateMatrixGPU.rotate(xAngle, 1, 0, 0);
    }
    if (yAngle != 0) {
      _rotateMatrixGPU.rotate(yAngle, 0, 1, 0);
    }
    if (zAngle != 0) {
      _rotateMatrixGPU.rotate(zAngle, 0, 0, 1);
    }
  }
}

void GeometryEngine::ChangeScale(const double scale) {
  if (scale != 0) {
    if (CPUMode) {
      _rotateMatrixCPU *= scale;
    } else {
      _rotateMatrixGPU.scale(scale);
    }
  }
}

void GeometryEngine::ChangeTranslateVector(const double x, const double y,
                                           const double z) {
  if (x != 0.) {
    _translateVector.setX(_translateVector.x() + x);
  }
  if (y != 0.) {
    _translateVector.setY(_translateVector.y() + y);
  }
  if (z != 0.) {
    _translateVector.setZ(_translateVector.z() + z);
  }
}

void GeometryEngine::AffineTransformation(QVector3D &vec) {
  if (CPUMode) {
    S21Matrix tempCoordinate(3, 1);
    tempCoordinate(0, 0) = vec.x();
    tempCoordinate(1, 0) = vec.y();
    tempCoordinate(2, 0) = vec.z();
    tempCoordinate = _rotateMatrixCPU * tempCoordinate;
    vec.setX(tempCoordinate(0, 0));
    vec.setY(tempCoordinate(1, 0));
    vec.setZ(tempCoordinate(2, 0));
  } else {
    vec = _rotateMatrixGPU.mapVector(vec);
  }
  vec += _translateVector;
  vec.setZ(vec.z());
}

void GeometryEngine::SetDrawModeCPU(bool mode) { CPUMode = mode; }

}  // namespace s21
