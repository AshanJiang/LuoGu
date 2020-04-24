#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string isbn;
    cin >> isbn;
    string isbnCopy = isbn;
    int checkCode{ 0 };
    isbnCopy.erase(remove(isbnCopy.begin(), isbnCopy.end(), '-'), isbnCopy.end());
    for (int i = 1; i <= 9; i++)
    {
        checkCode += (int)(isbnCopy[i - 1] - '0') * i;
    }
    checkCode %= 11;
    if (checkCode == 10) {
        if ('X' == isbnCopy.back())
        {
            cout << "Right";
        }
        else
        {
            isbn.back() = 'X';
            cout << isbn;
        }
    }
    else
    {
        if (checkCode == (int)(isbnCopy.back() - '0'))
        {
            cout << "Right";
        }
        else
        {
            isbn.back() = to_string(checkCode)[0];
            cout << isbn;
        }
    }
    return 0;
}