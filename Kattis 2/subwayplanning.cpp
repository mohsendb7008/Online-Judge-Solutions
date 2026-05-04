#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr double EPS = 1e-9;

enum EventType {
    START = 0,
    END = 1
};

struct Event {
    EventType type;
    int id;
    double angle;
    Event(const EventType t, const int i, const double a) : type(t), id(i) {
        angle = fmod(a + 2 * M_PI, 2 * M_PI);
    }
    bool operator<(const Event& o) const {
        if (fabs(angle - o.angle) > EPS)
            return angle < o.angle;
        return type < o.type;
    }
};

pair<double, double> computeInterval(const double x, const double y, const double d) {
    const double dist = sqrt(x * x + y * y);
    const double center = atan2(y, x);
    const double delta  = asin(d / dist);
    return {center - delta, center + delta};
}

int solveCase() {
    int n;
    double d;
    cin >> n >> d;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        if (x * x + y * y < d * d + EPS)
            continue;
        pair<double, double> interval = computeInterval(x, y, d);
        events.emplace_back(START, i, interval.first);
        events.emplace_back(END, i, interval.second);
    }
    sort(events.begin(), events.end());
    int best = n;
    for (int startIdx = 0; startIdx < events.size(); startIdx++) {
        vector<bool> active(n, false);
        vector<int> pending;
        int groups = 0;
        for (int i = 0; i < events.size(); i++) {
            const int idx = (startIdx + i) % static_cast<int>(events.size());
            const Event& e = events[idx];
            if (e.type == START) {
                active[e.id] = true;
                pending.push_back(e.id);
            } else {
                if (active[e.id]) {
                    groups++;
                    for (const int id : pending)
                        active[id] = false;
                    pending.clear();
                }
            }
        }
        groups += static_cast<int>(pending.size());
        best = min(best, groups);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        cout << solveCase() << endl;
    }
}