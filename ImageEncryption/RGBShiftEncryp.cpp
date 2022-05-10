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


cv::Mat RGBShiftEncryp::horizongtalShift(myEnum::Color c)
{
	int color = myEnum::getColorNum(c);
	cv::Mat resultImg(height, width, (this->img).type());
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			//每行的RGB分量进水平平移（第j行）
			int u = myTools::mod(i + offset, width);
			//opencv使用的是BGR，用户传的是RGB,因此用户传的RGB(012)映射到BGR(210)
			//opencv先传行(y)，再传列(x)
			resultImg.at<cv::Vec3b>(j, u)[2 - color] = (this->img).at<cv::Vec3b>(j, i)[2 - color];
		}
		offset = myTools::mod(offset + deltaOffset, width);
	}
	std::vector<cv::Mat> mv;
	cv::split(resultImg, mv);
	cv::merge(mv, this->img);
	return mv[2 - color];
}

cv::Mat RGBShiftEncryp::verticalShift(myEnum::Color c)
{
	int color = myEnum::getColorNum(c);
	cv::Mat resultImg(height,width,(this->img).type());
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			//每列的RGB分量进垂直平移（第i列）
			int u = myTools::mod(j + offset, height);
			resultImg.at<cv::Vec3b>(u,i)[2 - color] = (this->img).at<cv::Vec3b>(j, i)[2 - color];
		}
		offset = myTools::mod(offset + deltaOffset, height);
	}
	std::vector<cv::Mat> mv;
	cv::split(resultImg, mv);
	cv::merge(mv, this->img);
	return mv[2-color];
}

cv::Mat RGBShiftEncryp::horizongtalDeShift(myEnum::Color c)
{
	int color = myEnum::getColorNum(c);
	cv::Mat resultImg(height, width, (this->img).type());
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int u = myTools::mod(i + offset, width);
			//这里的this->img 已经被打乱了
			resultImg.at<cv::Vec3b>(j, i)[2 - color] = (this->img).at<cv::Vec3b>(j, u)[2 - color];
		}
		offset = myTools::mod(offset + deltaOffset, width);
	}
	std::vector<cv::Mat> mv;
	cv::split(resultImg, mv);
	cv::merge(mv, this->img);
	return mv[2 - color];
}

cv::Mat RGBShiftEncryp::verticalDeShift(myEnum::Color c)
{
	int color = myEnum::getColorNum(c);
	cv::Mat resultImg(height, width, (this->img).type());
	int offset = ik[color];
	int deltaOffset = dk[color];
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int u = myTools::mod(j + offset, height);
			resultImg.at<cv::Vec3b>(j, i)[2 - color] = (this->img).at<cv::Vec3b>(u, i)[2 - color];
		}
		offset = myTools::mod(offset + deltaOffset, height);
	}
	std::vector<cv::Mat> mv;
	cv::split(resultImg, mv);
	cv::merge(mv, this->img);
	return mv[2 - color];
}

cv::Mat RGBShiftEncryp::RGBShiftEnc(myEnum::Color c, int len)
{
	int color = myEnum::getColorNum(c);
	std::vector<cv::Mat> mv;
	cv::split(this->img, mv);
	for (int i = 0; i < len; i++) {
		if (ck[i] == 1) {
			mv[2 - color] = horizongtalShift(c);
		}
		else {
			mv[2 - color] = verticalShift(c);
		}
	}
	cv::merge(mv, this->img);
	return mv[2-color];
}

cv::Mat RGBShiftEncryp::RGBShiftDeEnc(myEnum::Color c, int len)
{
	int color = myEnum::getColorNum(c);
	std::vector<cv::Mat> mv;
	cv::split(this->img, mv);
	for (int i = 0; i < len; i++) {
		std::cout << i << std::endl;
		if (ck[len- 1 - i] == 1) {
			mv[2 - color] = horizongtalDeShift(c);
		}
		else {
			mv[2 - color] = verticalDeShift(c);
		}
	}
	cv::merge(mv, this->img);
	return mv[2 - color];
}




