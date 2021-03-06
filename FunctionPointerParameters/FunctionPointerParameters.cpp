// FunctionPointerParameters.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int bitSum(int a);
bool lessThanBitSum(int a, int b);

int main()
{
	//从上往下看
	//数据指针除了进行参数传递外,还承接申请空间/释放空间等任务
	//函数指针主要是用来进行参数传递的,就像引用
	//在标准排序算法sort中,对于所提供的整数容器vector,无需提供其他操作即可完成排序,如下
	int a[] = { 33,61,12,19,14,71,78,59 };
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << endl;
	}
	vector<int> aa(a, a + 8);
	cout << "aa values:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << aa[i] << endl;
	}
	sort(aa.begin(), aa.end());
	cout << "Sorted" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << aa[i] << endl;
	}
	//但是若整数的大小是以各位数字之和大小来比较的,就不能直接用sort函数进行比较
	//需要先定义一个比较函数,然后再对sort传递比较函数指针,已让sort知道大小关系不是默认的整数值的比较
	//而是根据比较函数来判定,可用函数指针调取比较函数来进行比较,如下
	cout << "Function Pointer Parameters" << endl;
	int b[] = { 33,61,12,19,14,71,78,59 };
	vector<int> bb(b, b + 8);
	cout << "bb values:" << endl;
	for (int i = 0; (unsigned)i < bb.size(); i++)
	{
		cout << bb[i] << endl;
	}
	sort(bb.begin(), bb.end(),lessThanBitSum);//第三个实参为比较函数名,函数名即为函数指针,正像数组名即为数组指针一样
	//sort的形参即为一个相对应的函数指针,参数类型为某个元素类型T的bool(const T&,const T&)
	cout << "Sorted" << endl;
	for (int i = 0; (unsigned)i < bb.size(); i++)
	{
		cout << bb[i] << endl;
	}
    return 0;
}

int bitSum(int a)
{
	int sum = 0;
	for (int x = a; x ; x/=10)
	{
		sum += x % 10;
	}
	return sum;
}

bool lessThanBitSum(int a, int b)
{
	return bitSum(a) < bitSum(b);
}
