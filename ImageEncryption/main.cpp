//²âÊÔÎÄ¼þ

// Arnold.cpp : Ã¨Á³±ä»»

#include <opencv2/opencv.hpp>
#include <iostream>
#include <Dense>
#include <math.h>
#include "RGBShiftEncryp.h"
using namespace cv;
using namespace std;


int main() {
	Mat src = imread("./resource/690x690.jpg");
	int a[14] = { 1, 0, 1, 0,0,1,1,1,0 ,0,0,1,1,0};
	int b[3] = { 234, 432, 754 };
	int c[3] = { 40, 53, 67 };
	RGBShiftEncryp* rgb = new RGBShiftEncryp(src,a,b,c);
	Mat temp(src.rows, src.cols, src.type());
	std::vector<Mat> mv;
	split(temp, mv);
	mv[2] = rgb->RGBShiftEnc(RGBShiftEncryp::Color::RED);
	mv[1] = rgb->RGBShiftEnc(RGBShiftEncryp::Color::GREEN);
	mv[0] = rgb->RGBShiftEnc(RGBShiftEncryp::Color::BLUE);
	Mat dst;
	merge(mv, dst);
	imshow("test", dst);
	waitKey(0);
	destroyAllWindows();
	return 0;
}



