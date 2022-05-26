#pragma once
#include <opencv.hpp>
#include "myEnum.h"
/**
 * @brief 改变图像维度的类
*/
class Dimension
{
public:
	/**
	 * @brief 将图片RGB中的某一通道的二维矩阵降成一维向量
	 * @param mat 图片矩阵
	 * @param c 通道的颜色
	 * @return 将图片中c通道二维矩阵降维为的一维向量
	*/
	static std::vector<uchar> img2OneColor(cv::Mat &mat,myEnum::Color c);
	/**
	 * @brief 将一维向量升维为一张单通道的灰度图
	 * @param w 灰度图的宽度
	 * @param h 灰度图的高度
	 * @param imgSeq 灰度图的一维向量
	 * @return 单通道的灰度图
	*/
	static cv::Mat vec2ImgMatC1(int w, int h ,std::vector<uchar> &imgSeq);
};