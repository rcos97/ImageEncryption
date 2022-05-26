#pragma once
#include <vector>
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <gmpxx.h>
using namespace std;
/**
 * @brief 用来产生混淆序列的类
*/
class Chaos
{
public:
	/**
	 * @brief 产生henon混沌序列
	 *			x_{n+1} = 1 - a*x_{n}*x_{n}+y_{n}
	 *			y_{n+1} = b*x_{n}
	 * 其中a = 1.4;b=0.3;x_{0}=init;y_{0}=0将会产生混沌序列
	 * @param init 混沌序列的初值，就是x_{0}的值
	 * @param n 产生的序列长度
	 * @return 长度为n的henon混沌序列向量
	*/
	static vector<mpf_class> henon(double init,int n);
	/**
	 * @brief 将混沌序列用散点图展示
	 * @param r 混沌序列
	*/
	static void show(vector<double> r);

	
};

