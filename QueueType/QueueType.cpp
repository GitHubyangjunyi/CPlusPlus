// QueueType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "list"
#include "iomanip"
#include "iostream"
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
//写到这P126
int main()
{
    return 0;
}