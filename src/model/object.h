// Copyright 2022 Savin Anton and Dyagteryov Andrey

#ifndef OBJECT_H
#define OBJECT_H
#include <QVector3D>
#include <QVector>

namespace s21 {
class Object {
 public:
  Object();
  bool LoadObject(std::string fname);
  QVector<QVector3D> _vertexes;
  QVector<QVector<int>> _surfaces;

  double GetExtremeValue(QString type);

  qsizetype GetNumberOfEdges();

 private:
  double xMin, xMax, yMin, yMax, zMin, zMax;
  std::string GetDoubleFromLine(std::string &source,
                                std::string::iterator &iter);
};

}  // namespace s21
#endif  // OBJECT_H
