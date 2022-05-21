//╡Бйтнд╪Ч
#include <opencv2/opencv.hpp>
#include <iostream>
#include <Dense>
#include <math.h>
#include "Dimension.h"
#include "Chaos.h"
using namespace cv;
using namespace std;


int main() {
	Mat src = imread("./resource/690x690.jpg");
	std::vector<uchar> t;
	t = Dimension::img2OneColor(src, myEnum::Color::RED);
	cout << t.size() << endl;
	return 0;
}



