// FileStreams.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;


int main()
{
	vector<int> prime(10000,1);
	for (size_t i = 2; i < 100; i++)
	{
		if (prime[i])
		{
			for (size_t j = i; i*j < 10000; j++)
			{
				prime[i*j] = 0;
			}
		}
	}
	ifstream in("a.txt");
	for (int a; in>>a && a>1 && a<10000;)
	{
		cout << a << " is " << (prime[a] ? "" : "not ") << " a prime.\n";
	}
	int a;
	cin >> a;
    return 0;
}
//文件的打开格式就像定义一个对象
//ifstream fin(filename,openmode=ios::in)
//ofstream fin(filename,openmode=ios::out)
//ifstream和ofstream都是类型名,表示输入和输出文件流,名称中的i和0表示输入和输出
//从2开始的某个连续的整数集合,留下2,除去所有的2的倍数,留下3,出去所有的3的倍数,留下5出去所有5的倍数
//接下来要判断是不是素数,访问以该数为下标的集合
//筛法求素数:这一次是从文本文件中读入数据判断素数
//先将10000个向量元素都赋初值1,凡是该下标的元素为1的则为素数
//初始状态下,所有整数都是素数,在这基础上将不是素数的数筛扣掉,将对应元素变为0
//筛选过程中,用了"若为素数必有因子小于其平方根"的思想
//10000个数,过滤因子到100就能保证10000以内全是素数了
