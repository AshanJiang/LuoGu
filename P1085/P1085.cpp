#include <iostream>

using namespace std;

int main()
{
	int a, b, res{ 0 };
	for (int i = 1; i <= 7; i++)
	{
		cin >> a >> b;
		if (a + b > 8)
		{
			if(res==0)
				res = i;
		}
	}
	cout << res;
	return 0;
}