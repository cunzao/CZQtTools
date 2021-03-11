## 前言

图片查看器，主要用于图像的显示，可以显示图像，并随着此widget的大小而等比例改变相关元素大小。

**现有功能：**

1. 查看图片
2. 显示十字准星
3. 显示标记框

**待加功能：**

1. 随着滚轮放大缩小
2. ...

## 接口

```c++
	explicit ImageViewer(QWidget *parent = nullptr); // 构造函数
    void setImg(QString strImgPath); // 设置显示的图片，输入参数为图片路径
    void setMark(QRect rectMark); // 设置标记框显示的位置
    void setMarks(QVector<QRect> rectMarks); // 设置多个标记框
    void setNeedCross(bool bNeedCross); // 设置是否需要十字架
```



## 最后

欢迎提issue跟cunzao一起交流