// InlineFunctionsPerformanceTesting.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

int cal1(int a,int b)
{
	return a + b;
}

inline int cal2(int a, int b)
{
	return a + b;
}
 
int main()
{
	int x[1000], y[1000], z[1000];
	clock_t t = clock();
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			for (int k = 0; k < 1000; k++)
			{
				z[i] = cal1(x[j], y[k]);
			}
		}
	}
	cout << "Not using inline:" << (clock() - t) / CLK_TCK << "seconds\n";
	t = clock();
	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			for (int k = 0; k < 1000; k++)
			{
				z[i] = cal2(x[j], y[k]);
			}
		}
	}
	cout << "Using inline:" << (clock() - t) / CLK_TCK << "seconds\n";
    return 0;
}
//这是一个实验,让主函数分别调用内联函数和非内联函数
//由于调用一次函数开销太小,只有几个机器指令,又有机器硬件专设的机构帮忙,所以调用10亿次放大时间差
//使用数组减少其他开销
