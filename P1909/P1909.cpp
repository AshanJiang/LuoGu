#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	int num, a, b, res = INT_MAX, tmp;
	cin >> num;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b;
		tmp = ceil(1.0 * num / a)* b;
		if (tmp < res)
			res = tmp;
	}
	cout << res;
	return 0;
}