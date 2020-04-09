#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	if (x <= 1)
		cout << "Today, I ate " << x << " apple.";
	else
		cout << "Today, I ate " << x << " apples.";
	return 0;
}