## 前言

本项为我写网络通信的时候常常需要用上的工具，因为使用频率高，所以设置为静态方法，直接引入头文件，然后直接调用对应的方法即可。



## 一、CheckSum8 累加和取最后8位

CheckSum8是常用的网络通信校验方法，前面所有位做累加，自然溢出，截取后八位获得一个一个字节的char作为校验位结果，返回的就是最后得到的结果。

```c++
static unsigned char CheckSum_8(char *pBuffer, unsigned int size); // 函数定义
```

## 二、CheckXOR 异或和取最后8位

与累加和类似，这里运算换成异或。

```c++
static unsigned char CheckXor(char *pBuffer, unsigned int size); // 函数定义
```

## 三、FindContours 查找轮廓

使用opencv来查找目标，具体是使用的轮廓标记，最原始的办法，主要是用于一些简单场景的目标检测。

```c++
static QPointF getContours(const QString strImgPath); // 输入图片路径，检测目标中心点，返回中心点坐标
```

