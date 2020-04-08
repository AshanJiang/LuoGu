#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	float val;
	cin >> val;
	ostringstream ss;
	ss << val;
	string val_s = ss.str();
	reverse(val_s.begin(), val_s.end());
	cout << val_s << endl;
	return 0;
}