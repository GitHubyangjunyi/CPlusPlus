// SkipLinkedList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
using namespace std;
//链表存在一个重大缺陷,需要顺序扫描才能找到元素,将元素排序后查找也要顺序查找,因此链表最好允许跳过某些节点避免顺序处理
//跳跃链表是有序链表的一个变种,可以进行非顺序查找,查找是高效的,插入删除效率很低

const int MAX_LEVEL = 4;
template<class T>class SkipListNode
{
public:
	T key;
	SkipListNode **next;
	SkipListNode()
	{

	}
};
 
template<class T>class SkipList
{
private:
	typedef SkipListNode<T> *nodePtr;//???
	nodePtr root[MAX_LEVEL];
	int powers[MAX_LEVEL];
public:
	SkipList();
	bool isEmpty()const;
	void choosePowers();
	int chooseLevel();
	T* skiplistSearch(const T&);
	void skiplistInsert(const T&);
};

template<class T>SkipList<T>::SkipList()
{
	for (int i = 0; i < MAX_LEVEL; i++)
	{
		root[i] = 0;
	}
}

template<class T>bool SkipList<T>::isEmpty() const
{
	return root[0] == 0;
}

template<class T>void SkipList<T>::choosePowers()
{
	powers[MAX_LEVEL - 1] = (2 << (MAX_LEVEL - 1)) - 1;//???
	for (int i = MAX_LEVEL-2,j=0; i >= 0; i--,j++)//???
	{
		powers[i] = powers[i + 1] - (2 << j);
	}
}

template<class T>int SkipList<T>::chooseLevel()
{
	int i, r = rand() % powers[MAX_LEVEL - 1] + 1;
	for ( i = 1	; i < MAX_LEVEL; i++)
	{
		if (r<powers[i])
		{
			return i - 1;
		}
		return i - 1;
	}
}

template<class T> T* SkipList<T>::skiplistSearch(const T& key)
{
	if (isEmpty())
	{
		return 0;
	}
	nodePtr prev, curr;
	int lvl;
	for (lvl = MAX_LEVEL-1; lvl>=0 && !root[lvl]; lvl--)
	{
		prev = cruu = root[lvl];
	}
	while (true)
	{
		if (key==curr->key)
		{
			return &curr->key;
		}
		else if (key<curr->key)
		{
			if (lvl==0)
			{
				return 0;
			}
			else if (curr==root[lvl])
			{
				curr = root[--lvl];
			}
			else
			{
				curr = *(prev->next + --lvl);
			}
		}
		else
		{
			prev = curr;
			if (*(curr->next+lvl!=0))
			{
				curr = *(curr->next + lvl);
			}
			else
			{
				for (lvl--; lvl>0 && *(curr->next+lvl)==0; lvl--)
				{

				}
				if (lvl>=0)
				{
					curr = *(curr->next + lvl);
				}
				else
				{
					return 0;
				}
			}
		}
	}
}

template<class T>void SkipList<T>::skiplistInsert(const T& key)
{
	nodePtr curr[MAX_LEVEL], prev[MAX_LEVEL], newNode;
	int i, lvl;
	curr[MAX_LEVEL - 1] = root[MAX_LEVEL - 1];
	prev[MAX_LEVEL - 1] = 0;
	for (lvl= MAX_LEVEL - 1; lvl>=0; lvl--)
	{
		while (curr[lvl] && curr[lvl]->key < key)
		{
			prev[lvl] = curr[lvl];
			curr[lvl] = *(curr[lvl]->next + lvl);
		}
		if (curr[lvl] && curr[lvl]->key==key)
		{
			return;
		}
		if (lvl>0)
		{
			if (prev[lvl]==0)
			{
				curr[lvl - 1] = root[lvl - 1];
				prev[lvl - 1] = 0;
			}
			else
			{
				curr[lvl - 1] = *(prev[lvl]->next + lvl - 1);
				prev[lvl - 1] = prev[lvl];
			}
		}
	}
	lvl = chooseLevel();
	newNode = new SkipListNode<T>;
	newNode->next = new nodePtr[sizeof(nodePtr) * (lvl + 1)];
	newNode->key = key;
	for ( i = 0; i <= lvl; i++)
	{
		*(newNode->next + i) = curr[i];
		if (prev[i]==0)
		{
			root[i] = newNode;
		}
		else
		{
			*(newNode->next + i) = newNode;
		}
	}
}


int main()
{

    return 0;
}

