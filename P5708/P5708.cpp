#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double a{}, b{}, c{};
	cin >> a >> b >> c;
	double p = 0.5 * (a + b + c);
	cout << fixed << setprecision(1) << sqrt(p * (p - a) * (p - b) * (p - c)) << endl;
	return 0;
}