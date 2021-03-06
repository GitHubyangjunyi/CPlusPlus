// MazeProblem.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;
//下面考虑一个陷入迷宫的老鼠如何找到出口的问题
//老鼠希望系统性地尝试所有的路径之后走出迷宫,如果到达死胡同,将原路返回至上一个位置并尝试新的路径
//在每个位置,老鼠可以向4个方向运动:上/下/左/右,无论它离出口处有多近,它总是按照这样的顺序尝试
//这样就可能会产生不必要的迂回,当到达一个死胡同之后,允许将重新搜索的信息保存起来
//老鼠使用一种称为"回溯"的方法
//迷宫是用一个二维字符数组实现的,通路以0表示,墙以1表示,出口位置以e表示,老鼠的初始位置以m表示
//在这个程序中,迷宫问题被一般化为允许出口在迷宫的任何位置(如果用图表示就好像有部电梯可以带着老鼠离开)
//允许通道在边界线上,为了避免老鼠到达边界线上的一个空单元而继续搜索路径时脱离整个数组
//需要不断地判断老鼠是否在边界线上,为此,程序自动地在用户输入的迷宫周围加上一层以1表示的框架
//
//
//		+---+-----+				11111111111
//		|     |   |				10000010001
//		| |   | | |				10100010101
//		E |     | |				E0100000101
//		| +-+-- | |				10111110101
//		| | |   | |				10101000101
//		|   | |   |				10001010001
//		|-+-+ |   |				11111010001
//		| |M| |   |				101M1010001
//		|     |   |				10000010001
//		+-----+---+				11111111111
//
//
//程序使用了两个栈,一个栈来初始化迷宫,另一个用来实现回溯
//在用户输入迷宫时,一次输入一行,用户输入的迷宫可以包含任意个行和任意个列
//程序仅有的假设是所有行的长度相同,并且只能由任意个1/任意个0/一个e/一个m组成
//按照用户输入的顺序将行数据放进栈mazeRows中,并在开始和结尾处各加上一个1
//等到所有的行都输入完毕,数组的大小就确定了,然后将栈中的各行数据转移到数组中
//的假设是所有行的长度相同，并且只能由任意个1、任意个O.个e.个m组成按照用户输入的顺序将行数据放进栈mazeRows 中，并在开始和结尾处各加上个1.等到所有的行都输入完毕后，数组的大小就确定了，然后将栈中的各行数据转移到数组中。
//第二个栈mazeStack在走出迷宫的过程中使用,为了记住没有尝试过的路径,以供后续的尝试
//需要将当前位置未尝试过的邻近位置(如果存在的话)存放到栈中
//并按照相同的顺序存储:先上边,再下边,其次左边,最后右边
//将进口放入栈中之后,老鼠位于栈项元素位置,测试第一个保存的未测试的邻近单元
//然后测试最上面的位置,以此类推,直至到达出口,或者尝试过了所有的路径发现没有出口
//为了避免因为尝试已走过的路径所带来的无限循环,每个访问过的单元都以句号作为标记
//下面是走出迷宫算法的伪代码
//				初始化栈exitCell, entryCell, currentCell = entryCell;
//				while currentCell 不是 exitCell
//					标记currentCell 为已访问过;
//					将currentCell 未访问过的邻近位置放进栈;
//					if 栈为空
//						失败;
//					else 从栈中弹出个单元,作为currentCell;
//				完成;

//栈中存放的是单元位置的坐标,可以使用两个整数栈来存放x和y坐标
//另一种方法是使用一个整数栈,利用移位操作把两个坐标存放在一个整型变量中
//在程序下面的程序中,类MazeCell中使用了两个数据成员x和y,这样可以用一个mazeStack类存放MazeCell对象
//下图示例,这个程序实际上输出了老鼠每步动作后的迷宫
//
//
//			|		 |	|		 |	|		 |	|		 |	|		 |	| (2  4) |	|		 |
//			|		 |	| (3  1) |	| (2  1) |	| (2  2) |	| (2  3) |	| (1  3) |	| (1  3) |
//栈		| (3  2) |	| (2  2) |	| (2  2) |	| (2  2) |	| (2  2) |	| (2  2) |	| (2  2) |
//			| (2  3) |	| (2  3) |	| (2  3) |	| (2  3) |	| (2  3) |	| (2  3) |	| (2  3) |
//			----------	----------	----------	----------	----------	----------	----------
//
//currentCell:(3 3)		  (3 2) 	  (3 1)		  (2 1)		  (2 2)	   	   (2 3)	  (2 4)
//
//迷宫
//			 111111		  111111	  111111	  111111	  111111	  111111	  111111
//			 111001		  111001	  111001	  111001	  111001	  111001	  111001
//			 1000E1		  1000E1	  1000E1	  1.00E1	  1..0E1	  1...E1	  1...E1
//			 100M11		  10.M11	  1..M11	  1..M11	  1..M11	  1..M11	  1..M11
//			 111111		  111111	  111111	  111111	  111111	  111111	  111111
//			   a			b			c			d			e			f			g
//
//用户输入迷宫后,立即被围上一层框架
//	1100		111111
//	000E		111001
//	00M1		1000E1
//				100M11
//				111111
//将entryCell和currentCell初始化为(3 3),exitCell初始化为(2 4)
//(1)因为currentCell不等于exitCell所以对当前单元(3 3)邻近的4个单元进行测试
//其中只有两个单元(3 2)和(2 3)可以作为新的当前位置,所以将这两个单元放到栈中
//判断栈中是否含有位置单元,如果不为空,则栈顶元素(3 2)变成当前单元
//(2)currentCell仍然不等于exitCell,,因此将从(3 2)可以到达的两个单元(2 2)和(3 1)放进栈
//注意老鼠所在的单元并不在栈中,将当前的单元标记为已访问后,迷宫中的情况
//现在,将栈顶元素(3 1)从栈中弹出,作为currentCell的值,这过程继续,直到到达出口

