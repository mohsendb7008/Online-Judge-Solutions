#include <bits/stdc++.h>
using namespace std;

int p, m, st[103], en[103], t[103], mp[103][103], ans[103];
string name[103];
unordered_map<string, int> id;
set<int> pr;

inline int convert(const string& s){
    int split = s.find_first_of(':');
    int h = stoi(s.substr(0, split));
    int m = stoi(s.substr(split + 1));
    if(h < 0)
        m *= -1;
    return 60 * h + m;
}

int main(){
    cin >> p >> m;
    for(int i = 0; i < p; i++){
        cin >> name[i], id[name[i]] = i;
        string dif, stt, enn;
        cin >> dif >> stt >> enn;
        int d = convert(dif);
        st[i] = convert(stt), en[i] = convert(enn);
        st[i] = (st[i] - d + 1440) % 1440;
        en[i] = (en[i] - d + 1440) % 1440;
    }
    for(int i = 0; i < m; i++){
        int c;
        cin >> c >> t[i];
        while(c--){
            string name;
            cin >> name;
            mp[i][id[name]] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        pr.clear();
        for(int j = 0; j < i; j++){
            if(ans[j] == -1)
                continue;
            for(int k = 0; k < p; k++)
                if(mp[i][k] && mp[j][k]){
                    pr.insert(j);
                    break;
                }
        }
        ans[i] = -1;
        for(int h = 0; h < 1440; h++){
            bool ok = 1;
            for(int j : pr){
                if(ans[j] > h + t[i] - 1 || h > ans[j] + t[j] - 1)
                    continue;
                ok = false;
                break;
            }
            if(!ok)
                continue;
            for(int k = 0; k < p; k++)
                if(mp[i][k]){
                    if(h >= st[k] && h + t[i] - 1 < en[k])
                        continue;
                    ok = false;
                    break;
                }
            if(ok){
                ans[i] = h;
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        if(ans[i] == -1)
            printf("N/A\n");
        else
            printf("%02d:%02d\n", ans[i] / 60, ans[i] % 60);
    }
}