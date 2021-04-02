#include <bits/stdc++.h>
using namespace std;

// The Closest Pair Problem

int n;
pair<double, double> points[10003];
pair<double, double> tmp[10003];

inline double dis(const pair<double, double>& p1, const pair<double, double>& p2){
    double deltax = p1.first - p2.first;
    double deltay = p1.second - p2.second;
    return sqrt(deltax * deltax + deltay * deltay);
}

bool byX(const pair<double, double>& p1, const pair<double, double>& p2){
    return p1.first < p2.first;
}

bool byY(const pair<double, double>& p1, const pair<double, double>& p2){
    return p1.second < p2.second;
}

double closest(int left, int right){
    if(right == left)
        return INT_MAX;
    if(right - left == 1)
        return dis(points[left], points[right]);
    if(right - left == 2)
        return min(dis(points[left], points[left+1]), min(dis(points[left], points[right]), dis(points[right-1], points[right])));
    int mid = (left + right) / 2;
    double d = min(closest(left, mid), closest(mid+1, right));
    auto lptr = lower_bound(points+left, points+mid+1, make_pair(points[mid].first-d, 0.0), byX);
    auto rptr = upper_bound(points+mid+1, points+right+1, make_pair(points[mid+1].first+d, 0.0), byX);
    int size = rptr - lptr;
    copy(lptr, rptr, tmp);
    sort(tmp, tmp+size, byY);
    for(int i = 0; i < size; i++)
        for(int j = i+1; j < min(i+16, size); j++)
            d = min(d, dis(tmp[i], tmp[j]));
    return d;
}

int main(){
    cout << fixed << setprecision(4);
    while(10245){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> points[i].first >> points[i].second;
        sort(points, points+n);
        double ans = closest(0, n-1);
        if(ans >= 10000.0)
            cout << "INFINITY" << endl;
        else cout << ans << endl;
    }
}