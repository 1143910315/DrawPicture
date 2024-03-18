#include "similarityfiltering.h"

SimilarityFiltering::SimilarityFiltering(cv::Mat *yuvImage, cv::Mat *argbImage, cv::Mat *originalArgbImage, cv::Vec3b baseColor, int similarity) : yuvImage(yuvImage), argbImage(argbImage), originalArgbImage(originalArgbImage), baseColor(baseColor), similarity(similarity) {
}

SimilarityFiltering::~SimilarityFiltering() {
    running = false;
}

void SimilarityFiltering::stop() {
    running = false;
}

void SimilarityFiltering::run() {
    running = true;
    int x = 0;
    int y = 0;
    while (running&&y < yuvImage->rows) {
        auto &value = yuvImage->at<cv::Vec3b>(y, x);
        int difference = (value[0] * value[0] + value[1] * value[1] + value[2] * value[2]) - (baseColor[0] * baseColor[0] + baseColor[1] * baseColor[1] + baseColor[2] * baseColor[2]);
        if (difference <= similarity&&difference >= -similarity) {
            argbImage->at<cv::Vec4b>(y, x)[0] = originalArgbImage->at<cv::Vec4b>(y, x)[0] / 2;// B
            argbImage->at<cv::Vec4b>(y, x)[1] = originalArgbImage->at<cv::Vec4b>(y, x)[1] / 2;// G
            argbImage->at<cv::Vec4b>(y, x)[2] = (originalArgbImage->at<cv::Vec4b>(y, x)[2] + 255) / 2;// R
            argbImage->at<cv::Vec4b>(y, x)[3] = originalArgbImage->at<cv::Vec4b>(y, x)[3];// A
        } else {
            argbImage->at<cv::Vec4b>(y, x)[0] = originalArgbImage->at<cv::Vec4b>(y, x)[0]; // B
            argbImage->at<cv::Vec4b>(y, x)[1] = originalArgbImage->at<cv::Vec4b>(y, x)[1]; // G
            argbImage->at<cv::Vec4b>(y, x)[2] = originalArgbImage->at<cv::Vec4b>(y, x)[2];// R
            argbImage->at<cv::Vec4b>(y, x)[3] = originalArgbImage->at<cv::Vec4b>(y, x)[3];// A
        }
        x++;
        if (x >= yuvImage->cols) {
            x = 0;
            y++;
        }
    }
    running = false;
}
