#include <bits/stdc++.h>
using namespace std;

// String Multimatching

const int maxn = 2e5 + 3;

string s, p;
vector<string> pat;
int q, n, m, sa[maxn], ra[maxn], cnt;
vector<pair<pair<int, int>, int>> tmp;
pair<int, int> prevy, nil = {-1, -1};

inline pair<int, int> find_match(string p){
    m = p.size();
    int lo = 0, hi = n - 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(strncmp(s.c_str() + sa[mid], p.c_str(), m) >= 0)
            hi = mid;
        else
            lo = mid + 1;
    }
    if(strncmp(s.c_str() + sa[lo], p.c_str(), m))
        return nil;
    pair<int, int> ans = {lo, -1};
    lo = 0, hi = n-1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(strncmp(s.c_str() + sa[mid], p.c_str(), m) > 0)
            hi = mid;
        else
            lo = mid + 1;
    }
    if(strncmp(s.c_str() + sa[hi], p.c_str(), m))
        hi--;
    ans.second = hi;
    return ans;
}

set<int> ans;

int main(){
    while(cin >> q){
        cin.ignore();
        pat.clear();
        while(q--)
            getline(cin, p), pat.push_back(p);
        getline(cin, s);
        n = s.size();
        for(int i = 0; i < n; i++)
            sa[i] = i, ra[i] = s[sa[i]];
        for(int k = 1; k < n; k *= 2){
            tmp.clear();
            for(int i = 0; i < n; i++)
                tmp.push_back({{ra[sa[i]], (sa[i] + k >= n) ? 0 : ra[sa[i] + k]}, sa[i]});
            sort(tmp.begin(), tmp.end());
            cnt = -1;
            prevy = {-1, -1};
            for(int i = 0; i < n; i++){
                sa[i] = tmp[i].second;
                if(tmp[i].first != prevy)
                    cnt++;
                ra[sa[i]] = cnt;
                prevy = tmp[i].first;
            }
            if(ra[sa[n-1]] == n-1)
                break;
        }
        for(string p : pat){
            ans.clear();
            pair<int, int> ansp = find_match(p);
            if(ansp != nil)
                for(int i = ansp.first; i <= ansp.second; i++)
                    ans.insert(sa[i]);
            for(int a : ans)
                cout << a << " ";
            cout << endl;
        }
    }
}