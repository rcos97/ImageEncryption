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
	/**
	 * @brief ���캯��
	 * @param m ͼƬ����
	*/
	ChaoSeqEnc(cv::Mat m);
	/**
	 * @brief �������н��м���
	 * @param keySeq ��������
	*/
	void encryption(std::vector<mpf_class> keySeq);

	
	void decrypt(std::vector<mpf_class> keySeq);
};

