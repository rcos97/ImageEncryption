#pragma once
#include <opencv2/opencv.hpp>
#include "myEnum.h"
#include "myTools.h"
class RGBShiftEncryp
{
public:
	/**
	* @brief RGBƽ�����Ҽ����㷨���캯��
	* @param img ͼƬ����
	* @param ck (control key) ����������Կ������ck=[1,0,1]
	* �����ͼ�����ˮƽ����ֱ��ˮƽ�ı任,���鳤�Ȳ��޶���
	* @param ik (init key) ��Ҫ����������ֵ�����飬�ֱ����RGB�ĳ�ʼƫ����
	* @param dk (delta key) ��Ҫ����������ֵ�����飬�ֱ����RGBÿ�����Һ�Ҫ���ӵ�ƫ����
	*/
	RGBShiftEncryp(cv::Mat img, int ck[], int ik[], int dk[]);
	cv::Mat RGBShiftEnc(myEnum::Color color,int len);
	cv::Mat RGBShiftDeEnc(myEnum::Color color, int len);
private:
	cv::Mat img;
	int width;
	int height;
	int* ck;
	int* ik;
	int* dk;
	~RGBShiftEncryp();
	cv::Mat horizongtalShift(myEnum::Color color);
	cv::Mat verticalShift(myEnum::Color color);
	cv::Mat horizongtalDeShift(myEnum::Color color);
	cv::Mat verticalDeShift(myEnum::Color color);
};

