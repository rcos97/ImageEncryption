#include "Dimension.h"

std::vector<uchar> Dimension::img2OneColor(cv::Mat& m, myEnum::Color c)
{
	std::vector<cv::Mat> mv;
	cv::split(m, mv);
	int color = myEnum::getColorNum(c);
	cv::Mat mat(mv[2 - color]);
	std::vector<uchar> array;
	if (mat.isContinuous()) {//mat�������洢��
		array.assign(mat.datastart, mat.dataend);
	}
	else {
		for (int i = 0; i < mat.rows; ++i) {
			//��endǰ����һ�����������
			array.insert(array.end(), mat.ptr<uchar>(i), mat.ptr<uchar>(i) + mat.cols);
		}
	}
	return array;
}
