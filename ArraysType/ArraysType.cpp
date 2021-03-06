// ArraysType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int array1[5] = { 1,2,3 };
int array2[5];

int main()
{
	//int a['a'];//表示int a[97];[]里的常量表达式只要是整数或整数子集就可以
	const int n = 100;
	//int b[n];//由于n是数据确定的
	int c[5] = {};//并不报错?
	cout << "sizeof(c):" << sizeof(c) << "\n";
	cout << "sizeof(c[0]):" << sizeof(c[0]) << "\n";
	////////////////////下列代码是关于数组默认值的示例////////////////////
	//数组的默认值,对于没有初始化的数组,分两种情况
	//一种是全局数组和静态数组,在函数外部定义,或者加上static修饰的数组定义,其元素总是被清零
	//另一种是局部数组,也就是在函数内部定义的数组,其值是不确定的
	int array3[5] = {2};
	//int array4[5];//注释掉,避免烦人的警告
	cout << "array1:" << "\n";
	for (size_t i = 0; i < sizeof(array1)/sizeof(array1[0]); i++)
	{
		cout << array1[i] << "\n";
	}
	cout << "array2:" << "\n";
	for (size_t i = 0; i < sizeof(array2) / sizeof(array2[0]); i++)
	{
		cout << array2[i] << "\n";
	}
	cout << "array3:" << "\n";
	for (size_t i = 0; i < sizeof(array3) / sizeof(array3[0]); i++)
	{
		cout << array3[i] << "\n";
	}
	cout << "array4:" << "\n";
	//for (size_t i = 0; i < sizeof(array4) / sizeof(array4[0]); i++)
	//{
	//	cout << array4[i] << "\n";//注释掉,避免烦人的警告:使用未初始化的内存警告
	//}
    return 0;
}

