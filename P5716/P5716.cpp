﻿#include <iostream>

using namespace std;

bool isLeapYear(int y) {
	if (y % 100 == 0) {
		if (y % 400 == 0)
			return true;
		else
			return false;
	}
	else if (y % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	int y, m;
	cin >> y >> m;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		cout << 31;
	}
	else {
		if (m == 2)
		{
			if (isLeapYear(y))
			{
				cout << 29;
			}
			else {
				cout << 28;
			}
		}
		else {
			cout << 30;
		}
	}
	return 0;
}