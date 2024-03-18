#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <opencv2/core/core.hpp>
#include <QMainWindow>
#include "similarityfiltering.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    cv::Mat convertToARGB32(const cv::Mat& inputImage);

    void on_pushButton_11_clicked();

    void onColorChange(QColor newColor);

    void onSelectColorEnd(QColor newColor);

    void on_horizontalSlider_valueChanged(int value);

    void onCheckAreaDirection(QPoint point);
    void on_pushButton_12_clicked();

private:
    void initConnect();

    void binarization();

    Ui::MainWindow *ui;

    cv::Mat showImage;

    cv::Mat realImage;

    cv::Mat yuvImage;

    SimilarityFiltering *similarityFiltering = nullptr;

    QColor baseColor;
};
#endif // MAINWINDOW_H
