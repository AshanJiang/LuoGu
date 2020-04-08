#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    }
    else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    }
    else if (T == 3) {
        int a = 14 / 4;
        cout << a << endl;
        cout << a * 4 << endl;
        cout << 14 - a * 4 << endl;
    }
    else if (T == 4) {
        cout << setprecision(6) << 500.0 / 3 << endl;
    }
    else if (T == 5) {
        cout << (260 + 220) / (12 + 20) << endl;
    }
    else if (T == 6) {
        cout << sqrt(6 * 6 + 9 * 9) << endl;
    }
    else if (T == 7) {
        int b = 100;
        b += 10;
        cout << b << endl;
        b -= 20;
        cout << b << endl;
        cout << 0 << endl;
    }
    else if (T == 8) {
        double pi = 3.141593;
        cout << pi * 10 << endl;
        cout << pi * 5 * 5 << endl;
        cout << 4.0 / 3 * pi * 5 * 5 * 5 << endl;
    }
    else if (T == 9) {
        cout << 22 << endl;
    }
    else if (T == 10) {
        cout << 9 << endl;
    }
    else if (T == 11) {
        cout << 100.0 / (8 - 5) << endl;
    }
    else if (T == 12) {
        cout << 13 << endl;
        cout << 'R' << endl;
    }
    else if (T == 13) {
        int pi = 3.141593;
        double volume = 4.0 / 3 * pi * 4 * 4 * 4;
        volume += 4.0 / 3 * pi * 10 * 10 * 10;
        cout << static_cast<int>(pow(volume, 1 / 3.0)) << endl;
    }
    else if (T == 14) {
        int a = 10;
        int res{};
        for (int i = 110; i > 0; i--)
        {
            if (i * (110 - i + a) == 3500) {
                res = i;
            }
        }
        cout << res << endl;
    }
    return 0;
}