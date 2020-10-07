#include <bits/stdc++.h>
using namespace std;

// Imperfect GPS

int n, k, x[103], y[103], t[103];
vector<int> gps;
vector<pair<double, double>> points;

double dis(double x1, double y1, double x2, double y2){
    double dx = x1 - x2, dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> t[i];
    double real = 0;
    for(int i = 0; i < n-1; i++)
        real += dis(x[i], y[i], x[i+1], y[i+1]);
    gps.push_back(0);
    int s = k;
    while(s < t[n-1])
        gps.push_back(s), s+= k;
    gps.push_back(t[n-1]);
    for(int s : gps){
        int lo = lower_bound(t, t + n, s) - t;
        int hi = upper_bound(t, t + n, s) - t;
        if(lo == hi){
            double dx = x[lo] - x[lo-1], dy = y[lo] - y[lo-1];
            double f = double(s - t[lo-1]) / (t[lo] - t[lo-1]);
            points.push_back({x[lo-1] + f * dx, y[lo-1] + f * dy});
        }
        else
            points.push_back({x[lo], y[lo]});
    }
    double estimated = 0;
    for(int i = 0; i < points.size()-1; i++)
        estimated += dis(points[i].first, points[i].second, points[i+1].first, points[i+1].second);
    cout << fixed << setprecision(6) << (real - estimated) * 100 / real << endl;
}