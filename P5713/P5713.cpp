#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int local = 5 * n;
	int luogu = 11 + 3 * n;
	if (local < luogu)
		cout << "Local";
	else
		cout << "Luogu";
	return 0;
}