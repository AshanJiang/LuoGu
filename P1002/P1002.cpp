//P1002过河卒
#include <iostream>

using namespace std;
//存储到[x][y]这个点的路径数
unsigned long long dp[25][25];
//存储[x][y]是否被控制
bool controlPoint[25][25];
//马对应的路线
int controlX[] = { 0,1,1,2,2,-1,-1,-2,-2 };
int controlY[] = { 0,-2,2,-1,1,-2,2,-1,1 };
int main()
{
	//一行四个正整数，分别表示B点坐标和马C的坐标。
	int bx, by, cx, cy;
	cin >> bx >> by >> cx >> cy;
	int conX, conY;
	//控制点
	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			conX = cx + controlX[i];
			conY = cy + controlY[i];
			if (conX >= 0 && conY >= 0) 
			{
				controlPoint[conX][conY] = true;
				//马落到边上，还会让边上这个点后的所有点被控制
				if (conX == 0) 
				{
					for (int i = conY + 1; i <= by; i++)
					{
						controlPoint[0][i] = true;
					}
				}
				if (conY == 0)
				{
					for (int i = conX + 1; i <= bx; i++)
					{
						controlPoint[i][0] = true;
					}
				}
			}
		}
	}
	//注意到dp(x,0)=1且dp(0,y)=1就有了初始值，而dp(i,j)=dp(i-1,j)+dp(i,j-1)
	//由于卒只可以向下或向右，所以只要向上向左逆推就可以了
	for (int i = 0; i <= bx; i++)
	{
		for (int j = 0; j <= by; j++)
		{
			if (controlPoint[i][j])
			{
				continue;
			}
			else
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
	}
	cout << dp[bx][by];
	return 0;
}