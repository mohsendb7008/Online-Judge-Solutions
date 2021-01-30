#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n;
pair<int, int> blocked[maxn];
vector<pair<int, int>> segment;

inline bool solve(){
    if(segment.size() % 2)
        return false;
    for(int i = 0; i < segment.size(); i += 2){
        if(segment[i].second == segment[i + 1].second){
            if((segment[i + 1].first - segment[i].first - 1) % 2)
                return false;
        }
        else{
            if(!((segment[i + 1].first - segment[i].first - 1) % 2))
                return false;
        }
    }
    return true;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    cin >> n >> n;
    for(int i = 0; i < n; i++)
        cin >> blocked[i].second >> blocked[i].first;
    if(n % 2){
        cout << "NO" << endl;
        continue;
    }
    sort(blocked, blocked + n);
    segment.clear();
    bool ans = true;
    for(int i = 0; i < n; i++){
        if(i + 1 < n && blocked[i].first == blocked[i + 1].first){
            if(!solve())
                ans = false;
            segment.clear();
            i++;
            continue;
        }
        segment.push_back(blocked[i]);
    }
    if(!solve())
        ans = false;
    cout << (ans ? "YES" : "NO") << endl;
  }
}
