// PrimeDecision.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	cout << "Please input a number to determine if prime:";
	int m;
	cin >> m;
	double sqrtm = sqrt(m*1.0);
	for (size_t i = 2; i <= sqrtm; i++)
	{
		if (m%i==0)
		{
			cout <<m<< " isn't prime";
			return 1;
		}
	}
	cout << m << " is prime";
	return 0;
}
//若3都除不尽那么就没有必要用6,9去除了
//例如77的平方根值介于8和9之间,因为77不是素数,则它一定有比8还小的因子,它能被7整除
//所以必定有一个因子不大于m(要判断的数)平方根
//所以要判断一个数是否为素数,只要试除到m的平方根就可以了
