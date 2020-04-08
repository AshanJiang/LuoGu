#include <iostream>

using namespace std;

int main()
{
	int a{}, b{};
	cin >> a >> b;
	int cents = a * 10 + b;
	cout << cents / 19 << endl;
	return 0;
}