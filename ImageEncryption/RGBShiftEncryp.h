#pragma once
#include <opencv2/opencv.hpp>
#include "myEnum.h"
#include "myTools.h"
#include "ImgBase.h"
#include <iostream>
class RGBShiftEncryp :public ImgBase
{
public:
	/**
	* @brief RGB平移置乱加密算法构造函数
	* @param img 图片矩阵
	* @param ck (control key) 控制序列密钥，比如ck=[1,0,1]
	* 代表对图像进行水平、垂直、水平的变换,数组长度不限定。
	* @param ik (init key) 需要传入有三个值的数组，分别代表RGB的初始偏移量
	* @param dk (delta key) 需要传入有三个值的数组，分别代表RGB每次置乱后要增加的偏移量
	*/
	RGBShiftEncryp(cv::Mat img, std::vector<int> ck, int ik[], int dk[]);
	cv::Mat RGBShiftEnc(myEnum::Color color);
	cv::Mat RGBShiftDeEnc(myEnum::Color color);
	cv::Mat RGBShiftEnc3C();
	cv::Mat RGBShiftDeEnc3C();
private:
	std::vector<int> ck;
	int* ik;
	int* dk;
	~RGBShiftEncryp();
	cv::Mat horizongtalShift(myEnum::Color color);
	cv::Mat verticalShift(myEnum::Color color);
	cv::Mat horizongtalDeShift(myEnum::Color color);
	cv::Mat verticalDeShift(myEnum::Color color);
};

