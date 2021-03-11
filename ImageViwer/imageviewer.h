#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = nullptr);
    void setImg(QString strImgPath); // 设置显示的图片，输入参数为图片路径
    void setMark(QRect rectMark); // 设置标记框显示的位置
    void setMarks(QVector<QRect> rectMarks); // 设置多个标记框
    void setNeedCross(bool bNeedCross); // 设置是否需要十字架

signals:

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    QImage m_img; // 存储需要显示的图片
    QVector<QRect> m_rectMarks; // 存储标记框的位置
    bool m_bNeedCross; // 是否需要十字架
    QPointF m_centerPoint; // 中心点坐标
    int m_iCrossLength = 10; // 十字架的长度
};

#endif // IMAGEVIEWER_H
