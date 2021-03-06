// FunctionSideEffectTwo.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void printf(vector<int>& a)
{
	for (int i = 0; (unsigned)i < a.size(); i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}

vector<int> add(const vector<int>& a, const vector<int>& b)//使用const限定对参数写操作,这样就不会导致a被改变
{
	vector<int> c(a);//使用这一语法实现性能上较好
	for (int i = 0; (unsigned)i < a.size(); i++)
	{
		//a[i] += b[i];//使用const限定对参数写操作,导致a[i]不能做左值
		c[i] += b[i];
	}
	return c;
}

int main()
{
	int aa[] = { 2,3,1,2,3,2,1 };
	int bb[] = { 1,2,3,4,5,6,7 };
	vector<int> a(aa, aa + 7), b(bb, bb + 7);
	printf(a);
	printf(b);
	vector<int> c = add(a, b);
	printf(a);
	printf(b);
	printf(c);
	return 0;
}
