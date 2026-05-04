#include "polygon.cpp"
#include <iostream>

using namespace std;

vector<point2D<int>> p;

int main() {
    int n, m;
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
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            const PointStatus ans = poly.status({x, y});
            if (ans == IN)
                cout << "in" << endl;
            if (ans == ON)
                cout << "on" << endl;
            if (ans == OUT)
                cout << "out" << endl;
        }
    }
}