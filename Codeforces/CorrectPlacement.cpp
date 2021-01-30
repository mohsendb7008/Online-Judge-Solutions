#include<bits/stdc++.h>
using namespace std;

struct rect{
    int id, w, h, fake;

    bool operator<(const rect& o) const{
        return this->w < o.w;
    }
};

const int maxn = 2e5 + 3;

int n, ans[maxn];
rect rects[2 * maxn];
set<pair<int, int>> heights;
vector<pair<int, int>> tmp;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int w, h;
        for(int i = 0; i < n; i++)
            cin >> w >> h, rects[i].id = i, rects[i].w = w, rects[i].h = h, rects[i].fake = 0;
        for(int i = 0; i < n; i++)
            rects[n + i].id = i, rects[n + i].w = rects[i].h, rects[n + i].h = rects[i].w, rects[n + i].fake = 1;
        sort(rects, rects + 2 * n);
        fill_n(ans, n, -1);
        heights.clear();
        tmp.clear();
        for(int i = 0; i < 2 * n; i++){
            if(i && rects[i].w > rects[i - 1].w){
                for(auto item : tmp)
                    heights.insert(item);
                tmp.clear();
            }
            if(!heights.empty() && heights.begin()->first < rects[i].h)
                ans[rects[i].id] = heights.begin()->second + 1;
            if(!rects[i].fake)
                tmp.push_back({rects[i].h, rects[i].id});
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}