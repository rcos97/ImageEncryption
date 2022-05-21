#pragma once
#include <opencv.hpp>
#include "ImgBase.h"
#include <map>
/**
 * @brief ʹ�û������н��м���
*/
class ChaoSeqEnc:public ImgBase
{
private:
	std::vector<uchar> seq;
public:
	ChaoSeqEnc(cv::Mat m, std::vector<uchar> seq);

	void Enc();

};

