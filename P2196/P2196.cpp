#include <iostream>
#include <string>
using namespace std;

int maxBomb = 0;
//bomb:炸弹数,dpBomb:累计最大炸弹数,cellarRoute地窖路径
int bomb[25], dpBomb[25] = { 0 }, cellarRoute[25][25];
string dpRoute[25];
int n;
//获得id号地窖可挖到的最多地雷
int getMaxBomb(int id)
{
	if (dpBomb[id])
	{
		return dpBomb[id];
	}
	else
	{
		int max = 0;
		int max_i = 0;
		for (int i = id + 1; i <= n; i++)
		{
			if (cellarRoute[id][i])
			{
				int tmp = getMaxBomb(i);
				if (tmp > max)
				{
					max = tmp;
					max_i = i;
				}
			}
		}
		dpBomb[id] = bomb[id] + max;
		if (max == 0)
			dpRoute[id] += to_string(id);
		else
			dpRoute[id] += to_string(id) + ' ' + dpRoute[max_i];
		return dpBomb[id];
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> bomb[i];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> cellarRoute[i][j];
		}
	}
	int maxBomb = 0;
	//maxId代表要获得最多炸弹应该从几号地下室开挖
	int maxId = 0;
	for (int i = 1; i <= n; i++)
	{
		int tmp = getMaxBomb(i);
		if (tmp > maxBomb)
		{
			maxBomb = tmp;
			maxId = i;
		}
	}
	cout << dpRoute[maxId] << endl;
	cout << maxBomb;
	return 0;
}