//P1996约瑟夫问题
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int m, n, count = 1;
	queue <int> q;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		q.push(i);
	}
	while (true)
	{
		if (count == n)
		{
			cout << q.front() << " ";
			q.pop();
			if (q.size() == 0)
				break;
			count = 1;
		}
		q.push(q.front());
		q.pop();
		count += 1;
	}
	return 0;
}