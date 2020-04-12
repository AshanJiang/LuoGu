#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5100;
const long long MOD_NUM = 80112002;
//入度、出度数组
int inDegree[MAX_N], outDegree[MAX_N];
//vector数组，维护点与边的关系
vector <int> graph[MAX_N];
//dp数组表示到达该节点的路径数
int dp[MAX_N];

int main()
{
	//表示生物种类n和吃与被吃的关系数m
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
	int i = 1, deleteNum = 0;
	long long res = 0;
	while (true)
	{
		if (deleteNum == n)
			break;
		//拓扑排序
		if (inDegree[i] == 0)
		{
			//初始入度为0的点要置为1
			if (dp[i] == 0)
			{
				dp[i] = 1;
			}
			for (size_t j = 0; j < graph[i].size(); j++)
			{
				dp[graph[i][j]] += dp[i];
				//可能会爆掉，在这需要取模
				dp[graph[i][j]] %= MOD_NUM;
				//删边
				inDegree[graph[i][j]] -= 1;
			}
			if (outDegree[i] == 0)
			{
				//终极消费者,注：可能有多个不相关的食物网
				res = (res + dp[i]) % MOD_NUM;
			}
			//删点(只需要让入度变为-1就行，因为每次只找入度为0的点)
			//删点后要重新搜索
			inDegree[i] = -1;
			i = 1;
			deleteNum += 1;
			continue;
		}
		i += 1;
	}
	cout << res << endl;
	return 0;
}