#include "imageviewer.h"
#include <QPainter>

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent)
  , m_bNeedCross(false)
{
}

void ImageViewer::setImg(QString strImgPath)
{
    m_img.load(strImgPath);
}

void ImageViewer::setMark(QRect rectMark)
{
    m_rectMarks.clear();
    m_rectMarks.push_back(rectMark);
}

void ImageViewer::setMarks(QVector<QRect> rectMarks)
{
    m_rectMarks.clear();
    m_rectMarks = rectMarks;
}

void ImageViewer::setNeedCross(bool bNeedCross)
{
    m_bNeedCross = bNeedCross;
}

void ImageViewer::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    m_centerPoint = QPointF(this->width()/2.0, this->height()/2.0); // 计算中心点坐标
    // Start 计算图片放缩比例
    float fScale, fWScale, fHScale;
    fWScale = this->width()/(m_img.width()*1.0);
    fHScale = this->height()/(m_img.height()*1.0);
    fScale = fHScale>fWScale?fWScale:fHScale;
    // End
    QImage scaledImg = m_img.scaled(m_img.width()*fScale, m_img.height()*fScale);
    // Start 计算图片放置的起始位置
    int imgLocateY = (this->height() - scaledImg.height()) / 2;
    int imgLocateX = (this->width() - scaledImg.width()) / 2;
    //End
    QPainter painter(this);
    painter.drawImage(imgLocateX > imgLocateY ? QPoint(imgLocateX, 0) : QPoint(0, imgLocateY),scaledImg);
    painter.setPen(QColor(Qt::white));
    if(!m_rectMarks.isEmpty())
    {
        for(auto mark : m_rectMarks)
        {
            int iLeft = mark.left()*fScale+(imgLocateX>imgLocateY?imgLocateX:0);
            int iTop = mark.top()*fScale+(imgLocateY>imgLocateX?imgLocateY:0);
            QRect tmp(iLeft, iTop, mark.width()*fScale, mark.height()*fScale);
            painter.drawRect(tmp);
        }
    }
    if(m_bNeedCross)
    {
        painter.drawLine(m_centerPoint.x(), m_centerPoint.y()-m_iCrossLength, m_centerPoint.x(), m_centerPoint.y()+m_iCrossLength);
        painter.drawLine(m_centerPoint.x()-m_iCrossLength, m_centerPoint.y(), m_centerPoint.x()+m_iCrossLength, m_centerPoint.y());
    }

}
