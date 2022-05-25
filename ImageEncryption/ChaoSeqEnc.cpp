#include "ChaoSeqEnc.h"


ChaoSeqEnc::ChaoSeqEnc(cv::Mat m):ImgBase(m)
{
}

struct myCompare {
	bool operator()(const mpf_class & l, const mpf_class & r)const
	{
		return cmp(l, r) < 0 ? true:false;
	}
};


void ChaoSeqEnc::Enc(std::vector<mpf_class> keySeq)
{
	std::map<mpf_class, int, myCompare> seqMap;
	for (int i = 0; i < keySeq.size(); i++) {
		//map默认按照key值从小到大排序
		//因此map的value值就是随机序列
		seqMap.insert(std::pair<mpf_class, int>(keySeq[i], i));
		//std::cout << keySeq[i] << ":" << i << std::endl;
	}
	//原始图片的RGB序列值
	std::vector<uchar> imgVector;
	std::vector<uchar> tempVector;
	tempVector =Dimension::img2OneColor(this->img, myEnum::Color::RED);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::GREEN);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::BLUE);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	//将RGB序列进行乱序
	std::vector<uchar> chaosImgVec;
	chaosImgVec.resize(imgVector.size());
	auto iter = seqMap.begin();
	int i = 0;
	while (iter != seqMap.end()) {
		chaosImgVec[iter->second] = imgVector[i];
		iter++;
		i++;
	}
	//乱序后RGB序列组成图片
	int step = this->width * this->height;
	std::vector<uchar> rCVec;
	std::vector<uchar> gCVec;
	std::vector<uchar> bCVec;
	rCVec.insert(rCVec.begin(), chaosImgVec.begin(), chaosImgVec.begin() + step);
	cv::Mat r = Dimension::vec2ImgMatC1(this->width, this->height, rCVec);
	gCVec.insert(gCVec.begin(), chaosImgVec.begin() + step, chaosImgVec.begin() + (long long)2 * step);
	cv::Mat g = Dimension::vec2ImgMatC1(this->width, this->height, gCVec);
	bCVec.insert(bCVec.begin(), chaosImgVec.begin() + (long long)2 * step, chaosImgVec.begin() + (long long)3 * step);
	cv::Mat b = Dimension::vec2ImgMatC1(this->width, this->height, bCVec);
	//合并通道
	std::vector<cv::Mat> matVec;
	matVec.push_back(r);
	matVec.push_back(g);
	matVec.push_back(b);
	cv::merge(matVec, this->img);
}
