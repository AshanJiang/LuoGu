#include <iostream>

using namespace std;

int main()
{
	bool nature1 = false, nature2 = false;
	int x;
	cin >> x;
	if (x % 2 == 0)
		nature1 = true;
	if (x > 4 && x <= 12)
		nature2 = true;
	if (nature1 && nature2)
		cout << "1 ";
	else
		cout << "0 ";
	if (nature1 || nature2)
		cout << "1 ";
	else
		cout << "0 ";
	if (nature1 && !nature2 || !nature1 && nature2)
		cout << "1 ";
	else
		cout << "0 ";
	if (!nature1 && !nature2)
		cout << "1";
	else
		cout << "0";
	return 0;
}