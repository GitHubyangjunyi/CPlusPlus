// OnewayLinkedList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
//从上往下看
//IntSLLNode节点的定义中用到了自身,因为数据成员next指向了刚刚定义的同类型的节点,这种对象成为自我引用对象
class IntSLLNode
{
public:
	int info;//用于存储信息
	IntSLLNode *next;//用于指向下一个节点
	IntSLLNode()//这一构造函数只为将next指针初始化为null,并无数据
	{
		next = 0;
	}
	IntSLLNode(int i, IntSLLNode *in=0)//这一构造函数一是用于初始化info成员,二是用于初始化next成员
	{//考虑到用户只提供一个参数时,则令next为null
		info = i;
		next = in;
	}
};

//以下可以先折叠,刚开始这一类可先跳过
class IntSLList
{
private:
	IntSLLNode *head, *tail;//都是指向节点类型的指针
public:
	IntSLList()
	{
		head = tail = 0;
	}
	~IntSLList();
	int isEmpty()
	{
		return head == 0;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead();
	int deleteFromTail();
	void deleteNode(int);
	bool isInList(int)const;
};

IntSLList::~IntSLList()
{
	for (IntSLLNode *p ;!isEmpty() ; )
	{
		p = head->next;
		delete head;
		head = p;
	}
}

void IntSLList::addToHead(int e1)
{
	head = new IntSLLNode(e1, head);
	if (tail==0)
	{
		tail = head;
	}
}

void IntSLList::addToTail(int e1)
{
	if (tail!=0)
	{
		tail->next = new IntSLLNode(e1);
		tail = tail->next;
	}
	else
	{
		head = tail = new IntSLLNode(e1);
	}
}

int IntSLList::deleteFromHead()
{
	int e1 = head->info;
	IntSLLNode *temp = head;
	if (head==tail)
	{
		head = tail = 0;
	}
	else
	{
		head = head->next;
	}
	delete temp;
	return e1;
}

int IntSLList::deleteFromTail()
{
	int e1 = tail->info;
	if (head==tail)
	{
		delete head;
		head = tail = 0;
	}
	else
	{
		IntSLLNode *temp;
		for (temp=head; temp->next!=tail ;temp=temp->next )
		{

		}
		delete tail;
		tail = temp;
		tail->next = 0;
	}
	return e1;
}

void IntSLList::deleteNode(int e1)
{
	if (head!=0)
	{
		if (head==tail&&e1==head->info)
		{
			delete head;
			head = tail = 0;
		}
		else
		{
			IntSLLNode *pred, *temp;
			for (pred=head,temp=head->next ;temp!=0&&!(temp->info==e1) ;pred=pred->next,temp=temp->next )
			{

			}
			if (temp!=0)
			{
				pred->next = temp->next;
				if (temp==tail)
				{
					tail = pred;
				}
				delete temp;
			}
		}
	}
}

bool IntSLList::isInList(int e1)const
{
	IntSLLNode *temp;
	for (temp=head ; temp!=0&&!(temp->info)==e1; temp=temp=temp->next)
	{

	}
	return temp != 0;
}
//以上可以先折叠

int main()
{
	IntSLLNode *p = new IntSLLNode(10);
	p->next = new IntSLLNode(8);
	p->next->next = new IntSLLNode(50);//p->next->next是第二个节点的next成员,由于只能通过变量p访问链表,所以必须使用这种麻烦的符号
	//所以为方便链表元素的访问,方法之一是在链表中保存两个指针,一个指向第一个节点,另一个指向最后一个节点
	//解决方法是增加一个类IntSLList,下面使用类IntSLList
	IntSLList list;
	list.addToHead(3);
	cout << (p->info);

    return 0;
}