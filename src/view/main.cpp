// Copyright 2022 Savin Anton and Dyagteryov Andrey

#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Controller controller;
  QLocale::setDefault(QLocale(QLocale::English, QLocale::UnitedStates));
  MainWindow w(nullptr, &controller);
  w.show();
  return a.exec();
}
