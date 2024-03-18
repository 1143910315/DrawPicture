#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include <QtMath>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // 设置纯色背景
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::green);  // 以绿色为例
    ui->label_2->setAutoFillBackground(true);
    ui->label_2->setPalette(palette);
    // 设置纯色背景
    QPalette palette1;
    palette1.setColor(QPalette::Window, Qt::black);  // 以黑色为例
    ui->frame->setAutoFillBackground(true);
    ui->frame->setPalette(palette1);
    // 设置纯色背景
    QPalette palette2;
    palette2.setColor(QPalette::Window, Qt::gray);  // 以灰色为例
    ui->frame_2->setAutoFillBackground(true);
    ui->frame_2->setPalette(palette2);
    initConnect();
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

void MainWindow::on_pushButton_7_clicked() {
    // 读取图像
    cv::Mat image = cv::imread("input_image.jpg", cv::IMREAD_GRAYSCALE);

    // 检查图像是否成功读取
    if (image.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // 应用Canny边缘检测
    cv::Mat edges;
    cv::Canny(image, edges, 50, 150);

    // 显示原始图像和边缘检测结果
    cv::imshow("Original Image", image);
    cv::imshow("Canny Edges", edges);
}

void MainWindow::on_pushButton_8_clicked() {
    // 读取图像
    cv::Mat image = cv::imread("input_image.jpg");

    // 检查图像是否成功读取
    if (image.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }

    // 将图像从BGR格式转换为YUV格式
    cv::Mat yuvImage;
    cv::cvtColor(image, yuvImage, cv::COLOR_BGR2YUV);

    // 显示原始图像和转换后的图像
    cv::imshow("Original Image", image);
    cv::imshow("YUV Image", yuvImage);
}

void MainWindow::on_pushButton_9_clicked() {
    // 读取图像
    cv::Mat image = cv::imread("input_image.jpg");

    // 检查图像是否成功读取
    if (image.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }
    qDebug() << image.type() << CV_8UC3;
    // 使用内存共享创建QImage（零拷贝方式）
    QImage qtImage(static_cast<const uchar *>(image.data), image.cols, image.rows, image.step, QImage::Format_RGB888);
    qDebug() << (qtImage.constBits() == image.data);

    // 修改cv::Mat内的值
    image.at<cv::Vec3b>(0, 0)[0] = 127;
    image.at<cv::Vec3b>(0, 0)[1] = 127;
    image.at<cv::Vec3b>(0, 0)[2] = 127;
    auto temp = qtImage.rgbSwapped();
    qDebug() << temp.format() << QImage::Format_RGB888 << QImage::Format_RGB32;
    // 显示QImage
    ui->label->setPixmap(QPixmap::fromImage(temp));
}

void MainWindow::on_pushButton_10_clicked() {
    // 读取图像
    cv::Mat image = cv::imread("input_image.jpg");

    // 检查图像是否成功读取
    if (image.empty()) {
        qDebug() << "Error: Unable to read the image.";
    }
    qDebug() << image.type() << CV_8UC3;
    // 将图像从BGR格式转换为YUV格式
    cv::cvtColor(image, yuvImage, cv::COLOR_BGR2YUV);
    showImage = convertToARGB32(image);
    showImage.copyTo(realImage);
    qDebug() << showImage.type() << CV_8UC4;
    // 使用内存共享创建QImage（零拷贝方式）
    QImage qtImage(static_cast<const uchar *>(showImage.data), showImage.cols, showImage.rows, showImage.step, QImage::Format_RGB32);
    qDebug() << (qtImage.constBits() == showImage.data);

    // auto temp = qtImage.rgbSwapped();
    qDebug() << qtImage.format() << QImage::Format_RGB32;
    // 显示QImage
    ui->label->setPixmap(QPixmap::fromImage(qtImage));
}

cv::Mat MainWindow::convertToARGB32(const cv::Mat &inputImage) {
    // 创建输出图像
    cv::Mat outputImage(inputImage.rows, inputImage.cols, CV_8UC4);

    // 转换颜色空间：BGR到BGRA
    cv::cvtColor(inputImage, outputImage, cv::COLOR_BGR2BGRA);

    // OpenCV中BGRA通道顺序是BGR0，需要进行调整
    cv::Mat finalImage;
    cv::cvtColor(outputImage, finalImage, cv::COLOR_BGRA2RGBA);

    return finalImage;
}

void MainWindow::on_pushButton_11_clicked() {
    // 修改cv::Mat内的值
    // showImage.at<cv::Vec4b>(0, 0)[0] = 127;
    // showImage.at<cv::Vec4b>(0, 0)[1] = 127;
    // showImage.at<cv::Vec4b>(0, 0)[2] = 127;
    // qDebug() << (ui->label->pixmap().toImage().constBits() == showImage.data);
    int row = QRandomGenerator::global()->bounded(0, showImage.rows);
    int col = QRandomGenerator::global()->bounded(0, showImage.cols);
    // 修改cv::Mat内的值
    showImage.at<cv::Vec4b>(row, col)[0] = 0;// B
    showImage.at<cv::Vec4b>(row, col)[1] = 0;// G
    showImage.at<cv::Vec4b>(row, col)[2] = 255;// R
    showImage.at<cv::Vec4b>(row, col)[3] = 255;// A
    ui->label->update(QRect(col, row, 1, 1));

    // showImage.at<cv::Vec4b>(200, 100)[0] = 0;// B
    // showImage.at<cv::Vec4b>(200, 100)[1] = 255;// G
    // showImage.at<cv::Vec4b>(200, 100)[2] = 0;// R
    // showImage.at<cv::Vec4b>(200, 100)[3] = 255;// A
    // ui->label->update();
}

void MainWindow::onColorChange(QColor newColor) {
    // 设置纯色背景
    QPalette palette;
    palette.setColor(QPalette::Window, newColor);
    ui->label_2->setAutoFillBackground(true);
    ui->label_2->setPalette(palette);
}

void MainWindow::onSelectColorEnd(QColor newColor) {
    onColorChange(newColor);
    baseColor = newColor;
    binarization();
}

void MainWindow::initConnect() {
    connect(ui->frame_2, &PickColorsFrame::colorChangeEvent, this, &MainWindow::onColorChange);
    connect(ui->frame_2, &PickColorsFrame::selectColorEndEvent, this, &MainWindow::onSelectColorEnd);
    connect(ui->label, &PositionLabel::checkAreaDirectionEvent, this, &MainWindow::onCheckAreaDirection);
}

void MainWindow::binarization() {
    // 创建一个RGB颜色
    cv::Vec3b rgbColor(baseColor.red(), baseColor.green(), baseColor.blue());

    // 将RGB颜色转换为YUV颜色
    cv::Mat rgbMat(1, 1, CV_8UC3, rgbColor);
    cv::Mat yuvMat;

    cv::cvtColor(rgbMat, yuvMat, cv::COLOR_RGB2YUV);

    // 提取YUV分量
    // int y = yuvMat.at<cv::Vec3b>(0, 0)[0];
    // int u = yuvMat.at<cv::Vec3b>(0, 0)[1];
    // int v = yuvMat.at<cv::Vec3b>(0, 0)[2];
    if (similarityFiltering) {
        similarityFiltering->stop();
        similarityFiltering->wait();
        similarityFiltering->deleteLater();
    }
    similarityFiltering = new SimilarityFiltering(&yuvImage, &showImage, &realImage, yuvMat.at<cv::Vec3b>(0, 0), ui->horizontalSlider->value());
    similarityFiltering->start();
}

void MainWindow::on_horizontalSlider_valueChanged(int value) {
    binarization();
}

void MainWindow::onCheckAreaDirection(QPoint point) {
    auto startX = point.x();
    auto startY = point.y();
    auto topX = point.x();
    auto topY = point.y();
    auto bottomX = point.x();
    auto bottomY = point.y();
    auto leftX = point.x();
    auto leftY = point.y();
    auto rightX = point.x();
    auto rightY = point.y();
    auto baseColor = yuvImage.at<cv::Vec3b>(startY, startX);
    auto tempColor = cv::Vec3b();
    auto bgraColor = cv::Vec4b();
    auto count = 0;
    auto difference = 0;
    auto leftRun = false;
    auto topRun = false;
    auto rightRun = false;
    auto bottomRun = false;
    auto findCircular = false;
    auto r = 3;
    if (topY > 0) {
        topY--;
        count++;
        tempColor = yuvImage.at<cv::Vec3b>(topY, topX);
        difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
        bgraColor = realImage.at<cv::Vec4b>(topY, topX);
        qDebug() << "Top" << difference << topX << topY << bgraColor[0] << bgraColor[1] << bgraColor[2];
        topRun = true;
    }
    if (leftX > 0) {
        leftX--;
        count++;
        tempColor = yuvImage.at<cv::Vec3b>(leftY, leftX);
        difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
        leftRun = true;
    }
    if (bottomY < yuvImage.rows - 1) {
        bottomY++;
        count++;
        tempColor = yuvImage.at<cv::Vec3b>(bottomY, bottomX);
        difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
        bottomRun = true;
    }
    if (rightX < yuvImage.cols - 1) {
        rightX++;
        count++;
        tempColor = yuvImage.at<cv::Vec3b>(rightY, rightX);
        difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
        rightRun = true;
    }
    if (count > 0) {
        difference = difference * 2 / count + 2000;
    }
    while (!findCircular) {
        for (int x = -r; x <= r; ++x) {
            auto y = 0;
            if (x == -r||x == r) {
            } else if (x == 0) {
                y = r;
            } else {
                y = qSqrt(r * r - x * x);
            }
            auto topColor = yuvImage.at<cv::Vec3b>(startY - y, startX + x);
            auto topDifference = (baseColor[0] - topColor[0]) * (baseColor[0] - topColor[0]) + (baseColor[1] - topColor[1]) * (baseColor[1] - topColor[1]) + (baseColor[2] - topColor[2]) * (baseColor[2] - topColor[2]);
            qDebug() << (topDifference < difference) << startX + x << startY - y << "↑" << topDifference;
            auto bottomColor = yuvImage.at<cv::Vec3b>(startY + y, startX + x);
            auto bottomDifference = (baseColor[0] - bottomColor[0]) * (baseColor[0] - bottomColor[0]) + (baseColor[1] - bottomColor[1]) * (baseColor[1] - bottomColor[1]) + (baseColor[2] - bottomColor[2]) * (baseColor[2] - bottomColor[2]);
            qDebug() << (bottomDifference < difference) << startX + x << startY + y << "↓" << bottomDifference;
            if (topDifference < difference) {
            }
        }
        qDebug() << "↑" << r;
        r += 2;
    }
    // while ((leftRun||rightRun)&&(topRun||bottomRun)) {
    // if (topRun) {
    // if (topY > 0) {
    // topY--;
    // count++;
    // tempColor = yuvImage.at<cv::Vec3b>(topY, topX);
    // difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
    // } else {
    // topRun = false;
    // }
    // }
    // if (leftRun) {
    // if (leftX > 0) {
    // leftX--;
    // count++;
    // tempColor = yuvImage.at<cv::Vec3b>(leftY, leftX);
    // difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
    // } else {
    // leftRun = false;
    // }
    // }
    // if (bottomRun) {
    // if (bottomY < yuvImage.rows - 1) {
    // bottomY++;
    // count++;
    // tempColor = yuvImage.at<cv::Vec3b>(bottomY, bottomX);
    // difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
    // } else {
    // bottomRun = false;
    // }
    // }
    // if (rightRun) {
    // if (rightX < yuvImage.cols - 1) {
    // rightX++;
    // count++;
    // tempColor = yuvImage.at<cv::Vec3b>(rightY, rightX);
    // difference += (baseColor[0] - tempColor[0]) * (baseColor[0] - tempColor[0]) + (baseColor[1] - tempColor[1]) * (baseColor[1] - tempColor[1]) + (baseColor[2] - tempColor[2]) * (baseColor[2] - tempColor[2]);
    // } else {
    // rightRun = false;
    // }
    // }
    // }
}

void MainWindow::on_pushButton_12_clicked() {
    onCheckAreaDirection({ 481, 481 });
}
