#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int m{}, t{}, s{};
	cin >> m >> t >> s;
	int res = m - ceil(1.0 * s / t);
	if (res > 0) {
		cout << res << endl;
	}
	else {
		cout << 0 << endl;
	}
	return 0;
}