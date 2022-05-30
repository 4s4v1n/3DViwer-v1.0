// Copyright 2022 Savin Anton and Dyagteryov Andrey

#include "mainwindow.h"

#include <QDir>

#include "ui/ui_mainwindow.h"

static const int framesInFiveSec = 50;
static const double sliderScalation = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->centralwidget->setFocus();
}

MainWindow::MainWindow(QWidget *parent, s21::Controller *controller)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      _settings(nullptr),
      _timer(new QTimer(this)),
      _gif(nullptr) {
  ui->setupUi(this);

  _controller = controller;
  ui->glscene->SetController(controller);

  connect(ui->jpegButton, SIGNAL(clicked()), this, SLOT(savePicture()));
  connect(ui->bmpButton, SIGNAL(clicked()), this, SLOT(savePicture()));
  connect(_timer, SIGNAL(timeout()), this, SLOT(takeFrame()));
}

MainWindow::~MainWindow() {
  delete ui;
  delete _timer;
}

void MainWindow::on_openFile_clicked() {
  QDir::currentPath();
  QString path = QDir::currentPath() + "/../objects/";
  QString fPath = QFileDialog::getOpenFileName(this, tr("Open File"), path,
                                               tr("objects (*.obj)"));
  QFileInfo fileinfo(fPath);
  QString fileName = fileinfo.fileName();
  if (fileName != "") {
    if (_controller->SetCurFile(fPath)) {
      ui->curFile->setText(fileName);
      ui->numberOfVertices->setText(
          "Vertices: " + QString::number(_controller->GetFacesSize()));
      ui->numberOfEdges->setText(
          "Edges: " + QString::number(_controller->GetNumberOfEdges()));
      ui->sliderScalate->setValue(100);
      ui->sliderXRotate->setValue(0);
      ui->sliderYRotate->setValue(0);
      ui->sliderZRotate->setValue(0);
      ui->sliderXTranslate->setValue(0);
      ui->sliderYTranslate->setValue(0);
      ui->sliderZTranslate->setValue(0);
    } else {
    }
  }
}

void MainWindow::on_settings_clicked() {
  _settings = new Settings;
  _settings->SetController(_controller);
  _settings->SetSettingsData(ui->glscene->GetSettingsDataPtr());
  _settings->SetDataFromConfig();
  _settings->show();
}

void MainWindow::on_gifButton_clicked() {
  if (ui->curFile->text() != "File name" && !ui->curFile->text().isEmpty() &&
      ui->gifButton->text() == "Record gif") {
    ui->gifButton->setText("Gif is recording");
    _gif = new QGifImage;
    _timer->start(100);
  }
}

void MainWindow::takeFrame() {
  if (_gif->frameCount() < framesInFiveSec) {
    QImage frame = ui->glscene->grabFramebuffer();
    _gif->addFrame(frame);
  } else {
    _timer->stop();
    ui->gifButton->setText("Record gif");
    QString directoryName =
        QFileDialog::getExistingDirectory(
            this, "Open directory to save file", "/",
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
        "/";
    QString fileName = ui->curFile->text();
    QString currentTime =
        QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss");
    fileName.resize(fileName.size() - 4);
    _gif->save(directoryName + fileName + "_" + currentTime + ".gif");
  }
}

void MainWindow::savePicture() {
  QString fileName = ui->curFile->text();
  if (fileName != "File name" && !fileName.isEmpty()) {
    QString currentTime =
        QDateTime::currentDateTime().toString("yyyy_MM_dd_HH_mm_ss");
    QPushButton *button = static_cast<QPushButton *>(sender());
    QImage img = ui->glscene->grabFramebuffer();
    QString directoryName =
        QFileDialog::getExistingDirectory(
            this, "Open directory to save file", "/",
            QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks) +
        "/";
    fileName.resize(fileName.size() - 4);
    if (button->text() == "Save to jpeg") {
      img.save(directoryName + fileName + "_" + currentTime + ".jpeg", "JPEG");
    } else {
      img.save(directoryName + fileName + "_" + currentTime + ".bmp", "BMP");
      delete _gif;
      _gif = nullptr;
    }
  }
}
void MainWindow::on_translateButton_clicked() {
  _controller->TranslateX(ui->xTranslate->text().toDouble());
  _controller->TranslateY(ui->yTranslate->text().toDouble());
  _controller->TranslateZ(ui->zTranslate->text().toDouble());
  ui->glscene->update();
}

void MainWindow::on_rotateButton_clicked() {
  _controller->RotateX(ui->xRotate->text().toDouble());
  _controller->RotateY(ui->yRotate->text().toDouble());
  _controller->RotateZ(ui->zRotate->text().toDouble());
  ui->glscene->update();
}

void MainWindow::on_scaleButton_clicked() {
  _controller->Scalate(ui->scalateSpinBox->text().toDouble());
  ui->glscene->update();
}

void MainWindow::on_sliderXRotate_sliderMoved(int position) {
  double degree = static_cast<double>(position - ui->sliderXRotate->value());
  _controller->RotateX(degree);
  ui->glscene->update();
}

void MainWindow::on_sliderYRotate_sliderMoved(int position) {
  double degree = static_cast<double>(position - ui->sliderYRotate->value());
  _controller->RotateY(degree);
  ui->glscene->update();
}

void MainWindow::on_sliderZRotate_sliderMoved(int position) {
  double degree = static_cast<double>(position - ui->sliderZRotate->value());
  _controller->RotateZ(degree);
  ui->glscene->update();
}

void MainWindow::on_sliderScalate_sliderMoved(int position) {
  double scalation = static_cast<double>(position - ui->sliderScalate->value());
  scalation = 1. + scalation / 100.;
  _controller->Scalate(scalation);
  ui->glscene->update();
}

void MainWindow::on_sliderXTranslate_sliderMoved(int position) {
  double translation =
      static_cast<double>(position - ui->sliderXTranslate->value());
  double scaleCoefficient =
      -(_controller->GetXMax() / _controller->GetXMin()) / sliderScalation;
  translation *= scaleCoefficient;
  _controller->TranslateX(translation);
  ui->glscene->update();
}

void MainWindow::on_sliderYTranslate_sliderMoved(int position) {
  double translation =
      static_cast<double>(position - ui->sliderYTranslate->value());
  double scaleCoefficient =
      -(_controller->GetYMax() / _controller->GetYMin()) / sliderScalation;
  translation *= scaleCoefficient;
  _controller->TranslateY(translation);
  ui->glscene->update();
}

void MainWindow::on_sliderZTranslate_sliderMoved(int position) {
  double translation =
      static_cast<double>(position - ui->sliderZTranslate->value());
  double scaleCoefficient =
      -(_controller->GetZMax() / _controller->GetZMin()) / sliderScalation;
  translation *= scaleCoefficient;
  _controller->TranslateZ(translation);
  ui->glscene->update();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_Escape) {
    this->close();
  } else if (event->key() == Qt::Key_Space) {
    this->on_settings_clicked();
  } else if (event->key() == Qt::Key_J) {
    ui->jpegButton->click();
  } else if (event->key() == Qt::Key_B) {
    ui->bmpButton->click();
  } else if (event->key() == Qt::Key_G) {
    this->on_gifButton_clicked();
  } else if (event->key() == Qt::Key_O) {
    this->on_openFile_clicked();
  }
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
  ui->xTranslate->clearFocus();
  ui->yTranslate->clearFocus();
  ui->zTranslate->clearFocus();
  ui->xRotate->clearFocus();
  ui->yRotate->clearFocus();
  ui->zRotate->clearFocus();
  ui->scalateSpinBox->clearFocus();
  event->ignore();
}
