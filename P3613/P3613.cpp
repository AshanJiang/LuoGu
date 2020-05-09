#include <iostream>
#include <map>

using namespace std;

map <int, map<int, int> > locker;

int main()
{
	int n, q, a, b, c, d;
	//第一行2个整数n和q，寄包柜个数和询问次数。
	cin >> n >> q;
	for (int i = 0; i < q; i++)
	{
		cin >> a;
		if(a==1)
		{
			cin >> b >> c >> d;
			locker[b][c] = d;
		}
		else
		{
			cin >> b >> c;
			cout << locker[b][c] << '\n';
		}
	}
	return 0;
}