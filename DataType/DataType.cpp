// DataType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Complex//复数类实部和虚部
{
public:
	Complex(double re = 0, double ima = 0) :real(re), imag(ima)//使用初值列性能较好,C++默认先使用初值列
	{

	}
private:
	double real, imag;
};

//数据类型三个要素:数据表示/范围表示/操作集合
int main()
{
	int a = 65;
	char b = 65;
	int c = '\101';
	cout << a << b<<c<<"\n";
	//C++提供多种表示初始化的符号,一种通用形式是使用花括号内的一组初始化器列表
	//使用初始化器至少确保不会发生可能导致信息丢失的类型转换
	int i = 7.8;//发生精度丢失
	//int it{ 7.8 };//发生精度丢失,编译器警告
	cout << "i=" << i << "\n";
	double dx{ 2.3 };
	_complex xx = { 8.9,9 };
	vector<int>{1, 2, 3, 4, 5, 6};
	//当我们没有明显的理由需要显式指定数据类型时,一般使用auto
	//在定义变量时,如果可以由初始化器推断出类型,无需显式指定其类型
	auto ai = 8;
	auto ab = true;
	auto ais = sqrt(8);
	cout << "ais=" << ais << "\n";
	enum Week//定义枚举时,花括号中的名称代表某个整数值,默认第一个0
	{
		Mon=1,
		Tue,
		Wed=0,
		Thu,
		Fri=50,
		Sat,
		Sun
	};
	//枚举定义中规定了若干个代表整数值的枚举符,全体枚举符作为全体整数的一个子集
	cout << "Mon :" << Mon << "\n";
	cout << "Tue :" << Tue << "\n";
	cout << "Wed :" << Wed << "\n";
	cout << "Thu :" << Thu << "\n";
	cout << "Fri :" << Fri << "\n";
	cout << "Sat :" << Sat << "\n";
	cout << "Sun :" << Sun << "\n";
	Week week = Wed;//正确的使用方法
	//Week week = 0;//错误的使用方法
	int meiju = Week(3);//并不是按下标访问
	int meiju1 = Week(4);
	cout << "week :" << week << "\n";
	cout << "meiju :" << meiju << "\n";
	cout << "meiju :" << meiju1 << "\n";
	//布尔型
	//bool x = 3;//警告:“初始化” : 从“int”到“bool”截断,这句话表示会产生精度丢失
	bool x = 1;
	bool y = 1;
	bool z = x + y;
	cout << x<<"\n";//布尔型输出默认1和0
	cout << boolalpha << x<<"\n";
	//浮点型,直接写出浮点数的字面值时默认为double,如果要表示成float型,要在后面加上f或F
	float f1 = 19.2f;
	float f2 = 0.192e+02;//将double转换为float,编译器警告:从double到float的截断
	double d1 = 19.2;
	double d2= 0.192e+02f;//将float转换为double
	long double ld1 = 19.2L;
	long double ld2 = 0.192e+02;//将double数转换为long double
	//获取单精度浮点数的二进制位码
	int* pa = (int*)&f1;
	for (int i = 31; i >=0; i--)
	{
		cout << (*pa >> i & 1) << (i==31||i==23 ? "-":"");
		//cout << "\n";
	}
	//常量,C++支持两种不变性概念
	//const:承诺不去改变这个值,主要用于说明接口,这样把变量传入函数时就不用担心变量值在函数内被改变,编译器负责确认并执行承诺
	//constexpr:意为在编译时求值,主要用于说明常量,允许将数据置于只读内存中以及提升性能

    return 0;
}
//余数的正负性决定于被除数的正负性,这与整除/操作的负负得正不同
//因为负数在机器表示中最高位为一,进行取余运算后最高位还是一
//11%(-5)=1
//-11%(-5)=-1
//在十进制中,一个浮点数可以用科学记数法表示,-306可以写成-0.3065*10的3次方
//指数3为阶或阶码,0.3065是小数部分称为尾数,其左右端非0数字包起来的最长的数字序列称为有效值,这里的有效值是3065
//之所以称为浮点数,以为它也可以表示成-3.065*10的2次方,以及-0.03065*10的4次方,小数点可以左右移动
//不管小数点怎么移动,有效值还是3065,不过尾数会变化成为065或03065
//两个浮点数要相加就先要通过小数点的移动对齐阶码,然后尾数相加
//0.0365*10的3次方+6.78*10的2次方
//=0.365*10的2次方+6.78*10的2次方
//=7.145*10的2次方
//为了使有效值和尾数能够统一,在空间上更有效率,便以一定长度的尾数表示尽可能多的有效值,有必要进行浮点数规格化
//即浮点数通过调整阶码,写成小数点前不含有效数字,小数点后第一位由非0数字表示
//例如-306.5规格化为-0.3065*10的3次方
//一旦十进制浮点数转换成二进制浮点数后,就要像十进制浮点数一样进行规格化
//二进制浮点数是通过调整阶码使得该数的有效值在1和2之间,即二进制浮点数的整数部分为1
//例如0.8125=0.1101=1.101*2的-1次方,详细解释信息已经转到OneNote上