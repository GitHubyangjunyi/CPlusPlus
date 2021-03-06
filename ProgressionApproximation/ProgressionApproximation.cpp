// ProgressionApproximation.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
	//abs()函数求绝对值
	double sum = 0, item = 1;
	for (int n = 1; abs(item)>1e-6; n++)//这里使用size_t会有bugfor (size_t n = 1; abs(item)>1e-6; n++)
	{
		item *= (-1.0)*(2 * n - 3) / (2 * n - 1);
		sum += item;
	}
	cout << "PI=" << fixed << sum * 4 << endl;
	//另一种方法
	sum = 0, item = 1;
	for (int denom = 1,sign=1; abs(item)>1e-6; denom+=2,sign*=-1)//这里使用size_t会有bugfor (size_t n = 1; abs(item)>1e-6; n++)
	{
		item = sign / double(denom);
		sum += item;
	}
	cout << "PI=" << fixed << sum * 4 << endl;
	//while循环
	sum = 1, item = 1;
	int denom = 1, sign = 1;
	while (abs(item)>1e-6)
	{
		denom += 2;
		sign *= -1;
		item = sign * 1.0 / denom;
		sum += item;
	}
	cout << "PI=" << fixed << sum * 4 << endl;
	//do-while循环
	sum = 0, item = 1;
	denom = -1, sign = -1;
	do
	{
		denom += 2;
		sign *= -1;
		item = sign * 1.0 / denom;
		sum += item;
	} while (abs(item)>1e-6);
	cout << "PI=" << fixed << sum * 4 << endl;
    return 0;
}
//级数逼近(Progression Approximation)
//循环的设计,对于无穷数列求和,逼近到某个近似值的情况,例如数学公式:PI/4=1-1/3+1/5-1/7...
//将所有不小于10的负6次方的项值加起来以小数点6位精度方式输出
//分析:
//1.整数不能表示小数所以PI的值用浮点double表示
//2.数列的第n项是((-1)的n-1次方)/(2n-1),第n项与第n-1项的关系为符号变一下,分母加2
//3.一种方法是根据循环变量n,求得第n项的值,累计,然后条件判断,若满足结束条件,则退出
//循环结束条件为前一个累计和与后一个累计和的差小于10的6次方
//由于前后两次的累计的结果之差的绝对值等于后一次加上去的值,所以也可以判断后一项的绝对值小于10的6次方而得到退出条件

