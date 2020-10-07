#include <bits/stdc++.h>
using namespace std;

// Eko

int n;
long long int M, trees[1000003];

bool judge(long long int h){
    long long int wood = 0;
    for(int i = 0; i < n; i++)
        wood += max(trees[i] - h, 0ll);
    return wood >= M;
}

int main(){
    cin >> n >> M;
    for(int i = 0; i < n; i++)
        cin >> trees[i];
    long long int lo = 0, hi = *max_element(trees, trees+n);
    while(lo < hi){
        long long int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(judge(mid))
            lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
}