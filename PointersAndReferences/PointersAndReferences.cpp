// PointersAndReferences.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//关于这一程序,可以转到CSharp解决方案下Ref小项目,异曲同工之妙

char* myStrcpy(char* s1, const char* s2);//函数声明,不然后警告找不到标识符

int main()
{
	int* ip;
	int iCount = 18;
	int* iPtr = &iCount;//&表示实体的地址,由于字面值不认为是具有空间地址的实体,所以不能进行&操作ip = &23;是错的
	ip = &iCount;
	cout << "iCount=" << iCount << "\n";//输出18
	cout << "iPtr=" << iPtr << "\n";//输出指针变量iPtr的内容(iCount的十六进制地址)
	cout << "*iPtr=" << *iPtr << "\n";//输出iCount的值18
	cout << "ip=" << ip << "\n";//输出指针变量iP的内容(iCount的十六进制地址)
	cout << "*ip=" << *ip << "\n";//输出iCount的值18
	cout << "\n";
	//cout << "*iCount=" << *iCount << "\n";//编译报错,间接访问只能作用在指针上
	//指针的0值并不是表示指向地址为0的空间,而是表示空指针,即不指向任何空间
	//而指针只有指向具体的实体,间接访问才有意义
	//int* test;
	//*test = 58;//这一句编译时并不会报错,但是是错误的,为了避免这种错误C++引入了引用的概念
	//初学者一不小心就会混淆下列语句
	//int* ip = &iCount;与*ip= &iCount(错误);
	//ip = &iCount(正确);
	//第一句是带有初始化的指针定义语句,第二句是错误的赋值语句,因为*ip是间接访问所指向的整型实体的操作
	//而&iCount并非整形实体,左右两边类型不一致
	//指针指向的实体可以通过指针的间接访问操作,即在指针变量前加上*的操作来读写该空间的内容
	*iPtr = 12;//使用间接访问直接修改iCount的值
	cout << "iCount=" << iCount << "\n";//输出12
	cout << "\n";
	//由于指针变量本身也是具有空间的实体,因此也具有地址空间,也可以被别的指针(二级指责)所操纵
	int** iiPtr = &iPtr;//二级指针,取到存放指针变量iPtr的地址,而不是iPtr的值,iPtr的值是存放iCount的十六进制地址
	**iiPtr = 100;//*iiPtr = 100;//错误
	cout << "iiPtr=" << iiPtr << "\n";//输出iiPtr的内容(存放iPtr这个指针变量的地址)
	cout << "*iiPtr=" << *iiPtr << "\n";//输出iPtr所存放的值(iCount的存储地址)
	cout<<"**iiPtr="<< **iiPtr<<"\n";//取出存放在iiPtr这个指针变量中的值(存放iPtr指针变量的地址),然后再取出iPtr指针变量里存放的内容(iCount的存储地址)所指向的内容iCount的值100
	cout << "\n";
	//int* iPtriCount = &*iPtr;//定义的一级指针,不能存放指针的指针
	int* iPtriCount = iPtr;//跟上面的语句一样的作用
	cout << "iPtriCount=" << iPtriCount << "\n";//输出指针变量iPtriCount的内容(iCount的十六进制地址)
	cout << "*iPtriCount=" << *iPtriCount << "\n";//输出iCount的值100
	cout << "\n";
	////////////////////以下代码区为关于实体空间理解的代码,也就是最下面注释的示例代码////////////////////
	float f1 = 34.5;
	float* ipf = &f1;
	int* intp = reinterpret_cast<int*>(&f1);//reinterpret_cast<type-id>(expression)
	//type-id必须是一个指针/引用/算术类型/函数指针或者成员指针
	//它可以把一个指针转换成一个整数,也可以把一个整数转换成一个指针
	//(先把一个指针转换成一个整数,再把该整数转换成原类型的指针,还可以得到原先的指针值)
	cout << "ipf=" << ipf << "\n";
	cout << "*ipf=" << *ipf << "\n";
	cout << "float address:&f1:" << &f1 << "=>" << f1 << endl;
	cout << "int address:intp:" << intp << "=>" << *intp << endl;
	*intp = 100;
	cout << "int:" << *intp << endl;
	cout << "float:" << f1 << endl;
	cout << "\n";
	//以下是关于实体空间理解的代码这一部分的解释
	//一个float变量的空间实体被一个int型指针指向,当该指针间接访问时,float变量的空间实体便现出整形实体的面相
	//于是34.5这个浮点数按照二进制补码来理解就变得怪异
	//指针的类型性体现在间接访问时,读写所指向的空间实体时以自身的类型来规定其操作的
	//指针的类型性表明不同类型的指针,其类型是不同的,不能相互赋值,例如:int* ip=&f;错误,float的地址不能赋给int指针
	//但是从地址的本质上来说,无非是一堆二进制码,因此从内存空间位置性而言,不同类型的指针又是统一的
	//于是便有了强制转换这种操作,例如:int* ip=(int*)&address;
	//不管该地址空间存放着什么数据,都视为整形地址,甚至该空间存放的是函数代码也不管
	//以上代码中,如果该地址指向的空间以整数指针间接访问的方式赋予100,则以浮点的眼光去看的时候,一切都变了
	////////////////////以下代码区为指针运算的示例代码////////////////////
	//指针值表示一个内存地址,因此它内部表示为整数,指针变量所占的空间大小总是等于整形变量的大小,但不是整形数
	//数据类型三个要素:数据表示/范围表示/操作集合
	//指针不服从整形数操作规则,例如两个指针值不能相加,指针值不能赋予一个整形数(要想获得整型数表示的绝对地址,应将整型数解释转换为对应的指针类型)
	//int* ip=1234567;是错误的
	//int* sp= reinterpret_cast<int*>(1234567);正确
	//指针的加减整型数大多用在数组这种连续又是同类型元素的序列空间中
	//可以把数组起始地址赋给一个指针(数组名本身就是表示元素类型的地址)通过移动指针(加减整数)来对数组元素进行操作
	int iArray[6];
	for (size_t i = 0; i < 6; i++)
	{
		iArray[i] = i * 2;
	}
	for (int* aip = iArray; aip < iArray+6; aip+=1)
	{
		cout << aip << ": " << *aip << endl;
	}
	cout << "\n";
	//指针的增减是以该类型的实体的大小为单位的
	//对float指针加6实际上增加了24个字节
	//对long int指针加5实际上增加了20个字节
	//对char指针减7实际上减少了7个字节
	//对double指针减2实际上减少了16个字节
	////////////////////以下代码区为指针限定的示例代码////////////////////
	//一个指针可以操作两个实体,一是指针的值(地址),一是间访值,于是指针的常量性也分为两种:常量指针/指针常量
	//指针常量是相对于指针变量而言的,也就是指针值不能修改的指针
	//常量指针是指向常量的指针
	//定义常量指针还是指针常量看const修饰符,若const修饰指针本身,则为指针常量
	//若修饰指针类型(指向的实体类型),则为常量指针
	const int consti = 78;
	int b = 10;
	int c = 18;
	const int* constip = &consti;//const修饰指向的实体类型-常量指针
	int const* dp = &b;//等价于上一句-常量指针
	int* const cp = &b;//const修饰指针*cp-指针常量
	const int* const constintXconst = &c;//常量指针常量
	//*constip = 87;//错误,常量指针不能修改指向的实体,*constip只能作右值
	ip = &c;//常量指针可以修改指针值
	*cp = 81;//指针常量可以修改指向的实体
	//cp = &b;//错误,指针常量不能修改指针值
	//*constintXconst = 33;//错误,常量指针常量不能修改指向的实体
	//constintXconst = &b;//错误,常量指针常量不能修改指针值
	int d = *constintXconst;
	//const修饰只是限定指针的操作,但不能限定空间上的实体的可改变性,因为一个实体可能不止被一个变量所关联
	//所以实体被其他关联变量的改变是可能的,如下代码所示
	int e = 78, f = 18;
	const int* ecip = &e;
	const int* const constintYconst = &f;
	e = 60, f = 28;
	cout << "ecip=>" << e << endl;
	cout << "constintYconst=>" << f << endl;
	cout << "\n";
	////////////////////以下代码区为引用的示例代码////////////////////
	//从逻辑上理解,引用是一个别名,引用局限性更强,不允许改变地址
	//当建立引用时,用一个由具体类型的实体去初始化别名,之后,别名便与关联其实体的变量(或对象)享有访问的同等待遇
	int someint = 500;
	int& rInt = someint;//引用定义时必须初始化,这是与指针的根本区别,并且严格要求类型一致
	int &pInt = someint;//使用引用就等于实体又多了一个关联的名字,实体的值便任由关联的名称操作所宰割,修改引用就是修改实体值
	int & qInt = someint;
	//上面三个语句均可以定义引用
	int* testip = &someint;
	cout << "someint=" << someint<<"\n";
	rInt = 100;
	cout << "someint=" << someint << "\n";
	cout << "rInt=" << rInt << "\n";
	cout << "&rInt=" << &rInt << "\n";
	cout << "testip=" << testip << "\n";
	cout << "\n";
	int int1 = 10;
	int& rInt1 = int1;
	cout << "&int1:" << &int1 << "    int1:" << int1 << endl;
	cout << "&rInt1:" << &rInt1 << "    rInt1:" << rInt1 << endl;
	int int2 = 20;
	rInt1 = int2;//我自己感觉像int1=int2;这种操作,经过验证是
	cout << "&rInt1:" << &rInt1 << "    rInt1:" << rInt1 << endl;
	cout << "&int2:" << &int2 << "    int2:" << int2 << endl;
	cout << "\n";
	//在程序中,rInt1关联了int1,执行rInt1 = int2;后,其值发生变化,但其地址永不改变
	//引用与指针的差别,指针可以操纵两个实体,一是指针值,二是指向的值,指针可以改变关联的实体,即改变指向的实体
	//而引用只能操纵一个实体,一旦引用诞生,就确定了它与一个实体的联系,这种联系时打不破的,直到引用自身的灭亡
	//从物理实现上理解,引用是一个隐性指针,即引用值是引自所指向的实体
	//引用与实体的关系看似直接访问,实则为指针的间接访问,幕后的转换工作是由编译做的
	//编译将这个特殊的指针rInt1转换成*rInt1操作,因此,引用不能不能操作自身的地址值,每次访问rInt1,实际上是在访问所指向的int1实体
	//引用实现为指针,但是封锁了作为指针实现的地址操作,又将间接访问操作暗中转换成直接操作,使得引用从reference的根本实现中抽象出来
	//引用也可以限定
	int int3 = 1;
	const int& crInt = int3;
	//crInt = 10;//上面的语句阻止crInt做写操作,但并不妨碍实体值可能被修改
	cout << "int3=" << int3 << endl;
	cout << "crInt=" << crInt << endl;
	int3 = 2;
	cout << "int3=" << int3 << endl;
	cout << "crInt=" << crInt << endl;
	cout << "\n";
	////////////////////以下代码区为指针的增量操作的示例代码////////////////////
	//指针可以加减一个整型数而得到另一个指针值,指针的增量操作也分为前增量和后增量
	char ippluss[50];
	const char* ss = "Hello,I am a student.\n";
	cout << myStrcpy(ippluss,ss);
	//20180612 23:34戴聪聪
	int arraytest[] = { 1, 2, 3, 4, 5, 6, 7 };
	int *pxy = arraytest;
	*(pxy++) += 89;
	cout << *pxy << "xx" << *(++pxy);
	cout << *pxy << "xx" << *(++pxy);
	for (int i = 0; i < 7; i++)
	{
		cout << arraytest[i] << "\n";
	}
	return 0;
}

char* myStrcpy(char* s1, const char* s2)
{
	char* s = s1;
	while (*s++=*s2++)
	{
		//while中没有循环体
	}
	return s1;
}
//先从上面开始看,然后再看这
//每个类型都有对应的指针类型
//int* ip;
//char *cp;
//float*fp;
//double * dp;
//定义中的*可以居左/居右/居中,由于指针本身也是一种类型,所以指针也有对应的指针类型
//int** iip;二级整形指针变量
//一个*只能修饰一个指针
//int* ip,iq;
//ip为指针变量,iq为整形变量
//int* ip,*iq;定义两个指针变量
//指针变量的定义,由数据类型后跟*号,在跟指针变量名组成
//指针是有类型的,给指责赋值时,不但必须是一个地址,而且应该是一个与指针类型相符的变量或常量的地址
//计算机中的内存空间实体是没有类型性的,都是二进制位码,如果一个int类型变量代表一个32位的空间实体
//那么这个空间在用该变量访问时,就理解为整形实体