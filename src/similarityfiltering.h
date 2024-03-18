#ifndef SIMILARITYFILTERING_H
#define SIMILARITYFILTERING_H

#include <QThread>

#include <opencv2/core/core.hpp>

class SimilarityFiltering : public QThread {
    Q_OBJECT
public:
    SimilarityFiltering(cv::Mat *yuvImage = nullptr, cv::Mat *argbImage = nullptr, cv::Mat *originalArgbImage = nullptr, cv::Vec3b baseColor = cv::Vec3b(0, 0, 0), int similarity = 0);
    ~SimilarityFiltering();
    void stop();
protected:
    void run() override;
private:
    cv::Mat *yuvImage;
    cv::Mat *argbImage;
    cv::Mat *originalArgbImage;
    cv::Vec3b baseColor;
    int similarity;
    bool running = false;
};

#endif // SIMILARITYFILTERING_H
