//²âÊÔÎÄ¼þ
#include <opencv2/opencv.hpp>
#include <iostream>
#include <Dense>
#include <math.h>
#include "Dimension.h"
#include "Chaos.h"
#include "ChaoSeqEnc.h"
using namespace cv;
using namespace std;


int main() {
	Mat src = imread("./resource/690x435.jpg");
	//std::vector<uchar> t;
	//t = Dimension::img2OneColor(src, myEnum::Color::RED);
	ChaoSeqEnc s(src);
	std::vector<mpf_class> t;
	t = Chaos::henon(0.1, s.width*s.height*3);
	s.encryption(t);
	imshow("+", s.img);
	s.decrypt(t);
	imshow("-", s.img);
	waitKey(0);
	//mpf_class a = 1.4, x = 0, xn = 0, y =1;
	//xn = 1 - a * x * x + y;
	//cout << xn << endl;
	return 0;
}



