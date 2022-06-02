// Copyright 2022 Savin Anton and Dyagteryov Andrey

#ifndef GEOMETRYENGINE_H
#define GEOMETRYENGINE_H

#include <QMatrix4x4>
#include <QVector3D>
#include <QVector>

#include "matrix/s21_matrix_oop.h"
#include "object.h"

namespace s21 {

class GeometryEngine {
 public:
  GeometryEngine();

  Object _object;

  /* drawing object */

  void InitData();

  void ChangeRotateMatrix(double xAngle, double yAngle, double zAngle);
  void ChangeScale(const double scale);
  void ChangeTranslateVector(const double x, const double y, const double z);

  void AffineTransformation(QVector3D &vec);

  void SetDrawModeCPU(bool mode);

 private:
  /* drawing preferences */
  bool CPUMode;

  /* data for drawing (rotating, translating etc) */
  QMatrix4x4 _rotateMatrixGPU;
  S21Matrix _rotateMatrixCPU;
  QVector3D _translateVector;
};

}  // namespace s21

#endif  // GEOMETRYENGINE_H
