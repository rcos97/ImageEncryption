#pragma once
#include <opencv2/opencv.hpp>
class RGBShiftEncryp
{
public:
	enum class Color { RED, GREEN, BLUE };
	RGBShiftEncryp(cv::Mat img, int ck[], int ik[], int dk[]);
	cv::Mat RGBShiftEnc(Color color);
private:
	cv::Mat img;
	int width;
	int height;
	int* ck;
	int* ik;
	int* dk;
	/**
	 * @brief RGBƽ�����Ҽ����㷨���캯��
	 * @param img ͼƬ����
	 * @param ck (control key) ����������Կ������ck=[1,0,1]
	 * �����ͼ�����ˮƽ����ֱ��ˮƽ�ı任,���鳤�Ȳ��޶���
	 * @param ik (init key) ��Ҫ����������ֵ�����飬�ֱ����RGB�ĳ�ʼƫ����
	 * @param dk (delta key) ��Ҫ����������ֵ�����飬�ֱ����RGBÿ�����Һ�Ҫ���ӵ�ƫ����
	*/
	~RGBShiftEncryp();
	cv::Mat horizongtalShift(Color color);
	cv::Mat verticalShift(Color color);

};

