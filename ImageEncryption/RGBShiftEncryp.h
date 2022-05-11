#pragma once
#include <opencv2/opencv.hpp>
#include "myEnum.h"
#include "myTools.h"
#include "ImgBase.h"
#include <iostream>
/**
 * @brief RGB置乱算法
*/
class RGBShiftEncryp :public ImgBase
{
public:
	/**
	* @brief RGB平移置乱加密算法构造函数
	* @param img 图片矩阵
	* @param ck (control key) 控制序列密钥，比如ck=[1,0,1]
	* 代表对图像进行水平、垂直、水平的变换,数组长度不限定。因此使用了动态数组
	* @param ik (init key) 需要传入有三个值的数组，分别代表RGB的初始偏移量
	* @param dk (delta key) 需要传入有三个值的数组，分别代表RGB每次置乱后要增加的偏移量
	*/
	RGBShiftEncryp(cv::Mat img, std::vector<int> ck, int ik[], int dk[]);
	/**
	 * @brief 对color通道的RGB置乱加密函数
	 * @param color 要加密的通道
	 * @return 加密后的图像
	*/
	cv::Mat RGBShiftEnc(myEnum::Color color);
	/**
	 * @brief 对color通道的RGB置乱解密函数
	 * @param color 要解密的通道
	 * @return 解密后的图像
	*/
	cv::Mat RGBShiftDeEnc(myEnum::Color color);
	/**
	 * @brief 同时对三个通道的RGB置乱加密函数
	 * @return 加密后的图像
	*/
	cv::Mat RGBShiftEnc3C();
	/**
	 * @brief 同时对三个通道的RGB置乱解密函数
	 * @return 解密后的图像
	*/
	cv::Mat RGBShiftDeEnc3C();
private:
	/**
	 * @brief 控制序列密钥
	*/
	std::vector<int> ck;
	/**
	 * @brief RGB的初始偏移量
	*/
	int* ik;
	/**
	 * @brief RGB每次置乱后要增加的偏移量
	*/
	int* dk;
	~RGBShiftEncryp();
	/**
	 * @brief 按行水平置乱
	 * @param color 水平移动的通道 
	 * @return 置乱后的图像（单通道）
	*/
	cv::Mat horizongtalShift(myEnum::Color color);
	/**
	 * @brief 按列竖直置乱
	 * @param color 竖直移动的通道
	 * @return 置乱后的图像（单通道）
	*/
	cv::Mat verticalShift(myEnum::Color color);
	/**
	 * @brief 按行水平解密
	 * @param color 水平移动的通道 
	 * @return 还原后的图像（单通道）
	*/
	cv::Mat horizongtalDeShift(myEnum::Color color);
	/**
	 * @brief 按列竖直解密
	 * @param color 竖直移动的通道
	 * @return 还原后的图像（单通道）
	*/
	cv::Mat verticalDeShift(myEnum::Color color);
};

