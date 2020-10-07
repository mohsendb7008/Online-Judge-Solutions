#include <bits/stdc++.h>
using namespace std;

// Jane Eyre

#define num long long int

int n, m, ptr = 0;
num k, ans = 0;
priority_queue<pair<string, num>, vector<pair<string, num>>, greater<pair<string, num>>> books; 
pair<num, pair<string, num>> unread[1000003]; 

bool cmp(const pair<num, pair<string, num>>& p1, const pair<num, pair<string, num>>& p2){
    return p1.first < p2.first;
}

int main(){
    scanf("%d %d %lld\n", &n, &m, &k);
    books.push({"Jane Eyre", k});
    char str[25];
    num l;
    while(n--){
        scanf("\"%[^\"]\" %lld\n", str, &l);
        books.push({string(str), l});
    }
    for(int i = 0; i < m; i++){
        scanf("%lld \"%[^\"]\" %lld\n", &unread[i].first, str, &unread[i].second.second);
        unread[i].second.first = string(str);
    }
    sort(unread, unread+m, cmp);
    while(!books.empty()){
        while(ptr < m && unread[ptr].first <= ans){
            books.push(unread[ptr].second);
            ptr++;
        }
        pair<string, num> cand = books.top();
        books.pop();
        ans += cand.second;
        if(cand.first == "Jane Eyre")
            break;
    }
    cout << ans << endl;
}
