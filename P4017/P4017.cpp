#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5005;
const long long MOD_NUM = 80112002;
//入度、出度数组
int inDegree[MAX_N], outDegree[MAX_N];
//vector数组，维护点与边的关系
vector <int> graph[MAX_N];
//dp数组表示到达该节点的路径数
int dp[MAX_N];

int main()
{
	int n, m;
	//每次输入的一组临时数据
	int a, b;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		//e.g 1 2 1->2构成一条边，1出度+1，2的入度+1
		inDegree[b] += 1;
		outDegree[a] += 1;
		//a->b构成一条边
		graph[a].push_back(b);
	}

	return 0;
}