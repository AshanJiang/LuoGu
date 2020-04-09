#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	//f表示到(i,j)点路径的最大值,m表示存储的数据
	static int f[1005][1005], m[1005][1005];
	int r{};
	cin >> r;
	//读入数据
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> m[i][j];
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + m[i][j];
		}
	}
	int maxSum = -1;
	for (int i = 1; i <= r; i++) {
		maxSum = max(f[r][i], maxSum);
	}
	cout << maxSum;
	return 0;
}