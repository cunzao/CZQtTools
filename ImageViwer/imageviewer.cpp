#include "imageviewer.h"
#include <QPainter>
#include <QPaintEvent>

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent)
  , m_bNeedCross(false)
  , m_bNeedBorder(true)
{
}

void ElectricAdjustableMirrorImageWidget::setImg(QString strImgPath)
{
    m_img.load(strImgPath);
//    this->update();
    UpdateWidget();
}

void ElectricAdjustableMirrorImageWidget::setImg(QImage img)
{
    m_img = img;
//    this->update();
    UpdateWidget();
}

void ElectricAdjustableMirrorImageWidget::setImg(QByteArray baImg)
{
    m_img.loadFromData(baImg);
//    this->update();
    UpdateWidget();
}

void ElectricAdjustableMirrorImageWidget::setMark(QRect rectMark)
{
    m_rectMarks.clear();
    m_rectMarks.push_back(rectMark);
}

void ElectricAdjustableMirrorImageWidget::setMarks(QVector<QRect> rectMarks)
{
    m_rectMarks.clear();
    m_rectMarks = rectMarks;
}

void ElectricAdjustableMirrorImageWidget::setNeedCross(bool bNeedCross)
{
    m_bNeedCross = bNeedCross;
}

void ElectricAdjustableMirrorImageWidget::setNeedBorder(bool bNeedBorder)
{
    m_bNeedBorder = bNeedBorder;
}

void ElectricAdjustableMirrorImageWidget::setText(QString strToShow)
{
    m_strToShow = strToShow;
    this->update();
}

void ElectricAdjustableMirrorImageWidget::sltUpdateWidget(double *pDoubleData)
{
    Q_UNUSED(pDoubleData);
}

void ElectricAdjustableMirrorImageWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // 绘制边框，当设置了需要边框而且未设置图片时绘制边框
    if(m_bNeedBorder && m_img.isNull())
    {
        painter.drawRect(0, 0, this->width() - painter.pen().width(), this->height() - painter.pen().width());
    }
    m_centerPoint = QPointF(this->width()/2.0, this->height()/2.0); // 计算中心点坐标

    if(m_img.isNull()) // 如果没有设置照片则不绘制图片，转而显示提示
    {
        painter.drawText(m_centerPoint, "无信号！");
        return;
    }
    // Start 计算图片放缩比例
    float fScale, fWScale, fHScale;
    fWScale = this->width()/(m_img.width()*1.0);
    fHScale = this->height()/(m_img.height()*1.0);
    fScale = fHScale>fWScale?fWScale:fHScale;
    // End

    // Start 放缩图片
    QImage scaledImg = m_img.scaled(m_img.width()*fScale, m_img.height()*fScale);
    // End

    // Start 计算图片放置的起始位置
    int imgLocateY = (this->height() - scaledImg.height()) / 2;
    int imgLocateX = (this->width() - scaledImg.width()) / 2;
    //End

    // Start 绘图
    painter.drawImage(imgLocateX > imgLocateY ? QPoint(imgLocateX, 0) : QPoint(0, imgLocateY),scaledImg);
    // End

    painter.setPen(QColor(Qt::white));
    if(!m_rectMarks.isEmpty()) // 判断是否需要显示标记框
    {
        for(auto mark : m_rectMarks)
        {
            int iLeft = mark.left()*fScale+(imgLocateX>imgLocateY?imgLocateX:0);
            int iTop = mark.top()*fScale+(imgLocateY>imgLocateX?imgLocateY:0);
            QRect tmp(iLeft, iTop, mark.width()*fScale, mark.height()*fScale);
            painter.drawRect(tmp);
        }
    }
    if(m_bNeedCross) // 判断是否需要显示准星
    {

        painter.setPen(QPen(QBrush(Qt::white), 2));
        painter.drawLine(m_centerPoint.x(), m_centerPoint.y()-m_iCrossLength*fScale, m_centerPoint.x(), m_centerPoint.y()+m_iCrossLength*fScale);
        painter.drawLine(m_centerPoint.x()-m_iCrossLength*fScale, m_centerPoint.y(), m_centerPoint.x()+m_iCrossLength*fScale, m_centerPoint.y());
    }
    if(!m_strToShow.isEmpty()) // 判断是否需要显示文字
    {
        painter.setPen(Qt::white);
        int iMargin = 50; // 边距，距离边框的距离
        painter.drawText(imgLocateX > imgLocateY ? QPoint(imgLocateX + iMargin*fScale, iMargin*fScale) : QPoint(iMargin*fScale, imgLocateY + iMargin*fScale), m_strToShow);
    }
}

void ElectricAdjustableMirrorImageWidget::UpdateWidget()
{
    m_rectMarks.clear();
    m_strToShow.clear();
    this->update();
}
