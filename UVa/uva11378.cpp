#include <bits/stdc++.h>
using namespace std;

// Bey Battle

int n;
pair<int, int> points[100003];
pair<int, int> tmp[100003];

inline int dis(const pair<int, int>& p1, const pair<int, int>& p2){
    return max(abs(p1.first-p2.first), abs(p1.second-p2.second));
}

bool byX(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.first < p2.first;
}

bool byY(const pair<int, int>& p1, const pair<int, int>& p2){
    return p1.second < p2.second;
}

int closest(int left, int right){
    if(right == left)
        return INT_MAX;
    if(right - left == 1)
        return dis(points[left], points[right]);
    if(right - left == 2)
        return min(dis(points[left], points[left+1]), min(dis(points[left], points[right]), dis(points[right-1], points[right])));
    int mid = (left + right) / 2;
    int d = min(closest(left, mid), closest(mid+1, right));
    auto lptr = lower_bound(points+left, points+mid+1, make_pair(points[mid].first-d, 0), byX);
    auto rptr = upper_bound(points+mid+1, points+right+1, make_pair(points[mid+1].first+d, 0), byX);
    int size = rptr - lptr;
    copy(lptr, rptr, tmp);
    sort(tmp, tmp+size, byY);
    for(int i = 0; i < size; i++)
        for(int j = i+1; j < min(i+16, size); j++)
            d = min(d, dis(tmp[i], tmp[j]));
    return d;
}

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> points[i].first >> points[i].second;
        sort(points, points+n);
        double ans = closest(0, n-1);
        cout << ans << endl;
    }
}