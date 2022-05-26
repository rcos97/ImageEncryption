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
		//mapĬ�ϰ���keyֵ��С��������
		//���map��valueֵ�����������
		seqMap.insert(std::pair<mpf_class, int>(keySeq[i], i));
	}
	//ԭʼͼƬ��RGB����ֵ
	std::vector<uchar> imgVector;
	std::vector<uchar> tempVector;
	tempVector =Dimension::img2OneColor(this->img, myEnum::Color::RED);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::GREEN);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::BLUE);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	//��RGB���н�������
	std::vector<uchar> chaosImgVec;
	chaosImgVec.resize(imgVector.size());
	auto iter = seqMap.begin();
	int i = 0;
	while (iter != seqMap.end()) {
		chaosImgVec[i] = imgVector[iter->second];
		iter++;
		i++;
	}
	//�����RGB�������ͼƬ
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
	//�ϲ�ͨ��
	std::vector<cv::Mat> matVec;
	//������Ҫʱbgr��˳��push
	matVec.push_back(b);
	matVec.push_back(g);
	matVec.push_back(r);
	cv::merge(matVec, this->img);
}

void ChaoSeqEnc::decrypt(std::vector<mpf_class> keySeq)
{
	//���ɻ�������
	std::map<mpf_class, int, myCompare> seqMap;
	for (int i = 0; i < keySeq.size(); i++) {
		seqMap.insert(std::pair<mpf_class, int>(keySeq[i], i));
	}
	//��������
	std::vector<int> desVec;
	desVec.resize(seqMap.size());
	auto iter = seqMap.begin();
	int j = 0;
	while (iter != seqMap.end()) {
		desVec[iter->second] = j;
		j++;
		iter++;
	}
	//ԭʼͼƬ��RGB����ֵ
	std::vector<uchar> imgVector;
	std::vector<uchar> tempVector;
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::RED);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::GREEN);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	tempVector = Dimension::img2OneColor(this->img, myEnum::Color::BLUE);
	imgVector.insert(imgVector.end(), tempVector.begin(), tempVector.end());
	//���ݽ���������������ԭʼͼƬ��RGB����ֵ
	std::vector<uchar> resultImgVec;
	auto viter = desVec.begin();
	resultImgVec.resize(imgVector.size());
	int i = 0;
	while (viter != desVec.end()) {
		resultImgVec[i] = imgVector[*viter];
		viter++;
		i++;
	}
	//RGB�������ͼƬ
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
	//�ϲ�ͨ��
	std::vector<cv::Mat> matVec;
	matVec.push_back(b);
	matVec.push_back(g);
	matVec.push_back(r);
	cv::merge(matVec, this->img);
}
