// DataType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include"iomanip"
using namespace std;


int main()
{
	int a = 65;
	char b = 65;
	int c = '\101';
	cout << a << b<<c<<"\n";
	enum Week//枚举
	{
		Mon=1,
		Tue,
		Wed=0,
		Thu,
		Fri,
		Sat,
		Sun
	};
	cout << "Mon :" << Mon << "\n";
	cout << "Tue :" << Tue << "\n";
	cout << "Wed :" << Wed << "\n";
	cout << "Thu :" << Thu << "\n";
	cout << "Fri :" << Fri << "\n";
	cout << "Sat :" << Sat << "\n";
	cout << "Sun :" << Sun << "\n";
	//布尔型
    return 0;
}
//余数的正负性决定于被除数的正负性,这与整除/操作的负负得正不同
//11%(-5)=1
//-11%(-5)=-1
