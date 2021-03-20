## 前言

图片查看器，主要用于图像的显示，可以显示图像，并随着此`widget`的大小而等比例改变相关元素大小。

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
    void setImg(QImage img); // 设置图片，输入参数位图片数据
    void setImg(QByteArray baImg); // 设置图片，输入参数为图片的字节数组
    void setMark(QRect rectMark); // 设置标记框显示的位置
    void setMarks(QVector<QRect> rectMarks); // 设置多个标记框
    void setNeedCross(bool bNeedCross); // 设置是否需要十字架
    void setNeedBorder(bool bNeedBorder); // 设置是否需要边框
    void setText(QString strToShow); // 设置需要显示的文字，显示在左上角
```

## 用法

  **方法一：**本工具可以直接引入头文件，新建对象，将对象加入到`Layout`中，调用所需要的接口即可。

  **方法二：**还可以在 `Qt Designer`中拖入一个`QWidget`后，将此`Widget`提升为`ImageViewer`，即可在`ui`内使用此工具。

## 更新日志

2021年3月20日 10点06分

1. 重载了`setImg`方法，`setImg`可以传入`QImage`类型的图片数据了
2. 添加无图片显示时的提示文字
3. 添加设置提示文字功能，默认显示在左上角，在某些显示场景实用
4. 添加设置`widget`的边框功能，例如无图片显示时，无边框看起来比较奇怪，故加此功能
5. 增加图片是否为空的判断，避免图片为空继续使用图片导致的报错



## 最后

欢迎提`Issue`跟`cunzao`一起交流