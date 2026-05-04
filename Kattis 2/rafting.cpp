#include "lineSegment.cpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(10);
    int tc;
    cin >> tc;
    while (tc--) {
        int ni, no;
        vector<point2D<double>> inner, outer;
        cin >> ni;
        while (ni--) {
            double x, y;
            cin >> x >> y;
            inner.emplace_back(x, y);
        }
        cin >> no;
        while (no--) {
            double x, y;
            cin >> x >> y;
            outer.emplace_back(x, y);
        }
        double ans = 1e18;
        for (int i = 0; i < inner.size(); i++) {
            lineSegment l1(inner[i], inner[(i + 1) % inner.size()]);
            for (int j = 0; j < outer.size(); j++) {
                lineSegment l2(outer[j], outer[(j + 1) % outer.size()]);
                ans = min(ans, l1.distance(l2) / 2.0);
            }
        }
        cout << ans << endl;
    }
}