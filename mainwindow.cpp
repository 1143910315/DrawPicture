#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    // 读取图像
    cv::Mat inputImage = cv::imread("input_image.jpg");

    // 如果图像读取失败，输出错误信息并退出
    if (inputImage.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // 创建一个与输入图像相同大小的输出图像
    cv::Mat outputImage;

    // inputImage.convertTo(inputImage, CV_8UC3);

    // 将图像转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

    // 将灰度图像转换为CV_32F类型
    grayImage.convertTo(grayImage, CV_32F);

    // 定义一个3x3的平均滤波器，grayImage.type()==CV_32F
    cv::Mat kernel = cv::Mat::ones(3, 3, grayImage.type()) / 9.0;

    // 应用平均滤波
    cv::filter2D(grayImage, outputImage, -1, kernel);

    // 显示原始图像和滤波后的图像
    cv::imshow("Original Image", inputImage);
    cv::imshow("Gray Image", grayImage / 255.0);
    cv::imshow("Filtered Image", outputImage / 255.0);

    // 等待用户按任意键
    // cv::waitKey(0);
}

void MainWindow::on_pushButton_2_clicked() {
    // 读取图像
    cv::Mat image = cv::imread("input_image.jpg");

    // 检查图像是否成功读取
    if (image.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // 调整对比度和亮度
    double alpha = 2; // 对比度增益
    int beta = 0;     // 亮度增益

    cv::Mat adjustedImage;
    image.convertTo(adjustedImage, -1, alpha, beta);

    // 显示原始图像和调整后的图像
    cv::imshow("Original Image", image);
    cv::imshow("Adjusted Image", adjustedImage);
}

void MainWindow::on_pushButton_3_clicked() {
    // 读取图像
    cv::Mat inputImage = cv::imread("input_image.jpg");

    // 如果图像读取失败，输出错误信息并退出
    if (inputImage.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // 创建一个与输入图像相同大小的输出图像
    cv::Mat outputImage;

    // inputImage.convertTo(inputImage, CV_8UC3);

    // 将图像转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

    // 将灰度图像转换为CV_32F类型
    grayImage.convertTo(grayImage, CV_32F);

    // 创建一个3x3的矩阵
    cv::Mat kernel = (cv::Mat_<float>(3, 3) << -1, -1, -1,
                      -1, 8, -1,
                      -1, -1, -1);

    // 应用平均滤波
    cv::filter2D(grayImage, outputImage, -1, kernel);

    // 显示原始图像和滤波后的图像
    cv::imshow("Original Image", inputImage);
    cv::imshow("Gray Image", grayImage / 255.0);
    cv::imshow("Filtered Image", outputImage / 255.0);
}

void MainWindow::on_pushButton_4_clicked() {
    // 读取图像
    cv::Mat inputImage = cv::imread("input_image.jpg");

    // 如果图像读取失败，输出错误信息并退出
    if (inputImage.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // inputImage.convertTo(inputImage, CV_8UC3);

    // 将图像转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

    // 将灰度图像转换为CV_32F类型
    // grayImage.convertTo(grayImage, CV_32F);

    // 应用平均滤波
    cv::Mat blurredImage;
    cv::blur(grayImage, blurredImage, cv::Size(3, 3));

    // 显示原始图像和滤波后的图像
    cv::imshow("Original Image", inputImage);
    cv::imshow("Gray Image", grayImage);
    cv::imshow("Filtered Image", blurredImage);
}

void MainWindow::on_pushButton_5_clicked() {
    // 读取图像
    cv::Mat inputImage = cv::imread("input_image.jpg");

    // 如果图像读取失败，输出错误信息并退出
    if (inputImage.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // inputImage.convertTo(inputImage, CV_8UC3);

    // 将图像转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

    // 将灰度图像转换为CV_32F类型
    // grayImage.convertTo(grayImage, CV_32F);

    // 应用高斯滤波
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(3, 3), 0);

    // 显示原始图像和滤波后的图像
    cv::imshow("Original Image", inputImage);
    cv::imshow("Gray Image", grayImage);
    cv::imshow("Filtered Image", blurredImage);
}

void MainWindow::on_pushButton_6_clicked() {
    // 读取图像
    cv::Mat inputImage = cv::imread("input_image.jpg");

    // 如果图像读取失败，输出错误信息并退出
    if (inputImage.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // inputImage.convertTo(inputImage, CV_8UC3);

    // 将图像转换为灰度图像
    cv::Mat grayImage;
    cv::cvtColor(inputImage, grayImage, cv::COLOR_BGR2GRAY);

    // 将灰度图像转换为CV_32F类型
    // grayImage.convertTo(grayImage, CV_32F);

    // 应用中值滤波
    cv::Mat blurredImage;
    cv::medianBlur(grayImage, blurredImage, 3);

    // 显示原始图像和滤波后的图像
    cv::imshow("Original Image", inputImage);
    cv::imshow("Gray Image", grayImage);
    cv::imshow("Filtered Image", blurredImage);
}
