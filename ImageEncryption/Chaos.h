#pragma once
#include <vector>
#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <gmpxx.h>
using namespace std;
class Chaos
{
public:
	static vector<mpf_class> henon(double init,int n);

	static void show(vector<double> r);

	
};

