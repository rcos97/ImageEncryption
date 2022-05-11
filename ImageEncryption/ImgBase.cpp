#include "ImgBase.h"

ImgBase::ImgBase(cv::Mat img)
{
	this->img = img;
	this->originImg = img;
	this->height = img.rows;
	this->width = img.cols;
}

cv::Mat ImgBase::getOriginImg()
{
	return originImg;
}
