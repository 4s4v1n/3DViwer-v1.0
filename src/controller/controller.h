#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QColor>
#include <QString>

#include "model/geometryengine.h"

namespace s21 {
class Controller {
 public:
  Controller();
  ~Controller();
  bool SetCurFile(QString fname);

  QVector3D GetVertex(const int i);
  QVector<int> GetFace(const int i);
  qsizetype GetFacesSize();

  /* extreme values */
  double GetXMin();
  double GetXMax();
  double GetYMin();
  double GetYMax();
  double GetZMin();
  double GetZMax();

  /* Change RotateMatrix and translate vector*/
  void RotateX(double angle);
  void RotateY(double angle);
  void RotateZ(double angle);

  void TranslateX(const double angle);
  void TranslateY(const double angle);
  void TranslateZ(const double angle);

  void Scalate(const double scale);

  /* change object vector */
  void CalcNewVec(QVector3D &vec);

  qsizetype GetNumberOfEdges();

  void SetRenderMode(QString mode);

 private:
  GeometryEngine _engine;
};

}  // namespace s21

#endif  // CONTROLLER_H
