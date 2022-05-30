// Copyright 2022 Savin Anton and Dyagteryov Andrey

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../model/settingsmodel.h"
#include "glwidget.h"
#include "qgifimage.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  MainWindow(QWidget *parent = nullptr, s21::Controller *controller = nullptr);
  ~MainWindow();

 private slots:
  void on_openFile_clicked();
  void on_settings_clicked();
  void on_gifButton_clicked();
  void savePicture();
  void takeFrame();

  void on_translateButton_clicked();
  void on_rotateButton_clicked();
  void on_scaleButton_clicked();

  void on_sliderXRotate_sliderMoved(int position);
  void on_sliderYRotate_sliderMoved(int position);
  void on_sliderZRotate_sliderMoved(int position);

  void on_sliderScalate_sliderMoved(int position);

  void on_sliderXTranslate_sliderMoved(int position);
  void on_sliderYTranslate_sliderMoved(int position);
  void on_sliderZTranslate_sliderMoved(int position);

 private:
  Ui::MainWindow *ui;
  s21::Controller *_controller;
  Settings *_settings;
  QTimer *_timer;
  QGifImage *_gif;
  void keyPressEvent(QKeyEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
};
#endif  // MAINWINDOW_H
