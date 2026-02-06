#include <iostream>
using namespace std;

#define num long long int

int main() {
    num s, p, y, j;
    while (cin >> s >> p >> y >> j) {
        bool flag = true;
        for (int a = 0; flag && a <= 1; a++) {
            for (int b = 0; flag && b <= 1; b++) {
                for (int c = 0; c <= 1; c++) {
                    num s2 = s + a;
                    num p2 = p + b;
                    num y2 = y + c;

                    num Y = (12 + j - p2 - y2) / 3;

                    if (Y < 0)
                        continue;

                    num P = Y + p2;
                    num S = Y + y2;

                    if (S == P + s2 && S + P + Y == 12 + j) {
                        cout << S << " " << P << " " << Y << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
}