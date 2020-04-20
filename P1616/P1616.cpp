//1616-疯狂的采药(完全背包)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//草药数组，每个数组元素存储采集时间[0]和价格[1]
vector <int> herbalList[10005];
//int dp[105][105];
int dp2[10000005];

//void fun1() //未优化空间
//{
//	//T代表总共能够用来采药的时间，M代表山洞里的草药的数目
//	//t代表这株草的采集时间，m代表这株草的价格
//	int T, M, t, m;
//	cin >> T >> M;
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> t >> m;
//		herbalList[i].push_back(t);
//		herbalList[i].push_back(m);
//	}
//
//	for (int i = 1; i <= M; i++)
//	{
//		for (int j = 1; j <= T; j++)
//		{
//			if (j < herbalList[i][0])
//			{
//				dp[i][j] = dp[i - 1][j];
//			}
//			else {
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - herbalList[i][0]] + herbalList[i][1]);
//			}
//			//cout << "[" << i << "]" << "[" << j << "]=" << dp[i][j] << endl;
//		}
//	}
//
//	cout << dp[M][T] << endl;
//}

int main()
{
	//优化为一维，dp[j] = max(f[j], f[j-C[i]]+W[i])，其中C为耗费，W为价值
	int T, M, t, m;
	cin >> T >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> t >> m;
		herbalList[i].push_back(t);
		herbalList[i].push_back(m);
	}
	for (int i = 1; i <= M; i++)
	{
		for (int j = herbalList[i][0]; j <= T; j++)
		{
			dp2[j] = max(dp2[j], dp2[j - herbalList[i][0]] + herbalList[i][1]);
		}
	}
	cout << dp2[T];
	return 0;
}