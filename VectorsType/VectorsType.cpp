// VectorsType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//还有错误未排除
typedef vector<vector<int>> Mat;
Mat input();
void mySort(const Mat& a);
void print(const Mat& a);

int main()
{
	//vector是向量类型,是一种对象实体,可以容纳许多其他类型的相同实体,是C++STL标准模板库的重要一员
	//vector的四种定义方式
	vector<int> i(10);//定义了10个整型元素的向量,未初始化
	vector<double> d(10,1.0);//定义了10个double型元素的向量,初始化为1
	vector<double> dd(d);//使用现成的向量初始化
	vector<double> c(d.begin(),d.begin()+3);//定义了其值依次为向量b中第0个到第2个元素的向量
	//d.begin()/d.begin()是表示向量的起始元素位置和最后一个元素之外的元素位置
	//向量还可以从数组中获取值
	int a[7] = { 1,2,3,4,5,6,7 };
	vector<int> va(a, a + 7);
	//vector<int>是模板形式,<>中为元素类型名,可以是任何合法的数据类型
	//向量元素位置也属于一种类型,称为遍历器
	//遍历器不单单表示元素位置,还可以在容器中前后移动,每种容器都有对应的遍历器
	//向量中的遍历器类型为:vector<int>::iterator;
	//如果要输出向量中的所有元素,有两种循环控制方式,这里介绍遍历器
	for(vector<double>::iterator it=d.begin(); it!=d.end(); it++)
	{
		cout << *it << "\n";//*it是指针间接访问方式
	}
	////////////////////向量使用示例////////////////////
	//将VectorsType.txt读入到向量中,判断有多少对数两两相等
	ifstream in("VectorsType.txt");//该文件在Debug文件夹下
	vector<int> s;
	for (int b;in>>b;)
	{
		s.push_back(b);
	}
	int pair = 0;
	for (unsigned int i=0;i<s.size()-1;i++)
	{
		for (size_t j = i + 1; j < s.size(); j++)
		{
			if (s[i]==s[j])
			{
				pair++;
			}
		}
	}
	cout << "Hava " << pair << "number" << "\n";
	////////////////////向量使用示例////////////////////
	const Mat x = input();
	//mySort(x);
	print(x);
    return 0;
}

Mat input()
{
	ifstream in("VectorsType.txt");//该文件在Debug文件夹下
	Mat a;
	for (string s;getline(in,s);)
	{
		vector<int> b;
		istringstream sin(s);
		for (int ia = 0; sin>>ia ; )
		{
			b.push_back(ia);
			a.push_back(b);
		}
	}
	return a;
}

void mySort( Mat& x)
{
	for (unsigned int pass = 1; pass < x.size(); pass++)
	{
		for (unsigned int i = 0; i < x.size()-pass; i++)
		{
			if (x[i+1].size()<x[i].size())
			{
				x[i].swap(x[i+1]);
			}
		}
	}
}

void print( Mat& a)
{
	for (unsigned int i = 0; i < a.size(); i++)
	{
		for (unsigned int j = 0; j < a[i].size(); j++)
		{
			cout << a[i][j];
			cout << endl;
		}
	}
}
//12 3 45 67 8 9
//56 232 12 23
//12 1
//8
//1212 2312
//22 22