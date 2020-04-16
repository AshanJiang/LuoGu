//1048-采药(背包)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//草药数组，每个数组元素存储采集时间[0]和价格[1]
vector <int> herbalList[105];
//dp行代表前i件物品，列代表背包容量,值代表取得的最大收益
int dp[105][1005];

int main()
{
	//T代表总共能够用来采药的时间，M代表山洞里的草药的数目
	//t代表这株草的采集时间，m代表这株草的价格
	int T, M, t, m;
	cin >> T >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> t >> m;
		herbalList[i].push_back(t);
		herbalList[i].push_back(m);
	}
	//基本0-1背包
	//i代表前i件物品
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			//j代表背包容量(采集时间)
			if (j < herbalList[i][0]) //放不下,这个物品一定不拿，对于dp数组，i=0行和j=0列都全为0
			{
				dp[i][j] = dp[i - 1][j];
				continue;
			}
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - herbalList[i][0]] + herbalList[i][1]);
		}
	}
	cout << dp[M][T] << endl;
	return 0;
}