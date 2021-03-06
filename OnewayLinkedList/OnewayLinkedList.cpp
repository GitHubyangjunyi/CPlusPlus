// OnewayLinkedList.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
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

//以下可以先折叠,刚开始这个IntSLList类可先跳过不看,先看main函数前三行
//				head---->
//----IntSLList----{		可以说很形象了
//				tail---->
class IntSLList//这个类用来访问链表,要想象成两个箭头,其实就是链表,节点只是链表单元而已,链表的重点应在head指针和tail指针
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
//这里的head前面不加*是因为要指向对象,而不是要指向那个内容,也就是说要关联对象,而不是为了取出值
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
	head = new IntSLLNode(e1, head);//实例化一个节点,并将head给它,然后这个整体让head指向这个新建的节点
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
	else//空链表的情况
	{
		head = tail = new IntSLLNode(e1);
	}
}

int IntSLList::deleteFromHead()
{
	if (head==0&&tail==0)//解决方案0自己加的特殊链表下删除头节点发生空指针异常的解决方案,i可以显示了
	{
		return NULL;//返回mull也是显示0,因为返回值定义成int类型了,无法返回字符串
	}
	int e1 = head->info;//因为要返回被删除节点存放的值,所以要先将值存起来再删除节点
	IntSLLNode *temp = head;
	if (head==tail)
	{
		head = tail = 0;
	}
	else
	{
		head = head->next;//将head指向第二个节点
	}
	delete temp;//删除头节点这个对象
	return e1;
}

int IntSLList::deleteFromTail()
{
	if (head == 0 && tail == 0)//解决方案1自己加的特殊链表下删除尾节点发生空指针异常的解决方案,ot可以显示了
	{
		return NULL;//返回mull也是显示0,因为返回值定义成int类型了,无法返回字符串
	}
	int e1 = tail->info;
	if (head==tail)//如果链表只有一个节点,删除head指向的节点,重置head = tail = 0;
	{
		delete head;
		head = tail = 0;
	}
	else//普通链表的情况
	{
		IntSLLNode *temp;
		for (temp=head; temp->next!=tail; temp=temp->next)//循环n-1次迭代,时间复杂度为O(n)
		{
			//上面的语句temp = temp->next就是循环体
		}
		delete tail;
		tail = temp;
		tail->next = 0;
	}
	return e1;
}

void IntSLList::deleteNode(int e1)
{
	if (head!=0)//链表不为空
		if (head == tail&&e1 == head->info)//链表只有一个头节点并且参数匹配,删除head指向的头节点对象,重置head和tail为0
		{
			delete head;
			head = tail = 0;
		}
		else 
			if (e1 == head->info)//要删除的节点是头节点
			{
				IntSLLNode *temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				IntSLLNode *pred, *temp;//指向节点类型的指针
				for (pred = head, temp = head->next; temp != 0 && !(temp->info == e1); pred = pred->next, temp = temp->next)
				{

				}
				if (temp != 0)//找到节点情况下才有意义
				{
					pred->next = temp->next;//连接将要删除的节点的前后元素
					if (temp == tail)//删除的节点不是尾节点时不执行,如果删除的节点时尾节点,移动到最后,temp和tail都指向相同的节点,也就是尾节点,则令tail等于pred(指向尾节点的前一节点),删除尾节点释放空间
					{
						tail = pred;
					}
					delete temp;//删除节点释放空间
				}
			}
}

