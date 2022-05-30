// Copyright 2022 Savin Anton and Degtyaryov Andrey

#include "object.h"

#include <fstream>
#include <string>

namespace s21 {

Object::Object() : xMin(0), xMax(0), yMin(0), yMax(0), zMin(0), zMax(0) {}

bool Object::LoadObject(std::string fname) {
  _vertexes.clear();
  _surfaces.clear();
  std::fstream file(fname, file.in);
  if (!file.is_open()) return false;
  while (file.eof() == false) {
    std::string line;
    std::getline(file, line, '\n');
    auto left = line.begin(), right = line.end();
    if (*left == 'v' && *(left + 1) == ' ') {
      left += 2;
      QVector3D newPoint;
      newPoint.setX(std::stod(GetDoubleFromLine(line, left)));
      if (newPoint.x() < xMin) xMin = newPoint.x();
      if (newPoint.x() > xMax) xMax = newPoint.x();
      newPoint.setY(std::stod(GetDoubleFromLine(line, left)));
      if (newPoint.y() < yMin) yMin = newPoint.y();
      if (newPoint.y() > yMax) yMax = newPoint.y();
      newPoint.setZ(std::stod(GetDoubleFromLine(line, left)));
      if (newPoint.z() < zMin) zMin = newPoint.z();
      if (newPoint.z() > zMax) zMax = newPoint.z();
      _vertexes.push_back(newPoint);
    }

    if (*left == 'f' && *(left + 1) == ' ') {
      left += 2;
      QVector<int> newSurface;
      while (left != right)
        newSurface.push_back(std::stod(GetDoubleFromLine(line, left)));
      _surfaces.push_back(newSurface);
    }
  }
  return true;
}

std::string Object::GetDoubleFromLine(std::string &source,
                                      std::string::iterator &iter) {
  size_t start = iter - source.begin();
  size_t end = source.find(' ', start);
  std::string out;
  if (end != std::string::npos) {
    out = source.substr(start, end - start);
    iter += end - start + 1;
  } else {
    out = source.substr(start);
    iter = source.end();
  }
  return out;
}

double Object::GetExtremeValue(QString type) {
  double res = nan("1");
  if (type == "xmin") res = xMin;
  if (type == "xmax") res = xMax;
  if (type == "ymin") res = yMin;
  if (type == "ymax") res = yMax;
  if (type == "zmin") res = zMin;
  if (type == "zmax") res = zMax;
  return res;
}

qsizetype Object::GetNumberOfEdges() {
  qsizetype ret = 0;
  for (qsizetype i = 0, size = _surfaces.size(), edge; i < size; i++) {
    edge = _surfaces[i].size();
    if (edge == 2) {
      ret += 1;
    } else {
      ret += edge;
    }
  }
  return ret;
}

}  // namespace s21
