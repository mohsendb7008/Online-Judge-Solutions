#include "iostream"
#include <vector>
#include <cmath>

using namespace std;

constexpr double EPS = 1e-9;
constexpr double INF = 1e18;

struct Boat {
    double x, y;
    double vx, vy;
};

double earliest_collision(const vector<Boat>& boats, const double r) {
    const double r2 = r * r;
    double best = INF;
    const int n = static_cast<int>(boats.size());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            const double dx = boats[i].x - boats[j].x;
            const double dy = boats[i].y - boats[j].y;
            const double dvx = boats[i].vx - boats[j].vx;
            const double dvy = boats[i].vy - boats[j].vy;
            const double A = dvx * dvx + dvy * dvy;
            const double B = 2.0 * (dx * dvx + dy * dvy);
            const double C = dx * dx + dy * dy - r2;
            if (C < EPS) {
                return 0.0;
            }
            if (fabs(A) < EPS) {
                continue;
            }
            const double D = B * B - 4 * A * C;
            if (D <= -EPS) {
                continue;
            }
            const double t1 = (-B - sqrt(D)) / (2 * A);
            const double t2 = (-B + sqrt(D)) / (2 * A);
            if (t2 <= -EPS)
                continue;
            best = min(best, max(t1, 0.0));
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        double r;
        cin >> n >> r;
        vector<Boat> boats(n);
        for (int i = 0; i < n; i++) {
            double x, y, deg, v;
            cin >> x >> y >> deg >> v;
            const double rad = deg * M_PI / 180.0;
            const double vx = v * sin(rad);
            const double vy = v * cos(rad);
            boats[i] = {x, y, vx, vy};
        }
        const double ans = earliest_collision(boats, r);
        if (fabs(ans - INF) < EPS) {
            cout << "No collision." << endl;
        } else {
            cout << lround(ans) << endl;
        }
    }
    return 0;
}