// HundredMoneyHundreChicken.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	for (size_t cock = 1; cock <= 13; cock++)
	{
		for (size_t hen = 1; hen <= 18; hen++)
		{
			for (size_t chick = 1; chick <= 96; chick++)
			{
				if (7 * cock + 5 * hen + chick / 3 - 100)
				{
					continue;
				}
				if (cock + hen + chick - 100)
				{
					continue;
				}
				if (chick % 3)
				{
					continue;
				}
				cout << "cock:" << cock << "hen:" << hen << "chick:" << chick << "\n";
			}
		}
	}
	//优化版
	for (size_t cock = 1; cock <= 13; cock++)
	{
		for (size_t hen = 1; hen <= 18; hen++)
		{
			if (7 * cock + 5 * hen + (100 - cock - hen) / 3 - 100)
			{
				continue;
			}
			if ((100 - cock - hen) % 3)
			{
				continue;
			}
			cout << "cock:" << cock << "hen:" << hen << "chick" << (100 - cock - hen) << "\n";
		}
	}
	//优化版
	for (size_t cock = 1; cock <= 13; cock++)
	{
		for (size_t hen = 1; hen <= 18; hen++)
		{
			if ((100 - cock - hen) % 3 == 0 && 7 * cock + 5 * hen + (100 - cock - hen) / 3 == 100)
			{
				cout << "cock:" << cock << "hen:" << hen << "chick" << (100 - cock - hen) << "\n";
			}
		}
	}
	//优化版
	for (size_t cock = 1; cock <= 13; cock++)
	{
		for (size_t hen = 1, chick = 99 - cock; hen <= 18; hen++, chick--)
		{
			if (chick % 3 == 0 && 7 * cock + 5 * hen + chick / 3 == 100)
			{
				cout << "cock:" << cock << "hen:" << hen << "chick" << (100 - cock - hen) << "\n";
			}
		}
	}
	return 0;
}
//对于逻辑判断的问题一般都要考虑全部的可能性,然后从这些可能性中按条件逐一排查直到最后获得某个结论
//百钱买百鸡问题:雄鸡7元1只,母鸡5元1只,小鸡1元3只,花100元钱买100只鸡
//如果雄鸡、母鸡和小鸡都必须有,则雄鸡、母鸡和小鸡应各买几只?
//考虑全部的可能性时先考虑雄鸡,母鸡和小鸡数的取值范围(当然也可以从金额着手)
//由于各种鸡都必须要有所以雄鸡的最高耗用金额为100-5-1=94元,取7的倍数,得91元
//所以雄鸡数范围为1~13,同理,母鸡数的范围为1~18,小鸡数的范围为3到96.注意小鸡数虽可以花100-7-5=88元钱买264只
//但由于总鸡数的限制小鸡数应<98