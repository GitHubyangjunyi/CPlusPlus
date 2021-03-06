// StringType.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
//C++语言不提供支持连接运算的字符串类型,string位于C++标准库,如果把上面一行注释掉,下面的string将无法使用
//从用户角度看,使用内置类型和使用标准库类型几乎没有区别

int main()
{
	//注释从这往下看
	//在C++中,由两种字符串,一种是从C沿袭过来的,称为C-字符串,简称C-串,尽量别用
	//C-串是以全0字节作为结束符的字符序列
	//C-串的类型是const char*,事实上所有的字面值类型都是const的,char*称为字符指针,与字符数组虽然类型不同,但是操作是一样的
	char buffer[7] = "Hello!";//加上最后一个字节全0作为结束,该数组空间全部用完
	char* str = buffer;
	cout << "*str:" << *str << endl;//*str是字符指针变量的间接引用,输出H
	cout << "str:" << str << endl;//str是字符指针变量,输出字符指针就是输出字符串,从首地址开始,直到遇到0
	char strZero[7] = "H0llo!";
	char* strZerotest = strZero;//虽然字符串中间有0但还是全部输出了
	cout << "strZerotest:" << strZerotest << endl;
	cout << "\n";
	//由于C-串类型是字符指针,因此比较两个相同的C-串时,会因空间位置的不同而不同
	//而且,分别存储两个相同的C-串的字符数组,其数组比较也会是不相同的
	//下面的代码是C-串比较的错误方式
	cout << "C-串比较的错误方式\n";
	cout << ("join" == "join" ? "" : "not ") << "equal\n";//相等
	const char* str1 = "good";
	const char* str2 = "good";
	cout << (str1 == str2 ? "" : "not ") << "equal\n";//相等
	cout << "&str1:" << &str1 << "\n";//这两个字符串地址并不一样
	cout << "&str2:" << &str2 << "\n";//这两个字符串地址并不一样
	const char* stri1 = "good";
	const char* stri2 = stri1;
	cout << "&stri1:" << &stri1 << "\n";//这两个字符串地址也不一样
	cout << "&stri2:" << &stri2 << "\n";//这两个字符串地址也不一样
	char buffer1[6] = "Hello";
	char buffer2[6] = "Hello";
	cout << (buffer1 == buffer2 ? "" : "not ") << "equal\n";//不相等
	cout << "\n";
	//为了比较C_串的字典序大小,在C库函数中专门设计了C-串的比较函数strcmp
	cout << "C-串的比较函数\n";
	const char* str3 = str2;//意味着str2和str3共享空间,书上这样说,实际运行取地址并不一样,如下
	cout << "&str2:" << &str2 << "\n";//这两个字符串地址并不一样
	cout << "&str3:" << &str3 << "\n";//这两个字符串地址并不一样
	cout << "\n";
	//char buffer3[6] = buffer2;//数组无法复制,所以C库设计strcpy函数
	const char* s1 = "Hello ";
	const char* s2 = "1234";
	char a[20];
	strcpy_s(a,s1);//复制函数,将二参拷贝到一参的位置,返回一参首地址
	cout<<(strcmp(a,s1)==0 ? "":"not ")<< "equal\n";//比较函数,两者相等返回0,一参大于二参返回非0正数
	cout << strcat_s(a, s2) << endl;//连接函数,将二参连接到一参的后面,并返回连接后的一参的首地址
	cout << _strrev(a) << endl;//倒置函数,返回倒置后的字符串
	cout << _strset_s(a,'c') << endl;//设置函数,用二参替代掉一参的所有字符并返回替换字符后一参
	cout << (strstr(s1, "ell") ? "" : "not ") << "found\n";//查找串函数,找到返回1,未找到返回0
	cout << (strchr(s1, 'c') ? "" : "not ") << "found\n";//查找字符函数,找到返回1,未找到返回0
	cout << "\n";
	//使用无下划线的函数时会出现错误警告,因为内存空间不一样长会导致不可预料的结果
	//string类型时C++的STL提供的一种自定义的类型,可以方便地执行C-串所不能直接执行的一切操作
	//string类型处理空间占用问题时是自动的
	cout <<"string类型\n";
	string string1 = "Hello", string2 = "Hello";
	string string3 = "123";
	string3 += string2;//字符串拼接
	cout << (string1 == string2 ? "" : "not ") << "equal\n";
	cout << "&string1:" << &string1 << "\n";//这两个字符串地址并不一样
	cout << "&string2:" << &string2 << "\n";//这两个字符串地址并不一样
	reverse(string3.begin(), string3.end());
	cout << string3 << "\n";
	cout << string1.replace(0, 9, 9, 'c') << endl;//从下标0开始,长度是9的子串用9个c字符替代
	cout << (string2.find("ell") != -1 ? "" : "not ") << "found\n";
	cout << (string2.find('c') != -1 ? "" : "not ") << "found\n";
	cout << "\n";
	//string还可以有参数化的定义方式
	int x(35);
	string xx("Hello");
	string xxx(15,'H');//15个H
	cout << "string类型与C-串输入输出\n";
	//for (string s ;cin>>s; )//缓冲区读完且没有数据接续,流状态变为false
	//{
	//	cout << s;
	//}
	//cout << endl;
	//cin>>的读入方式总是将前导的空格/回车/制表符滤掉,将单词读入,遇到空格结束
	//如果一个文件StringType.txt有多行,每行若干个整数,要输出每行的和该怎么办
	//12 3 45 67 8 9
	//56 232 12 23
	//12 1
	//8
	//1212 2312
	//由于cin<<不能辨别空格和回车的区别,好的方法是使用string流
	//这一测试得到生成可执行文件夹下运行
	ifstream in("StringType.txt");//该文件在Debug文件夹下
	for (string s; getline(in, s);)//getline函数的返回是流状态,判断文件是否还有数据行可读
	{
		int a, sum = 0;
		for (istringstream sin(s); sin >> a; sum += a);//istringstream是输入string流,在sstream中说明
		//该语句类似文件流操作,不过哦创建sin流时,参数为string对象,是将string的实体看作时一个输入流
		//因而sin>>a即是从string流中输入整数到a中,一直输入到string中的最后一个整数
		cout << sum << endl;
	}
	getchar();
    return 0;
}

