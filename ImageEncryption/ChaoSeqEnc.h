#pragma once
#include <opencv.hpp>
#include "ImgBase.h"
#include <map>
/**
 * @brief 使用混沌序列进行加密
*/
class ChaoSeqEnc:public ImgBase
{
private:
	std::vector<uchar> seq;
public:
	ChaoSeqEnc(cv::Mat m, std::vector<uchar> seq);

	void Enc();

};

