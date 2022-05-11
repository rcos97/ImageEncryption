#pragma once

#include <opencv2/opencv.hpp>

class ImgBase
{
private:
	cv::Mat originImg;
public:
	cv::Mat img;
	int width;
	int height;
	ImgBase(cv::Mat img);
	cv::Mat getOriginImg();
};

