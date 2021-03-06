// InlineFunctions.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//在C++中函数调用需要建立栈环境,进行参数复制,保护调用现场,返回时还要进行返回值复制,恢复调用现场
//这些都是额外开销,因此流行的CPU已经将这些跟特定任务无关的额外任务硬件化,减少开销但是还是会降低效率
//下面的示例是关于频繁调用小函数
bool isnumber(char);

int main()
{
	char c;
	while (cin>>c&&c!='\n')
	{
		if (isnumber(c))//反复调用小函数
		{
			cout << "you enter a digit\n";
		}
		else
		{
			cout << "you enter a non-digit\n";
		}
	}
    return 0;
}

bool isnumber(char ch)
{
	return ch >= '0'&&ch <= '9' ? 1 : 0;
}
//示例到此结束
//以上示例程序不断从标准输入设备中读取数据,频繁调用isnumber函数,函数调用占比较大,为了提高效率可将程序改写为
//int main()
//{
//	char c;
//	while (cin >> c && c != '\n')
//	{
//		if (c >= '0'&&c <= '9' ? 1 : 0)//融化小函数,免去函数调用开销提高效率
//		{
//			cout << "you enter a digit\n";
//		}
//		else
//		{
//			cout << "you enter a non-digit\n";
//		}
//	}
//	return 0;
//}
//由于isnumber函数相对于表达式可读性较好,所以如果在程序中多次出现isnumber,而又将其替换为表达式的话就会降低可读性
//我们既要可读性好又要性能时,可以将这种小函数声明为内联函数
//示例InlineFunctionsTwo