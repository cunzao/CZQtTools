#ifndef FINDCONTOURS_H
#define FINDCONTOURS_H

#ifndef NEEDOPENCV
#define NEEDOPENCV 0
#endif

#include <QPointF>
#include <QString>

class FindContours
{
public:
    FindContours();
    static QPointF getContours(const QString strImgPath); // 输入图片路径，检测目标中心点，返回中心点坐标
};

#endif // FINDCONTOURS_H
