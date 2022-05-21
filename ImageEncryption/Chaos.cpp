#include "Chaos.h"

vector<double> Chaos::henon(double init , int n)
{
    vector <double> result;
    result.reserve(n);//从n后面开始添加的函数
    double a = 1.76;
    double b = 0.1;
    double x_n = init;
    double x_n1 = 0;
    double y_n = 1;
    double y_n1 = 0;
    result.push_back(x_n);
    for (int i = 1; i < n; i++) {
        x_n1 = 1 - a * x_n + y_n;
        y_n1 = b * x_n;
        x_n = x_n1;
        y_n = y_n1;
        result.push_back(x_n1);
    }
    return result;
}

void Chaos::show(vector<double> r)
{
    Py_Initialize();
    if (Py_IsInitialized()) {
        // 指定py文件目录
        PyRun_SimpleString("import sys");
        PyRun_SimpleString("sys.path.append('./')");
        PyObject* tuple = PyTuple_New(r.size());
        for (unsigned int i = 0; i < r.size(); i++) {
            PyTuple_SET_ITEM(tuple, i, Py_BuildValue("d", r.at(i)));
        }
        //Python 模块(Module)，是一个 Python 文件，以 .py 结尾
        //导入模块
        PyObject* pModule = PyImport_ImportModule("draw");
        PyObject* pFun = PyObject_GetAttrString(pModule, "test");
        PyObject* args = PyTuple_New(1);
        PyTuple_SetItem(args, 0, tuple);
        PyObject* pReturnValue = PyObject_CallObject(pFun, args);
    }
    Py_Finalize();
}
