#pragma once
#include <opencv.hpp>
#include "myEnum.h"
class Dimension
{
public:
	static std::vector<uchar> img2OneColor(cv::Mat &mat,myEnum::Color c);
};