bool IntSLList::isInList(int e1)const//复杂度:最好情况O(1),最坏情况和平均情况O(n)
{
	IntSLLNode *temp;
	for (temp=head ; temp!=0&&!(temp->info==e1); temp=temp->next)//第一次打错写成!(temp->info)==e1
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
	IntSLList list;//特别注意,这个对象跟上面的以p开头的链表无联系,这是新建一个空链表,从头开始
	list.addToHead(11);
	list.addToHead(22);
	list.addToHead(33);
	cout << boolalpha << list.isInList(11) << "\n";//可以使用调试查看整个链表的指向
	//删除头节点的测试
	//下面测试试图删除一个特殊链表会引发异常,特殊链表包括空链表和只有一个元素的链表
	//第一种特殊链表,空链表
	IntSLList listEmpty;//建立空链表
	int i= listEmpty.deleteFromHead();//这里演示试图删除一个空链表会引发异常,需要在单步调试情况下才会显示异常信息,执行则不会显示cout << i;现在可以显示了,若要测试这个异常,将自己加的解决方案0注释掉
	cout << i << "\n";//并不会显示
	//所以要在deleteFromHead处理函数中添加对空链表的判断,并使用异常处理机制
	//解决方法可以是加入static_assert(!isEmpty());判断,如果条件是false程序终止,解决方法粗糙
	//第二种特殊链表是只有一个元素的链表,删除将会是链表成为空链表,这时候就要将head和tail都设置为mull
	IntSLList listOne;
	listOne.addToHead(1);//只有一个元素的链表
	int o=listOne.deleteFromHead();
	cout << o << "\n";
	//删除尾节点的测试
	//问题是删除尾节点后要让tail指向新的尾节点,tail必须反向移动
	//但因为从最后一个节点并没有直接的链接指向新尾节点,所以必须使用临时变量遍历整个链表
	//与删除头节点相似,存在两种特殊情况,空链表和只有一个节点的链表
	//第一种情况是如果链表为空,就不能删除任何节点
	//第二种情况是链表只有一个节点,删除后就成为空链表,要将head和tail设置为null
	IntSLList listEmptyTwo;
	int et= listEmptyTwo.deleteFromTail();//这里演示试图删除一个空链表会引发异常,需要在单步调试情况下才会显示异常信息,执行则不会显示cout << i;现在可以显示了,若要测试这个异常,将自己加的解决方案1注释掉
	cout << et << "\n";//不会显示
	//第二种特殊链表,只有一个节点的链表
	IntSLList listOneTwo;
	int ot = listOneTwo.deleteFromTail();
	cout << ot << "\n";
	//删除指定节点的测试
	IntSLList listtest;
	listtest.addToHead(10);
	listtest.addToHead(9);
	listtest.addToHead(8);
	listtest.addToHead(7);
	listtest.addToHead(6);
	listtest.addToHead(5);
	listtest.addToHead(4);
	listtest.addToHead(3);
	listtest.addToHead(2);
	listtest.addToHead(1);
    return 0;
}
//删除普通链表某一节点演示,且这一节点不是头节点也不是尾节点,其中XXXX是要删除的节点
//第一步实例化两个指针分别指向第一节点和第二节点
//head---->[info]<----pred
//		   [next]---->[info]<----temp
//					  [next]---->[info]
//								 [next]---->[XXXX]
//											[next]---->[info]
//													   [next]---->[info]<----tail
//																  [  \ ]
//第二步执行循环体移动指针
//head---->[info]
//		   [next]---->[info]<----pred
//					  [next]---->[info]<----temp
//								 [next]---->[XXXX]
//											[next]---->[info]
//													   [next]---->[info]<----tail
//																  [  \ ]
//下面是循环体执行完后的状态
//head---->[info]
//		   [next]---->[info]
//					  [next]---->[info]<----pred
//								 [next]---->[XXXX]<----temp
//											[next]---->[info]
//													   [next]---->[info]<----tail
//																  [  \ ]
//然后执行pred->next = temp->next;//连接将要删除的节点的前后元素
//下面是删除指定节点后链表的状态
//head---->[info]
//		   [next]---->[info]
//					  [next]---->[info]<----pred
//								 [next]----|      <----temp指向已被delete的对象,会不会出问题,不会,函数执行完对象消亡
//										   |---------->[info]
//													   [next]---->[info]<----tail
//																  [  \ ]




//删除普通链表某一节点演示,且这一节点是头节点,其中XXXX是要删除的节点
//第一步实例化temp指针指向头节点
//head---->[XXXX]<----temp
//		   [next]---->[info]
//					  [next]---->[info]
//								 [next]---->[info]
//											[next]---->[info]
//													   [next]---->[info]<----tail
//																  [  \ ]
//第二步令head指向第二节点,删除头节点
//head----|      <----temp指向已被delete的对象,会不会出问题,不会,函数执行完对象消亡
//		  |---------->[info]
//					  [next]---->[info]
//								 [next]---->[info]
//											[next]---->[info]
//													   [next]---->[info]<----tail
//																  [  \ ]




//删除普通链表某一节点演示,且这一节点是尾节点,其中XXXX是要删除的节点
//第一步实例化两个指针分别指向第一节点和第二节点
//head---->[info]<----pred
//		   [next]---->[info]<----temp
//					  [next]---->[info]
//								 [next]---->[info]
//											[next]---->[info]
//													   [next]---->[XXXX]<----tail
//																  [  \ ]
//第二步执行循环体移动指针
//head---->[info]
//		   [next]---->[info]<----pred
//					  [next]---->[info]<----temp
//								 [next]---->[info]
//											[next]---->[info]
//													   [next]---->[XXXX]<----tail
//																  [  \ ]
//下面是循环体执行完后的状态
//head---->[info]
//		   [next]---->[info]
//					  [next]---->[info]
//								 [next]---->[info]
//											[next]---->[info]<----pred
//													   [next]---->[XXXX]----{<----tail
//																  [  \ ]    {<----temp
//然后执行执行pred->next = temp->next;连接将要删除的节点的前后元素,其实这里连接到的是null
//然后temp==tail成立,然后执行tail=pred;令tail重定向指向新的尾节点
//head---->[info]
//		   [next]---->[info]
//					  [next]---->[info]
//								 [next]---->[info]				 {<----tail
//											[next]---->[info]----{<----pred
//													   [next]----|[XXXX]<----temp
//																 |->[  \ ]
//下面是删除指定节点尾节点后链表的状态
//head---->[info]
//		   [next]---->[info]
//					  [next]---->[info]
//								 [next]---->[info]				 {<----tail
//											[next]---->[info]----{<----pred
//													   [  \ ]          <----temp指向已被delete的对象,会不出问题,,不会,函数执行完对象消亡

//deleteNode情况分析
//1.试图删除空链表,函数退出
//2.从单节链表删除唯一节点:head和tail都设置为null
//3.从至少有两个节点的链表删除第一个节点:需要更新head
//4.从至少有两个节点的链表删除最后一个节点:需要更新tail
//5.试图删除链表中不存在的某个数字的节点,函数退出

//deleteNode时间复杂度分析
//1.最好情况:删除头节点:O(1)时间
//2.最坏情况:删除尾节点:O(n)时间,与deleteFromTail相当
//3.平均情况:(0+1+2+...+(n-1))/n=(n-1)n/2/n=(n-1)/2