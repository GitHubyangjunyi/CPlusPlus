// Generic.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

template<class genType,int size> class GenericClass//两个参数
{
	genType storage[size];
public:
	void setstorage()
	{
		for (int i = 0; i < size; i++)
		{
			storage[i] = i;
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << storage[i] << "\n";
		}
	}
};

int main()
{
	GenericClass<int, 10> test;
	test.setstorage();
	test.print();
    return 0;
}
//C++的强大特性之一是能够在类的声明中使用类型参数来声明通用类