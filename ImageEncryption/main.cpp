//�����ļ�

// Arnold.cpp : è���任

#include <opencv2/opencv.hpp>
#include <iostream>
#include <Dense>
#include <math.h>
using namespace cv;
using namespace std;


int main() {
	Mat src = imread("./resource/690x690.jpg");
	imshow("test", src);
	waitKey(0);
	destroyAllWindows();
	return 0;
}



