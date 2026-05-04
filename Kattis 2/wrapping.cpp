#include "convexHull.cpp"
#include "polygon.cpp"
#include "iostream"
#include "iomanip"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        double totalArea = 0.0;
        vector<point2D<double>> allPoints;
        for (int i = 0; i < n; i++) {
            double cx, cy, w, h, angle;
            cin >> cx >> cy >> w >> h >> angle;
            totalArea += w * h;
            const double theta = -angle * M_PI / 180.0;
            double hw = w / 2.0;
            double hh = h / 2.0;
            vector<point2D<double>> local = {
                {-hw, -hh},
                { hw, -hh},
                { hw,  hh},
                {-hw,  hh}
            };
            for (const point2D<double> &p : local) {
                const double x = p.x;
                const double y = p.y;
                const double xr = x * cos(theta) - y * sin(theta);
                const double yr = x * sin(theta) + y * cos(theta);
                allPoints.emplace_back(cx + xr, cy + yr);
            }
        }
        const vector<point2D<double>> hull = ConvexHull<double>::get(allPoints);
        polygon<double> poly(hull);
        const double ans = totalArea / poly.Area() * 100.0;
        cout << ans << " %" << endl;
    }
}