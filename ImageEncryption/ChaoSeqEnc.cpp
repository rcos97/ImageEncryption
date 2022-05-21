#include "ChaoSeqEnc.h"

ChaoSeqEnc::ChaoSeqEnc(cv::Mat m, std::vector<uchar> seq):ImgBase(m)
{
	this->seq = seq;
}

void ChaoSeqEnc::Enc()
{
	std::map<double, int> seqMap;
	for (int i = 0; i < (this->seq).size(); i++) {
		//mapĬ�ϰ���keyֵ��С��������
		seqMap.insert(std::pair<double, int>(this->seq[i], i));
	}


}
