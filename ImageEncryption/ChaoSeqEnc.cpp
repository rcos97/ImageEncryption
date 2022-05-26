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



void ChaoSeqEnc::encryption(std::vector<mpf_class> keySeq)
{
	std::map<mpf_class, int, myCompare> seqMap;
	for (int i = 0; i < keySeq.size(); i++) {
		//map默认按照key值从小到大排序
		//因此map的value值就是随机序列
		seqMap.insert(std::pair<mpf_class, int>(keySeq[i], i));
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
		chaosImgVec[i] = imgVector[iter->second];
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
	//这里需要时bgr的顺序push
	matVec.push_back(b);
	matVec.push_back(g);
	matVec.push_back(r);
	cv::merge(matVec, this->img);
}

void ChaoSeqEnc::decrypt(std::vector<mpf_class> keySeq)
{
	//生成混沌序列
	std::map<mpf_class, int, myCompare> seqMap;
	for (int i = 0; i < keySeq.size(); i++) {
		seqMap.insert(std::pair<mpf_class, int>(keySeq[i], i));
	}
	//解密序列
	std::vector<int> desVec;
	desVec.resize(seqMap.size());
	auto iter = seqMap.begin();
	int j = 0;
	while (iter != seqMap.end()) {
		desVec[iter->second] = j;
		j++;
		iter++;
	}
	//原始图片的RGB序列值
	std::vector<uchar> imgVector;
	std::vector<uchar> tempVector;
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::RED);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::GREEN);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::BLUE);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	//根据解密序列重新排列原始图片的RGB序列值
	std::vector<uchar> resultImgVec;
	auto viter = desVec.begin();
	resultImgVec.resize(imgVector.size());
	int i = 0;
	while (viter != desVec.end()) {
		resultImgVec[i] = imgVector[*viter];
		viter++;
		i++;
	}
	//RGB序列组成图片
	int step = this->width * this->height;
	std::vector<uchar> rCVec;
	std::vector<uchar> gCVec;
	std::vector<uchar> bCVec;
	rCVec.insert(rCVec.begin(), resultImgVec.begin(), resultImgVec.begin() + step);
	cv::Mat r = Dimension::vec2ImgMatC1(this->width, this->height, rCVec);
	gCVec.insert(gCVec.begin(), resultImgVec.begin() + step, resultImgVec.begin() + (long long)2 * step);
	cv::Mat g = Dimension::vec2ImgMatC1(this->width, this->height, gCVec);
	bCVec.insert(bCVec.begin(), resultImgVec.begin() + (long long)2 * step, resultImgVec.begin() + (long long)3 * step);
	cv::Mat b = Dimension::vec2ImgMatC1(this->width, this->height, bCVec);
	//合并通道
	std::vector<cv::Mat> matVec;
	matVec.push_back(b);
	matVec.push_back(g);
	matVec.push_back(r);
	cv::merge(matVec, this->img);
}
