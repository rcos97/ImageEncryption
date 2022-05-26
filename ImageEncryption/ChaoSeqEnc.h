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
	/**
	 * @brief 构造函数
	 * @param m 图片矩阵
	*/
	ChaoSeqEnc(cv::Mat m);
	/**
	 * @brief 混沌序列进行加密
	 * @param keySeq 混沌序列
	*/
	void encryption(std::vector<mpf_class> keySeq);

	
	void decrypt(std::vector<mpf_class> keySeq);
};

