// FunctionPointers.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//把函数声明和定义放一起为了方便一起看
void f();
void f()
{
}
int k();
int k()
{
	return 0;
}
int h(char);
int h(char)
{
	return 0;
}
int m(int,int);
int m(int, int)
{
	return 0;
}
int g(int);
int g(int x)
{
	cout << x;
	cout << x;
	return 0;
}
int (*gp)(int)=g;

int main()
{
	g(2);
	gp(4);
    return 0;
}
//一个运行中的程序在内存中的布局分为四个区域,代码区/全局数据区/堆区/栈区
//指向数据区的指针称为数据指针,指向代码区域的指针称为指向函数的指针,简称为函数指针
//但要注意,与返回指针类型的函数不同,该函数称为指针函数
//int* f(int a);
//char* copy(char* s1,char* s2);
//f函数返回int指针,即为int指针函数,copy函数称为char指针函数
//运行中的程序,其函数都存放在代码区,每个函数都有起始地址,指向函数起始地址的指针完全不同于数据指针
//之间不能相互转换,通过函数指针可以调用所指向的函数
//void f();
//int k();
//int g(int);
//int h(char);
//int m(int,int);
//函数是以参数个数/参数类型/参数顺序甚至返回值类型来区分不同类型的
//函数的类型表示是函数声明去掉函数名,所以上面的m函数类型表示为int(int,int)
//声明一个int(int)型函数就是把函数名放在返回值与括号之间
//int g(int);
//同样,定义一个int(int)型函数指针gp就是将指针名放在返回类型和括号之间
//int (*gp) (int);
//上面是定义一个函数指针,不是声明,而且函数指针名的括号不能省,表示*gp是一个整体
//int *gp (int);表示声明一个含有一个整型参数的整型指针函数,等价于int* gp
//定义函数指针还可以直接初始化
//int g(int);
//int (*gp)(int)=g;
//或者int (*gp)(int);
//gp=g;
//定义了一个函数指针,就拥有了一个指针实体,实体大小跟int类型实体大小一样
//函数指针的类型必须接受编译器类型检查,gp指针说指向的函数拥有一个int型参数,并返回int值
//函数指针也是一种数据类型,即
//int (*) (int);
//是int(int)型函数的指针类型,其中(*)的括号不能省,因为是数据类型就可以作为函数参数
//void f(int* a,int* b,int (*) (int));
//函数指针的定义比较复杂,可以使用typedef简化
//typedef int (*Fun)(int a,int b);
//int m(int,int);
//Fun funp=m;
//简略形式的函数指针表示
//int();//无名函数声明,表示一个函数类型
//int func();//函数声明,表示一个函数类型
//int (*) ();//无名函数指针
//int (*fp) ();//函数指针定义,fp是函数指针名,函数指针的函数类型是int()
//也就是说如果
typedef int Func();//表示将该函数类型称之为Func
//则函数指针定义等价为
Func* pf;
//进一步地
int(*func(int)) ();//是一个函数声明,是int()类型的指针函数,名字为func
//或者基于Func函数类型名字,可写为
Func* func(int);
//func函数返回一个函数指针,且带有一个int参数,该返回的函数指针类型为int()
int(*func(int))()
{
	return nullptr;
}
//习惯用法
typedef int(*SIG)();//声明返回int且无参函数的指针类型SIG
typedef void(*SIGARG)();//声明无返回且无参函数的指针类型SIGARG
SIG signal(int, SIGARG);//声明的函数返回函数指针,其参数为int和函数指针
SIG signal(int, SIGARG)
{
	return SIG();
}
//函数指针的意义
//1.基于历史原因,函数类型不能作为参数,如果参数中给出了一个函数类型,则自动转换为函数指针,这种现象称为蜕变decay
//MenuFun fun[]={f1,f2,f3};
//就是有蜕变才有这样的形式，本来是
//MenuFun fun[]={&f1,&f2,&f3};
//也使得函数指针调用形式成为fun[0] ();//*fun[0] ();
//2.可以使用函数引用
//void g();
//typedef void Fun();
//Fun& f=g;
//f();//调用函数g
//3.函数指针使得C++可以通过函数指针挂接,将其他语言编写的函数和过程引入C++
//函数指针使得程序表现出更多的灵活性,一个函数指针参数取不同的值,就可以让该函数表现出不同的行为
//4.事实上函数代码是跨进程的,通过函数指针可以越过本地进程,通过动态链接库的方式访问共享性质的其他进程(服务器)
//执行其函数,甚至操作系统函数