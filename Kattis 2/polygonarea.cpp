#include "polygon.cpp"
#include <iostream>

using namespace std;

vector<point2D<int>> p;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (!n)
            break;
        p.clear();
        while (n--) {
            int x, y;
            cin >> x >> y;
            p.emplace_back(x, y);
        }
        polygon<int> poly = p;
        int ans = poly.SignedDoubledArea();
        if (ans > 0) {
            cout << "CCW ";
        }
        else {
            cout << "CW ";
            ans *= -1;
        }
        cout << ans / 2 << (ans % 2 ? ".5" : ".0") << endl;
    }
}