#include <iostream>
using namespace std;

int main()
{
	int a{}, b{}, c{}, d{};
	cin >> a >> b >> c >> d;
	int e{}, f{};
	int minutes = (c * 60 + d) - (a * 60 + b);
	e = minutes / 60;
	f = minutes % 60;
	cout << e << ' ' << f << endl;
	return 0;
}