template<class T>class Stack :public stack<T>
{
public:
	T pop()
	{
		T temp = top();
		stack<T>::pop();
		return temp;
	}
};

class Cell
{
private:
	int x, y;
	friend class Maze;
public:
	Cell(int i = 0, int j = 0)
	{
		x = i;
		y = j;
	}
	bool operator ==(const Cell& c)const
	{
		return x == c.x && y == c.y;
	}
};

class Maze
{
private:
	int rows, cols;
	Cell currentCell, exitCell, entryCell;
	const char exitMarker, entryMarker, visited, passage, wall;
	Stack<Cell> mazeStack;
	char **store;
	void pushUnvisited(int, int);
	friend ostream& operator<<(ostream&, const Maze&);
public:
	Maze();
	void exitMaze();
};
Maze::Maze() :exitMarker('e'), entryMarker('m'), visited('.'), passage('0'), wall('1')
{
	Stack<char*> mazeRows;
	char str[80], *s;
	int col, row = 0;
	cout << "Enter a rectangular maze using the following "
		<< "characters:\nm - entry\ne - exit\n1 - wall\n0 - passage\n"
		<< "Enter one line at time;end with Ctrl-z:\n";
	while (cin>>str)
	{
		row++;
		cols = strlen(str);
		s = new char[cols + 3];
		mazeRows.push(s);
		strcpy(s + 1, str);
		s[0] = s[cols + 1] = wall;
		s[cols + 2] = '\0';
		if (strchr(s,exitMarker)!=0)
		{
			exitCell.x = row;
			exitCell.y = strchr(s, exitMarker) - s;
		}
		if (strchr(s, entryMarker) != 0)
		{
			entryCell.x = row;
			entryCell.y = strchr(s, entryMarker) - s;
		}
	}
	rows = row;
	store = new char*[rows + 2];
	store[0] = new char[cols + 3];
	for (; !mazeRows.empty(); row--)
	{
		store[row] = mazeRows.pop();
	}
	store[row + 1] = new char[cols + 3];
	store[0][cols + 2] = store[row + 1][cols + 2] = '\0';
	for (col=0; col <= cols+1; col++)
	{
		store[0][col] = wall;
		store[rows + 1][col] = wall;
	}
}
void Maze::pushUnvisited(int row, int col)
{
	if (store[row][col]==passage || store[row][col] == exitMarker)
	{
		mazeStack.push(Cell(row, col));
	}
}
void Maze::exitMaze()
{
	int row, col;
	currentCell = entryCell;
	while (!(currentCell==exitCell))
	{
		row = currentCell.x;
		col = currentCell.y;
		cout << *this;
		if (!(currentCell==entryCell))
		{
			store[row][col] = visited;
		}
		pushUnvisited(row - 1, col);
		pushUnvisited(row + 1, col);
		pushUnvisited(row, col - 1);
		pushUnvisited(row, col + 1);
		if (mazeStack.empty())
		{
			cout << *this;
			cout << "Failure\n";
			return;
		}
		else
		{
			currentCell = mazeStack.pop();
		}
	}
	cout << *this;
	cout << "Success\n";
}
ostream& operator<<(ostream& out, const Maze& maze)
{
	for (int row = 0; row <=maze.rows+1; row++)
	{
		out << maze.store[row] << endl;
	}
	out << endl;
	return out;
}
int main()
{
	Maze().exitMaze();
    return 0;
}

