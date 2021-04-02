#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

#define num long long int

int n;
num k, h[maxn], p[maxn];
pair<num, int> heights[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        fill_n(p, n, -1);
        for(int i = 0; i < n; i++)
            heights[i] = {h[i], i};
        sort(heights, heights + n);
        for(int i = n - 1; i >= 0; i--){
            int index = heights[i].second;
            num place = heights[i].first + 1;
            if(index && p[index - 1] != -1)
                place = max(place, p[index - 1] - k + 1);
            if(index < n - 1 && p[index + 1] != -1)
                place = max(place, p[index + 1] - k + 1);
            p[index] = place;
        }
        bool ans = 1;
        for(int i = 0; i < n; i++)
            if(p[i] - h[i] - 1 >= k){
                ans = 0;
                break;
            }
        if(p[0] != h[0] + 1)
            ans = 0;
        if(p[n - 1] != h[n - 1] + 1)
            ans = 0;
        cout << (ans ? "YES" : "NO") << endl;
    }
}
