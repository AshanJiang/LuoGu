#include <iostream>
#include <algorithm>

using namespace std;

int r, c, maxLength{ 0 };
static int heightArr[105][105];
//dp[i][j]存储到(i,j)这个点对应的最长长度值
static int dp[105][105];

//获得(i,j)点最长路径长度
int getDp(int i, int j)
{
	//越界
	if (i < 1 || j < 1)
		return 1;
	if (i > r || j > c)
		return 1;
	
	if (dp[i][j] > 0) {
		return dp[i][j];
	}
	else {
		int top{ 0 }, left{ 0 }, down{ 0 }, right{ 0 };
		//上
		if (heightArr[i - 1][j] > heightArr[i][j])
		{
			top = 1 + getDp(i - 1, j);
		}
		//左
		if (heightArr[i][j-1] > heightArr[i][j])
		{
			left = 1 + getDp(i, j - 1);
		}
		//下
		if (heightArr[i + 1][j] > heightArr[i][j])
		{
			down = 1 + getDp(i + 1, j);
		}
		//右
		if (heightArr[i][j + 1] > heightArr[i][j])
		{
			right = 1 + getDp(i, j + 1);
		}
		dp[i][j] = max(max(top, down), max(left, right));
		if (dp[i][j] > maxLength)
			maxLength = dp[i][j];
		return dp[i][j];
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++) 
		{
			cin >> heightArr[i][j];
		}
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			getDp(i, j);
		}
	}
	cout << maxLength + 1 << endl;
	return 0;
}
