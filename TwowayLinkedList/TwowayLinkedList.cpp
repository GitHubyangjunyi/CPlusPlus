// TwowayLinkedList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;
#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
//单向链表只包含指向后继节点的指针,从而无法快速访问前驱节点
//为了避免这一问题,重新定义单向链表,使链表中的每个节点包含两个指针,一个指向前驱,一个指向后继,成为双向链表
template<class T> class DLLNode
{
public:
	T info;
	DLLNode *next, *prev;
	DLLNode()
	{
		next = prev = 0;
	}

	DLLNode(const T& e1,DLLNode *n=0,DLLNode *p = 0 )
	{
		info = e1;
		next = n;
		prev = p;
	}
};

template<class T> class DoubleLinkedList
{
protected:
	DLLNode<T> *head, *tail;
public:
	DoubleLinkedList()
	{
		head = tail = 0;
	}

	void addToTail(const T& e1);
	T deleteFromDLLTail();
};

template<class T> void DoubleLinkedList<T>::addToTail(const T& e1)//注意泛型函数声明方式,复杂,但重用性强
{
	if (tail!=0)
	{
		tail = new DLLNode<T>(e1, 0, tail);
		tail->prev->next = tail;
	}
	else//空链表情况下添加尾节点
	{
		head = tail = new DLLNode<T>(e1);//实例化只有info而没有前驱和后继的新节点,将head和tail指向这个新节点
	}
}

template<class T> T DoubleLinkedList<T>::deleteFromDLLTail()//注意泛型函数声明方式,复杂,但重用性强
{
	
	if (head == tail&&head==0)
	{
		return NULL;
	}
	else
	{
		T e1 = tail->info;
		if (head == tail)
		{
			delete head;
			head = tail = 0;		//解决方案0
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = 0;
		}
		return e1;
	}
	//T e1 = tail->info;
	//if (head == tail)
	//{
	//	delete head;
	//	head = tail = 0;
	//}
	//else				//原来的版本,如果试图删除空链表的尾节点会引发空指针异常
	//{
	//	tail = tail->prev;
	//	delete tail->next;
	//	tail->next = 0;
	//}
	//return e1;
}

int main()
{
	//试图删除空链表的尾节点会引发空指针异常,查看需将解决方案0与原来的版本互换,并在调试模式下运行
	DoubleLinkedList<int> x;
	int i=x.deleteFromDLLTail();
	cout << i << "\n";//解决方案0情况下输出0,原来版本空指针异常卡住
	x.addToTail(5);
	i = x.deleteFromDLLTail();
	cout << i << "\n";
    return 0;
}
#endif // !DOUBLE_LINKED_LIST
//在双向链表尾节点添加节点演示
//向空的双向链表添加尾节点
//head---->null<----tail
//执行head = tail = new DLLNode<T>(e1);//实例化只有info而没有前驱和后继的新节点,将head和tail指向这个新节点
//变成一个节点的双向链表
//head---->[info]<----tail
//		   [  \ ]
//		   [  \ ]

//向只有一个节点的双向链表添加尾节点
//head---->[info]<----tail
//		   [  \ ]
//		   [  \ ]
//执行tail = new DLLNode<T>(e1, 0, tail);增加一个节点并将tail指针指向新的尾节点
//head---->[info]<--|
//		   [  \ ]   | 	[ e1 ]<----tail
//		   [  \ ]   |	[  \ ]
//					|---[tail]
//执行tail->prev->next = tail;
//变成普通数量的双向链表
//head---->[info]<--|
//		   [next]---|-->[ e1 ]<----tail
//		   [  \ ]   |	[  \ ]
//					|---[tail]

//向普通数量的双向链表添加尾节点
//head---->[info]<-|
//		   [next]--|->[info]<-|
//		   [  \ ]  |  [next]--|->[info]<-|
//				   |--[prev]  |  [next]--|->[info]<-|
//							  |--[prev]	 |  [next]--|->[info]<-|
//										 |--[prev]	|  [next]--|->[info]<-|
//												    |--[prev]  |  [next]--|->[info]<-|
//															   |--[prev]  |  [next]--|->[info]<----tail
//																		  |--[prev]  |  [  \ ]
//																					 |--[prev]
//执行tail = new DLLNode<T>(e1, 0, tail);增加一个节点并将tail指针指向新的尾节点
//head---->[info]<-|
//		   [next]--|->[info]<-|
//		   [  \ ]  |  [next]--|->[info]<-|
//				   |--[prev]  |  [next]--|->[info]<-|
//							  |--[prev]	 |  [next]--|->[info]<-|
//										 |--[prev]	|  [next]--|->[info]<-|
//												    |--[prev]  |  [next]--|->[info]<-|
//															   |--[prev]  |  [next]--|->[info]<--|
//																		  |--[prev]  |  [  \ ]   |	[ e1 ]<----tail
//																					 |--[prev]   |	[  \ ]
//																								 |--[tail]
//执行tail->prev->next = tail;
//head---->[info]<-|
//		   [next]--|->[info]<-|
//		   [  \ ]  |  [next]--|->[info]<-|
//				   |--[prev]  |  [next]--|->[info]<-|
//							  |--[prev]	 |  [next]--|->[info]<-|
//										 |--[prev]	|  [next]--|->[info]<-|
//												    |--[prev]  |  [next]--|->[info]<-|
//															   |--[prev]  |  [next]--|->[info]<--|
//																		  |--[prev]  |  [next]   |	[ e1 ]<----tail
//																					 |--[prev]   |	[  \ ]
//																								 |--[tail]