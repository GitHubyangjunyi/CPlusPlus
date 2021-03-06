// QueueType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <list>
#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

//队列是一个简单的等待序列,在尾部加入元素时队列变长,在前端删除数据时队列变短
//与栈不同,队列是使用两端的结构,一端用来加入新元素,另一端用来删除元素
//因此,最后一个元素必须等到排在它之前的元素都删除之后才能操作,先进先出原则
//清空队列				clear()
//判断是否为空			isEmpty()
//在队列尾部加入元素	enqueue(el)
//取出队列第一个元素	dequeue()
//返回队列第一个元素,但不删除	firstEL()
//队列的一种可能实现形式是数组,但并非最佳选择
//元素从队尾加入而从队首删除,这会释放数组中的某些单元,这些单元不应该被浪费
//因此,应该利用这些单元存放新的元素,这样队列的尾部可能会出现在数组的开头

//队列的数组实现
template<class T, int size = 100>class ArrayQueue
{
private:
	int first, last;
	T storage[size];
public:
	ArrayQueue()
	{
		first = last = -1;
	}
	void enqueue(T);
	T dequeue();
	bool isFull()
	{
		return first == 0 && last == size - 1 || first == last + 1;
	}
	bool isEmpty()
	{
		return first == -1;
	}
};
template<class T, int size> void ArrayQueue<T, size>::enqueue(T el)
{
	if (!isFull())
	{
		if (last==size-1 || last==-1)
		{
			storage[0] = el;
			last = 0;
			if (first==-1)
			{
				first = 0;
			}
		}
		else
		{
			storage[++last] = el;
		}
	}
	else
	{
		cout << "Full queue.\n";
	}
}
template<class T, int size> T ArrayQueue<T, size>::dequeue()
{
	T temp;
	tmp = storage[first];
	if (first==last)
	{
		last = first = -1;
	}
	else
	{
		if (first==size-1)
		{
			first = 0;
		}
		else
		{
			first++;
		}
	}
	return temp;
}

//队列的链表实现
template<class T>class Queue
{
public:
	Queue()
	{

	}
	void clear()
	{
		lst.clear();
	}
	bool isEmpty()
	{
		return lst.empty();
	}
	T& front()
	{
		return lst.front();
	}
	T dequeue()
	{
		T el = lst.front();
		lst.pop_front();
		return el;
	}
	void enqueue(const T& el)
	{
		lst.push_back(el);
	}
private:
	list<T> lst;
};
//如果在队列的链表实现中使用双向链表,这两种实现(数组和双向链表)执行入队和出队都需要常数时间O(1)
//在单向链表中出对需要O(n)次基本操作扫描链表,并在倒数第二个节点处停止
//队列常常用于模拟排队论:需要多少服务员才能避免排队?等候的空间需要多大才能容纳所有排队的顾客?增大空间还是增加服务员哪个花费更小?
//以第一银行为例,三个月内来到银行的顾客数目和对其提供服务所需的时间
//这一天15%的时间没有顾客到达,20%时间有一个顾客到达,亿次类推
//现在雇佣了6个服务员.没有顾客排队的情况发生,银行管理想知道是不是雇佣太多人了

//表一:每分钟到达银行的客户数目
//	每分钟顾客数目				一分钟间隔的百分比				范围
//		0								15						1-15
//		1								20						16-35
//		2								25						36-60
//		3								10						61-70
//		4								30						71-100

//表二:每个顾客交易所需要的时间(秒)
//	提供服务所需要的时间			顾客百分比					范围
//			0							0						 -
//			10							0						 -
//			20							0						 -
//			30							10						1-10
//			40							5						11-15
//			50							10						16-25
//			60							10						26-35
//			70							0						 -
//			80							15						36-50
//			90							25						51-75
//			100							10						76-85
//			110							15						86-100

//顾客由1至100之间的随机数决定,表一将1到100的数字分为5个部分,划分的根据是一分钟内到达0/1/2/3/4个顾客的百分比
//如果随机数为21,则顾客数目为1,如果随机数为90,则顾客数目为4
//此外对记录的分析表明,需要10秒或20秒交易时间的顾客数目为0,需要30秒交易时间的顾客数目为10%
//下面程序模拟了业务情况
//arrivals[]根据到达顾客数目记录每分钟到达顾客的百分比
//service[]用来存放服务所需时间的分布
//将给定数组单元的下标乘以10就可以得到时间值,例如service[3]等于10,意味着在10%的时间内,顾客需要3*10秒的服务时间
//clerks[]以秒为单位记录交易时间

int option(int percents[])
{
	register int i = 0, choice = rand() % 100 + 1, perc;
	for (perc = percents[0]; perc < choice; perc += percents[i + 1], i++)
	{
		
	}
	return i;
}

int main()
{
	int arrivals[] = { 15,20,25,10,30 };
	int service[] = { 0,0,0,10,5,10,10,0,15,25,10,15 };
	int clerks[] = { 0,0,0,0 };
	int numberOfClerks = sizeof(clerks) / sizeof(int);
	int customers, t, i, x, numberOfMinutes = 100;
	double maxWait = 0.0, currWait = 0.0, thereIsLine = 0.0;
	Queue<int> simulQueue;
	cout.precision(2);
	for (t = 1; t <= numberOfMinutes; t++)
	{
		cout << "t=" << t;
		for ( i = 0; i < numberOfClerks; i++)
		{
			if (clerks[i]<60)
			{
				clerks[i] = 0;
			}
			else
			{
				clerks[i] -= 60;
			}
		}
		customers = option(arrivals);
		for ( i = 0; i < customers; i++)
		{
			x = option(service) * 10;
			simulQueue.enqueue(x);
			currWait += x;
		}
		for ( i = 0; i < numberOfClerks && !simulQueue.isEmpty(); )
		{
			if (clerks[i]<60)
			{
				x = simulQueue.dequeue();
				clerks[i] += x;
				currWait -= x;
			}
			else
			{
				i++;
			}
		}
		if (!simulQueue.isEmpty())
		{
			thereIsLine++;
			cout << "wait=" << currWait / 60.0 << "\n";
			if (maxWait<currWait)
			{
				maxWait = currWait;
			}
		}
		else
		{
			cout << "wait=0;\n";
		}
	}
	cout << "\nFor " << numberOfClerks << " clerks,there was a line" << thereIsLine / numberOfMinutes * 100.0
		<< "% of the time;\n" << "maximum wait time was" << maxWait / 60 << "min.";
    return 0;
}
//每一分钟t到达的顾客数目是随机的,对每个顾客而言,交易时间也是随机选择的
//函数option生成一个随机数,找出其所在的范围,然后输出这个范围所在的位置,该位置或者是顾客数目或者是秒数的1/10
//这个程序的运行结果表明4个服务员就可以,25%的时间里有较短的排队