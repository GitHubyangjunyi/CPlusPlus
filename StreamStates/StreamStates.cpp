// StreamStates.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int main()
{
	cout << showpos << 12;
	cout << hex << 18 << "  " << showbase << 18;
	cout << hex << 255 << "  " << uppercase << 18;
	cout << 123.0 << "  " << showpoint << 123.0;
	cout << (2 > 3) << "  " << boolalpha << (2>3);
	cout << fixed << 12345.678;
	cout << scientific << 12345.678;
	cout.width(5);
	cout.fill('x');
	cout << 23 << 23;//第二次不会填充字符,只有前面的受宽度5的限制
    return 0;
}
//流iostream主管数据类型的识别工作和沟通操作系统,全权负责把流中的数据送到对应的设备上
//1.常用的流状态
//showpos  在正数之前显示+号
//showbase  加数制前置,十六进制加ox,八进制加o
//showpoint  浮点输出,即使小数点后都为零也加小数点
//uppercase  十六进制格式字母大写.默认小写
//boolalpha  逻辑值0和1用true和false表示
//left  左对齐
//right  右对齐
//dec  十进制显示整数
//hex  十六进制显示整数
//oct  八进制显示整数
//fixed  常规小数格式输出
//scientific  科学记数法输出
//取消流状态的操作为
//noshowpos,noshowbase,noshowpoint,nouppercase,noboolalpha
//相互对立的,设置了此就消了彼,而fixed和scientific和一般显示方式三者也是独立的
//不过取消方式是为cout捆绑函数调用的方式
//cout.unsetf(ios::scientific);
//2.有参数的三个常用流状态
//width(int)  设置显示宽度
//fill(char)  设置填充字符
//precision(int)  设置有效位数(普通显示方式)或精度(定点或科学记数法)
//这些流状态是以cout捆绑调用它们的形式设置的,不能与流出符<<连用
//特别注意width(n)是一次性操作,第二次显示时将不再有效,默认为0,表示仅显示数值
//3.与<<连用时的设置方式,但在使用时要包含另一个头文件iomanip
//