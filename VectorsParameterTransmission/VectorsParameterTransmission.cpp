// VectorsParameterTransmission.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
//还有错误未排除
typedef vector<int> VI;
typedef vector<VI> VVI;
void printf(const VI&);
void input(VVI& m);
bool findVector(const VVI& matrix, VI& v);

int main()
{
	VVI matrix;
	input(matrix);
	VI vec;
	if (findVector(matrix,vec))
	{
		printf(vec);
	}
    return 0;
}

void printf(const VI& v)
{
	for (int i = 0; (unsigned)i < v.size(); i++)
	{
		cout << v[i] << "  ";
		cout << "\n";
	}
}

void input(VVI& m)
{
	ifstream in("VectorsParameterTransmission.in");
	int n, t;
	in >> n;
	m.resize(n);
	for (string s ;n-- && getline(in , s); )
	{
		for (istringstream sin(s); sin >> t; m[m.size() - n - 1].push_back(t));
	}
}

bool findVector(const VVI& matrix, VI& v)
{
	for (int i = 0; (unsigned)i < matrix.size(); i++)
	{
		for (int j = 0; (unsigned)j < matrix[i].size(); j++)
		{
			if (matrix[i][j]==-1)
			{
				v = matrix[i];
				return true;
			}
		}
	}
	return false;
}

//8
//12 35 77 45
//1 2 3 4 5 67 9
//12 11 8 9 0
//1 - 11
//2 3 4 5 6 7 8 9 0 - 4 - 5 - 1
//5 4 3 2 1 6 7
//13 34 56 78 99 98
//11 111 11 11 11