#pragma once
#include <opencv.hpp>
#include "ImgBase.h"
#include <map>
#include "Dimension.h"
#include <gmpxx.h>
/**
 * @brief ʹ�û������н��м���
*/
class ChaoSeqEnc:public ImgBase
{
private:

public:
	ChaoSeqEnc(cv::Mat m);

	void Enc(std::vector<mpf_class> keySeq);

};

