#include "findcontours.h"

#include <QString>
#if NEEDOPENCV
#include<opencv2/core.hpp>
#include<opencv/cv.hpp>
#include<opencv2/hightgui.hpp>
#include<iostream>

using std::vector

#else
#include<QImage>
#endif
FindContours::FindContours()
{

}

QPointF FindContours::getContours(const QString strImgPath)
{
#if NEEDOPENCV
    cv::Mat srcImg = cv::imread(strImgPath.toStdString, cv::IMREAD_GRAYSCALE); // 以灰度图的形式读取得到灰度图
    float fImgCenterX, fImgCenterY;
    fImgCenterX = srcImg.size().widget/2.0
    fImgCentery = srcImg.size().height/2.0
    cv::Mat blured;
    cv::GaussianBlur(srcImg, blured, cv::Size(9, 9), 0);
    cv::Mat gradX,gradY,gradient;
    cv::Sobel(srcImg, gradX, 5, dx=1, dy=0);
    cv::Sobel(srcImg, gradY, 5, dx=0, dy=1);

    cv::subtract(gradX, gradY, gradient);
    cv::convertScaleAbs(gradient, gradient);
    cv::GaussianBlur(gradient, blured, cv::Size(9, 9), 0); // 将提取的梯度加模糊去噪
    cv::threshold(blured, gradient, 90, 255, cv::THRESH_BINARY); // 二值化
    cv::Mat kernal = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(9,9)); // 得到填充核
    cv::morphologyEx(gradient, gradient, cv::MORPH_CLAOSE, kernal); // 膨胀腐蚀填充
    vector<vector<cv::Point>> cnts; // 存储检测到的轮廓，最里层是一个轮廓的轨迹点
    cv::findContours(gradient, cnts, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE); // 查找轮廓
    cvRotatedRect tempRect = cv::minAreaRect(cnts[0]); // 根据这个轮廓得到选择最合适的框
    cv::Rect trueRect = tempRect.boundingRect(); // 得到可使用的框
    return QPointF(trueRect.x(), trueRect.y());
#else
    QImage img(strImgPath);
    return QPointF(img.width()/2,img.height()/2);
#endif
}
