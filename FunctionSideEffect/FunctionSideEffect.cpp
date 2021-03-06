// FunctionSideEffect.cpp: 定义控制台应用程序的入口点。
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

vector<int> add(vector<int>& a, vector<int>& b)
{
	for (int i = 0; (unsigned)i<a.size(); i++)
	{
		a[i] += b[i];
	}
	return a;
}

int main()
{
	int aa[] = { 2,3,1,2,3,2,1 };
	int bb[] = { 1,2,3,4,5,6,7 };
	vector<int> a(aa, aa + 7), b(bb, bb + 7);
	printf(a);
	printf(b);
	vector<int> c = add(a,b);
	printf(a);
	printf(b);
	printf(c);
    return 0;
}
//改动直接影响了传递进去的参数,如果要消除这一副作用,FunctionSideEffectTwo下有解决方案
