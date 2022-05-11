#pragma once
#include <opencv2/opencv.hpp>
#include "myEnum.h"
#include "myTools.h"
#include "ImgBase.h"
#include <iostream>
/**
 * @brief RGB�����㷨
*/
class RGBShiftEncryp :public ImgBase
{
public:
	/**
	* @brief RGBƽ�����Ҽ����㷨���캯��
	* @param img ͼƬ����
	* @param ck (control key) ����������Կ������ck=[1,0,1]
	* �����ͼ�����ˮƽ����ֱ��ˮƽ�ı任,���鳤�Ȳ��޶������ʹ���˶�̬����
	* @param ik (init key) ��Ҫ����������ֵ�����飬�ֱ����RGB�ĳ�ʼƫ����
	* @param dk (delta key) ��Ҫ����������ֵ�����飬�ֱ����RGBÿ�����Һ�Ҫ���ӵ�ƫ����
	*/
	RGBShiftEncryp(cv::Mat img, std::vector<int> ck, int ik[], int dk[]);
	/**
	 * @brief ��colorͨ����RGB���Ҽ��ܺ���
	 * @param color Ҫ���ܵ�ͨ��
	 * @return ���ܺ��ͼ��
	*/
	cv::Mat RGBShiftEnc(myEnum::Color color);
	/**
	 * @brief ��colorͨ����RGB���ҽ��ܺ���
	 * @param color Ҫ���ܵ�ͨ��
	 * @return ���ܺ��ͼ��
	*/
	cv::Mat RGBShiftDeEnc(myEnum::Color color);
	/**
	 * @brief ͬʱ������ͨ����RGB���Ҽ��ܺ���
	 * @return ���ܺ��ͼ��
	*/
	cv::Mat RGBShiftEnc3C();
	/**
	 * @brief ͬʱ������ͨ����RGB���ҽ��ܺ���
	 * @return ���ܺ��ͼ��
	*/
	cv::Mat RGBShiftDeEnc3C();
private:
	/**
	 * @brief ����������Կ
	*/
	std::vector<int> ck;
	/**
	 * @brief RGB�ĳ�ʼƫ����
	*/
	int* ik;
	/**
	 * @brief RGBÿ�����Һ�Ҫ���ӵ�ƫ����
	*/
	int* dk;
	~RGBShiftEncryp();
	/**
	 * @brief ����ˮƽ����
	 * @param color ˮƽ�ƶ���ͨ�� 
	 * @return ���Һ��ͼ�񣨵�ͨ����
	*/
	cv::Mat horizongtalShift(myEnum::Color color);
	/**
	 * @brief ������ֱ����
	 * @param color ��ֱ�ƶ���ͨ��
	 * @return ���Һ��ͼ�񣨵�ͨ����
	*/
	cv::Mat verticalShift(myEnum::Color color);
	/**
	 * @brief ����ˮƽ����
	 * @param color ˮƽ�ƶ���ͨ�� 
	 * @return ��ԭ���ͼ�񣨵�ͨ����
	*/
	cv::Mat horizongtalDeShift(myEnum::Color color);
	/**
	 * @brief ������ֱ����
	 * @param color ��ֱ�ƶ���ͨ��
	 * @return ��ԭ���ͼ�񣨵�ͨ����
	*/
	cv::Mat verticalDeShift(myEnum::Color color);
};

