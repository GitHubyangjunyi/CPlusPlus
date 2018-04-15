// MinimumSample.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"


int main()
{
	std::cout << "MinimumSample\n";
    return 0;
}
//#include表示对编译器发出操作指令,指示编译器在编译之前,将包含的头文件在原地展开
//而头文件的内容则声明从现在开始标准输入/输出流操作可用,并在链接的作用下
//将编译后的输入\输出指令转化为对应的输入/输出设备的操作
//C++程序的总入口点总是int main(),操作系统装载可执行文件时,便装在文件到内存,并从main开始执行程序
//cout是标准输出设备的名称,<<是操作指令,指示将后面的数据显示到显示器设备上去
//std是名空间