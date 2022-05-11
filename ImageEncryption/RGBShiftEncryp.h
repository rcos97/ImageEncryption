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
	* @brief RGBƽ�����Ҽ����㷨���캯��
	* @param img ͼƬ����
	* @param ck (control key) ����������Կ������ck=[1,0,1]
	* �����ͼ�����ˮƽ����ֱ��ˮƽ�ı任,���鳤�Ȳ��޶���
	* @param ik (init key) ��Ҫ����������ֵ�����飬�ֱ����RGB�ĳ�ʼƫ����
	* @param dk (delta key) ��Ҫ����������ֵ�����飬�ֱ����RGBÿ�����Һ�Ҫ���ӵ�ƫ����
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

