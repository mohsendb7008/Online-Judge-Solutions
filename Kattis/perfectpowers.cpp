#include <iostream>
using namespace std;

#define num long long int

int main() {
    num x;
    while (true) {
        cin >> x;
        if (!x)
            break;
        bool neg = false;
        if (x < 0) {
            x = -x;
            neg = true;
        }
        num p = 1;
        for (num b = 2; b * b <= x; b++) {
            if (!(x % b)) {
                num c = 0;
                num y = x;
                while (!(y % b)) {
                    c++;
                    y /= b;
                }
                if (y == 1 && (!neg || c % 2)) {
                    p = max(p, c);
                }
            }
        }
        cout << p << endl;
    }
}