#include <iostream>
#include <cctype>
using namespace std;

int main() {
	char ch;
	cin >> ch;
	cout << static_cast<char>(toupper(ch));
	return 0;
}