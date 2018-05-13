// StackType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "vector"
#include "list"
#include "iomanip"
#include "iostream"
using namespace std;
//栈是一种线性数据结构,存储以及查找只能访问栈的一端,像叠盘子一样最后放的盘子先被取出,先进后出原则
//一般来说,栈适用于数据存储后以相反顺序检索的情况
//栈中至少有一个元素时才能取出,只有空间足够时才能加入,栈的操作包括:
//清空栈				clear()
//判断栈是否为空		isEmpty()
//将元素放到栈的顶部	push(e1)
//弹出栈顶元素			pop()
//获取栈顶元素,但不删除	topEI()
//一个应用是在程序中匹配分隔符,分隔符匹配是编译器的一部分
//分隔符及其匹配的分隔符之间可以被其他分隔符隔开,也就是分隔符可以嵌套使用
//只有一个分隔符以及其匹配的分隔符之间的所有分隔符已经匹配,这个分隔符菜匹配
//例如循环while(m<(n[8]+o))的第一个左圆括号必须与最后一个右圆括号相匹配,但是只有当第二个左圆括号与倒数第二个右圆括号匹配之后
//第一个左圆括号和最后一个右圆括号才完成匹配
//分隔符匹配算法从源程序中读入一个字符,如果字符是左分隔符,将其存放在栈中
//如果发现一个右分隔符,则与栈中弹出的分隔符相比较,如果匹配继续处理,不匹配中断处理提示出错
//直到到达末尾并且栈为空时,成功完成对程序的处理
//							字符串匹配伪代码
//						从file中读取字符ch;
//						while file未结束
//							if	ch是'(','['或者'}'
//								将ch压入栈中;
//							else if ch是')',']'或者'}'
//									if ch和弹出的分隔符不匹配
//										出错;
//							else if ch是'/'
//									读下一个字符;
//									if 这个字符是'*'
//										跳过'*/'之前的所有字符,如果直到文件末尾还没有遇到'*/',报错
//									else ch=读入的字符;
//										continue;
//								else 忽略其他字符
//									从file中读入下一字符ch;
//							if 栈为空
//								匹配成功;
//							else 出错;
//								字符匹配结束
//另一个应用是非常大的数相加,整数的最大值有限制,无法将182743646777622347643256743672435672433467与126657834265473676743676767676346767467相加
//因为整型遍历不能存放这么大的值,为解决这个问题,可以将这种非常大的数看成一串数字,分别存放在两个栈中,弹出数进行相加
//使用中间变量存放进位
//								大数相加伪代码
//						读入第一个数字并存放到栈中
//						读入第二个数字并存放到栈中
//						Carry=0;
//						while(至少一个栈不为空)
//							从每个非空的栈中弹出一个数并与Carry进行相加;
//							将个数结果放进结果栈中;
//							将进位存进Carry中;
//						如果进位不为0,将其放进结果栈中
//						从结果栈中弹出结果并显示;
//大数相加使用栈
//592+3784
//	|	|			|	|			|	|			|	|			|	|
//	| 2 |---+		|	|			|	|			|	|			|	|
//	| 9 |	|		| 9 |---+|		|	|			|	|			|	|
//	| 5 |	|		| 5 |	|		| 5 |---+		|	|			|	|
//	-----	|		-----	|		-----	|		-----			-----
//			|				|				|
//			+-->6			+->17		   1+->13
//			|	|			|	7			|	|
//			|	|			|	|			|	|
//	| 4 |---+	|	|	|	|	|	|	|	|	|	|	|			|	|
//	| 8 |		|	| 8 |---+	|	|	|	|	|	|	|			|	|
//	| 7 |		|	| 7 |		|	| 7 |---+	|	|	|			|	|
//	| 3 |		|	| 3 |		|	| 3 |		|	| 3 |---1+->4	|	|
//	-----		|	-----		|	-----		|	-----		|	-----
//				|				|				|				|
//				|				|				|				|
//				|				|				|				|
//				|				|				|				|
//	|	|		|	|	|		|	|	|		|	|	|		|-->| 4 |
//	|	|		|	|	|		|	|	|		|-->| 3 |			| 3 |
//	|	|		|	|	|		|-->| 7 |			| 7 |			| 7 |
//	|	|		|-->| 6 |			| 6 |			| 6 |			| 6 |
//	-----			-----			-----			-----			-----

//栈的向量实现
template<class T, int capacity = 30> class Stack
{
private:
	vector<T> pool;
public:
	Stack()
	{
		pool.reserve(capacity);
	}
	void clear()
	{
		pool.clear();
	}
	bool isEmpty() const
	{
		return pool.empty();
	}
	T& topEL()
	{
		return pool.back();
	}
	T pop()
	{
		T el = pool.back();
		pool.pop_back();
		return el;
	}
	void push(const T& el)
	{
		pool.push_back(el);
	}
};
//栈的链表实现
template<class T>class LLStack
{
private:
	list<T> lst;
public:
	LLStack()
	{

	}
	void clear()
	{
		lst.clear();
	}
	bool isEmpty()const
	{
		return lst.empty();
	}
	T& topEL()
	{
		return lst.back();
	}
	T pop()
	{
		T el = lst.back();
		lst.pop_back();
		return el;
	}
	void push(const T& el)
	{
		lst.push_back();
	}
};
//链表的实现与抽象栈更为匹配,因为链表中只包含栈中的元素,链表的节点数和栈中元素的数目相等
//而在向量的实现中,栈的容量常常超过其大小,一样的是两个实现均不要求程序员在一开始就考虑栈的大小
//如果能够预估合理大小,则可将预估值作为栈构造函数的参数,提前创建一个指定容量的向量
//这样可避免向已满的栈中压入新元素时需要将栈元素复制到更大位置时的性能损失
//在向量与链表实现中,出栈和入栈时间常数为O(1),但是在向量实现中,将一个元素压入一个已经满的栈中需要分配更多的空间
//并且需要将现有的向量中的所有元素复制到一个新的向量中,最坏的情况是O(n)
int main()
{
    return 0;
}