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
	cv::Mat resultImg(height, width, (this->img).type());
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			//ÿ�е�RGB������ˮƽƽ�ƣ���j�У�
			int u = (i + offset)%width;
			//opencvʹ�õ���BGR���û�������RGB,����û�����RGB(012)ӳ�䵽BGR(210)
			//opencv�ȴ���(y)���ٴ���(x)
			resultImg.at<cv::Vec3b>(j, u)[2 - color] = (this->img).at<cv::Vec3b>(j, i)[2 - color];
		}
		offset = (offset + deltaOffset) % width;
	}
	std::vector<cv::Mat> mv;
	cv::split(resultImg, mv);
	return mv[2 - color];
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
	cv::Mat resultImg(height,width,(this->img).type());
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			//ÿ�е�RGB��������ֱƽ�ƣ���i�У�
			int u = (j + offset) % height;
			resultImg.at<cv::Vec3b>(u,i)[2 - color] = (this->img).at<cv::Vec3b>(j, i)[2 - color];
		}
		offset = (offset + deltaOffset) % height;
	}
	std::vector<cv::Mat> mv;
	cv::split(resultImg, mv);
	return mv[2-color];
}

cv::Mat RGBShiftEncryp::RGBShiftEnc(Color c)
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
	std::vector<cv::Mat> mv;
	cv::split(this->img, mv);
	for (int i = 0; i < 14; i++) {
		std::cout << i << std:: endl;
		if (ck[i] == 1) {
			mv[2 - color] = horizongtalShift(c);
		}
		else {
			mv[2 - color] = verticalShift(c);
		}
	}
	return mv[2-color];
}




