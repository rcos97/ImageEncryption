#pragma once
#include <opencv2/opencv.hpp>
class RGBShiftEncryp
{
	enum class Color{RED,GREEN,BLUE};
	cv::Mat img;
	int width;
	int height;
	int* ck;
	int* ik;
	int* dk;
	/**
	 * @brief RGB平移置乱加密算法构造函数
	 * @param img 图片矩阵
	 * @param ck (control key) 控制序列密钥，比如ck=[1,0,1]
	 * 代表以每三个像素为一组，分别进行水平、垂直、水平的变换,数组长度不限定。
	 * @param ik (init key) 需要传入有三个值的数组，分别代表RGB的初始偏移量
	 * @param dk (delta key) 需要传入有三个值的数组，分别代表RGB每次置乱后要增加的偏移量
	*/
	RGBShiftEncryp(cv::Mat img, int ck[], int ik[], int dk[]);
	~RGBShiftEncryp();
	cv::Mat horizongtalShift(Color color);
	cv::Mat verticalShift(Color color);

};

