//P1802 五倍经验日（还是01背包）
#include <iostream>
#include <algorithm>

using namespace std;

int win[1005], lose[1005], use[1005];
int dp[1005][1005];

int main()
{
	int n, x;
	cin >> n >> x;
	int a, b, c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		lose[i] = a;
		win[i] = b;
		use[i] = c;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (j < use[i]) //药不够，直接落败
			{
				dp[i][j] = dp[i - 1][j] + lose[i];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j] + lose[i], dp[i - 1][j - use[i]] + win[i]);
			}
		}
	}

	cout << 5ll * dp[n][x] << endl;

	return 0;
}