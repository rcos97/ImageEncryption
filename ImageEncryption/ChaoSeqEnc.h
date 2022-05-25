#pragma once
#include <opencv.hpp>
#include "ImgBase.h"
#include <map>
#include "Dimension.h"
#include <gmpxx.h>
/**
 * @brief 使用混沌序列进行加密
*/
class ChaoSeqEnc:public ImgBase
{
private:

public:
	ChaoSeqEnc(cv::Mat m);

	void Enc(std::vector<mpf_class> keySeq);

};

