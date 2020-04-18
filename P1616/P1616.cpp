//1616-疯狂的采药(完全背包)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//草药数组，每个数组元素存储采集时间[0]和价格[1]
vector <int> herbalList[10005];

int main()
{
	//T代表总共能够用来采药的时间，M代表山洞里的草药的数目
	//t代表这株草的采集时间，m代表这株草的价格
	int T, M, t, m;
	cin >> T >> M;
	int rowCount = M + 5;
	int colCount = 10000000 / M + 5;
	int **dp = new int*[rowCount];
	for (int i = 0; i < M + 5; ++i)
	{
		dp[i] = new int[colCount];
	}
	for (int i = 0; i < rowCount; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i < colCount; ++i)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> t >> m;
		herbalList[i].push_back(t);
		herbalList[i].push_back(m);
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (j < herbalList[i][0])
			{
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - herbalList[i][0]] + herbalList[i][1]);
			}
		}
	}
	cout << dp[M][T] << endl;
	return 0;
}