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
	std::vector<int> a = { 1};
	int b[3] = {100, 100, 100 };
	int c[3] = { -1, -1, -1 };
	RGBShiftEncryp* rgb = new RGBShiftEncryp(src,a,b,c);
	imshow("加密1", rgb->RGBShiftEnc3C());
	imshow("解密1", rgb->RGBShiftDeEnc3C());
	waitKey(0);
	destroyAllWindows();
	return 0;
}



