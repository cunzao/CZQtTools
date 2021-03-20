#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#ifndef IMAGEVIEWER_VERSION
#define IMAGEVIEWER_VERSION 1.1
#endif

#include <QWidget>

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = nullptr);
    void setImg(QString strImgPath); // 设置显示的图片，输入参数为图片路径
    void setImg(QImage img); // 设置图片，输入参数位图片数据
    void setImg(QByteArray baImg); // 设置图片，输入参数为图片的字节数组
    void setMark(QRect rectMark); // 设置标记框显示的位置
    void setMarks(QVector<QRect> rectMarks); // 设置多个标记框
    void setNeedCross(bool bNeedCross); // 设置是否需要十字架
    void setNeedBorder(bool bNeedBorder); // 设置是否需要边框
    void setText(QString strToShow); // 设置需要显示的文字

signals:

protected:
    virtual void paintEvent(QPaintEvent *event) override;

private:
    QImage m_img; // 存储需要显示的图片
    QVector<QRect> m_rectMarks; // 存储标记框的位置
    bool m_bNeedCross; // 是否需要十字架
    bool m_bNeedBorder; // 是否需要显示边框
    QPointF m_centerPoint; // 中心点坐标
    int m_iCrossLength = 20; // 十字架的长度
    QString m_strToShow; // 需要进行显示文字

    void UpdateWidget();
};

#endif // IMAGEVIEWER_H
