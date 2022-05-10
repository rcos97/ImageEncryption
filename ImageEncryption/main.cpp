//测试文件
#include <opencv2/opencv.hpp>
#include <iostream>
#include <Dense>
#include <math.h>
#include "RGBShiftEncryp.h"
using namespace cv;
using namespace std;


int main() {
	Mat src = imread("./resource/690x690.jpg");
	int a[4] = {1,0,0,1};
	int b[3] = {432, 234, 543 };
	int c[3] = { 78, 23, 43 };
	RGBShiftEncryp* rgb = new RGBShiftEncryp(src,a,b,c);
	Mat temp(src.rows, src.cols, src.type());
	std::vector<Mat> mv;
	split(temp, mv);
	mv[2] = rgb->RGBShiftEnc(myEnum::Color::RED,sizeof(a)/sizeof(a[0]));
	mv[1] = rgb->RGBShiftEnc(myEnum::Color::GREEN, sizeof(a) / sizeof(a[0]));
	mv[0] = rgb->RGBShiftEnc(myEnum::Color::BLUE, sizeof(a) / sizeof(a[0]));
	Mat dst;
	merge(mv, dst);
	imshow("加密", dst);
	Mat temp1(src.rows, src.cols, src.type());
	std::vector<Mat> mv1;
	split(temp1, mv1);
	mv1[2] = rgb->RGBShiftDeEnc(myEnum::Color::RED, sizeof(a) / sizeof(a[0]));
	mv1[1] = rgb->RGBShiftDeEnc(myEnum::Color::GREEN, sizeof(a) / sizeof(a[0]));
	mv1[0] = rgb->RGBShiftDeEnc(myEnum::Color::BLUE, sizeof(a) / sizeof(a[0]));
	Mat dst1;
	merge(mv1, dst1);
	imshow("解密", dst1);
	waitKey(0);
	destroyAllWindows();
	return 0;
}



