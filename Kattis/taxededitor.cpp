#include <bits/stdc++.h>
using namespace std;

// Taxed Editor

#define num long long int
#define numd long double

const int maxn = 1e5 + 3;
const numd eps = 1e-15l;

bool cmp(pair<num, num>& p1, pair<num, num>& p2){
    return p1.second < p2.second;
}

int n, m;
pair<num, num> books[maxn];

// Moore's greedy algorithm for minimizing the number of late jobs:
bool judge(numd sp){
    numd days = 0;
    priority_queue<numd> jobs;
    for(int i = 0; i < n; i++){
        numd tmp = books[i].first / sp;
        jobs.push(tmp);
        if(days + tmp < books[i].second + eps)
            days += tmp;
        else{
            numd longest = jobs.top();
            jobs.pop();
            days += tmp - longest;
        }
    }
    return jobs.size() >= n - m;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> books[i].first >> books[i].second;
    sort(books, books + n, cmp);
    num lo = 0, hi = 100000000000000;
    while(lo < hi){
        num mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}