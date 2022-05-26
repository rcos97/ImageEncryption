#pragma once
#include <vector>
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <gmpxx.h>
using namespace std;
/**
 * @brief ���������������е���
*/
class Chaos
{
public:
	/**
	 * @brief ����henon��������
	 *			x_{n+1} = 1 - a*x_{n}*x_{n}+y_{n}
	 *			y_{n+1} = b*x_{n}
	 * ����a = 1.4;b=0.3;x_{0}=init;y_{0}=0���������������
	 * @param init �������еĳ�ֵ������x_{0}��ֵ
	 * @param n ���������г���
	 * @return ����Ϊn��henon������������
	*/
	static vector<mpf_class> henon(double init,int n);
	/**
	 * @brief ������������ɢ��ͼչʾ
	 * @param r ��������
	*/
	static void show(vector<double> r);

	
};

