#include "Dimension.h"

std::vector<uchar> Dimension::img2OneColor(cv::Mat& m, myEnum::Color c)
{
	std::vector<cv::Mat> mv;
	cv::split(m, mv);
	int color = myEnum::getColorNum(c);
	cv::Mat mat(mv[2 - color]);
	std::vector<uchar> array;
	if (mat.isContinuous()) {//mat是连续存储的
		array.assign(mat.datastart, mat.dataend);
	}
	else {
		for (int i = 0; i < mat.rows; ++i) {
			//在end前插入一段区间的数据
			array.insert(array.end(), mat.ptr<uchar>(i), mat.ptr<uchar>(i) + mat.cols);
		}
	}
	return array;
}

cv::Mat Dimension::vec2ImgMatC1(int w, int h, std::vector<uchar> &imgSeq)
{
	return cv::Mat(h, w, CV_8UC1, (void*)imgSeq.data());
}
