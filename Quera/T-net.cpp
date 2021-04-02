#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e5 + 3;
int n;
num a, b;
num ans = 0;
int points[maxn];
vector<vector<int>> segs;

int main(){
    cin >> n >> a >> b;
    if(a > b)
        swap(a, b);
    for(int i = 0; i < n; i++)
        cin >> points[i];
    if(n == 1){
        cout << a << endl;
        return 0;
    }
    sort(points, points + n);
    for(int i = 0; i < n - 1; i++)
        if(points[i + 1] - points[i] > b){
            cout << -1 << endl;
            return 0;
        }
    ans = n * a;
    vector<int> v;
    v.push_back(points[0]);
    segs.push_back(v);
    for(int i = 1; i < n; i++){
        if(points[i] - points[i - 1] > a){
            vector<int> v;
            v.push_back(points[i]);
            segs.push_back(v);
        }
        else
            segs.back().push_back(points[i]);
    }
    if(segs.size() == 1){
        cout << ans << endl;
        return 0;
    }
    ans += b - a;
    int endd = segs[0].back() + b;
    for(int i = 1; i < segs.size(); i++){
        if(endd >= segs[i].back())
            ans += b - a, endd = segs[i].back() + b;
        else{
            int end_seg;
            for(int p : segs[i])
                if(p <= endd)
                    end_seg = p;
            if(i < segs.size() - 1 && end_seg + b < segs[i + 1][0])
                end_seg = segs[i].back(), ans += b - a;
            ans += b - a;
            endd = end_seg + b;
        }
    }
    cout << ans << endl;
}