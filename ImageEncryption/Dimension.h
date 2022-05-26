#pragma once
#include <opencv.hpp>
#include "myEnum.h"
/**
 * @brief �ı�ͼ��ά�ȵ���
*/
class Dimension
{
public:
	/**
	 * @brief ��ͼƬRGB�е�ĳһͨ���Ķ�ά���󽵳�һά����
	 * @param mat ͼƬ����
	 * @param c ͨ������ɫ
	 * @return ��ͼƬ��cͨ����ά����άΪ��һά����
	*/
	static std::vector<uchar> img2OneColor(cv::Mat &mat,myEnum::Color c);
	/**
	 * @brief ��һά������άΪһ�ŵ�ͨ���ĻҶ�ͼ
	 * @param w �Ҷ�ͼ�Ŀ��
	 * @param h �Ҷ�ͼ�ĸ߶�
	 * @param imgSeq �Ҷ�ͼ��һά����
	 * @return ��ͨ���ĻҶ�ͼ
	*/
	static cv::Mat vec2ImgMatC1(int w, int h ,std::vector<uchar> &imgSeq);
};