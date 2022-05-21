#pragma once
#include <vector>
#define PY_SSIZE_T_CLEAN
#include <Python.h>
using namespace std;
class Chaos
{
public:
	static vector<double> henon(double init,int n);

	static void show(vector<double> r);

	
};

