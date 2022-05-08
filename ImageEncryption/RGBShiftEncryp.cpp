#include "RGBShiftEncryp.h"

RGBShiftEncryp::RGBShiftEncryp(cv::Mat img, int ck[], int ik[], int dk[])
{
	this->img = img;
	this->ck = ck;
	this->ik = ik;
	this->dk = dk;
	this->width = img.cols;
	this->height = img.rows;
}

RGBShiftEncryp::~RGBShiftEncryp()
{
	delete[] this->ck;
	delete[] this->ik;
	delete[] this->dk;
}


cv::Mat RGBShiftEncryp::horizongtalShift(Color c)
{
	int color = -1;
	switch (c)
	{
	case RGBShiftEncryp::Color::RED:
		color = 0;
		break;
	case RGBShiftEncryp::Color::GREEN:
		color = 1;
		break;
	case RGBShiftEncryp::Color::BLUE:
		color = 2;
		break;
	default:
		break;
	}
	cv::Mat resultImg;
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int u = (i + offset)%256;
			//opencvʹ�õ���BGR���û�������RGB,����û�����RGB(012)ӳ�䵽BGR(210)
			//opencv�ȴ���(y)���ٴ���(x)
			resultImg.at<cv::Vec3b>(j, u)[2 - color] = (this->img).at<cv::Vec3b>(j, i)[2 - color];
		}
		offset = (offset + deltaOffset) % 256;
	}
	return resultImg;
}

cv::Mat RGBShiftEncryp::verticalShift(Color c)
{
	int color = -1;
	switch (c)
	{
	case RGBShiftEncryp::Color::RED:
		color = 0;
		break;
	case RGBShiftEncryp::Color::GREEN:
		color = 1;
		break;
	case RGBShiftEncryp::Color::BLUE:
		color = 2;
		break;
	default:
		break;
	}
	cv::Mat resultImg;
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int u = (i + offset) % 256;
			//opencvʹ�õ���BGR���û�������RGB,����û�����RGB(012)ӳ�䵽BGR(210)
			//opencv�ȴ���(y)���ٴ���(x)
			resultImg.at<cv::Vec3b>(j, u)[2 - color] = (this->img).at<cv::Vec3b>(j, i)[2 - color];
		}
		offset = (offset + deltaOffset) % 256;
	}
	return resultImg;
}




