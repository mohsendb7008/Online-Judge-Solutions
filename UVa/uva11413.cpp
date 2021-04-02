#include <bits/stdc++.h>
using namespace std;

// Fill the Containers

int n, m;
int milk[1003];

bool judge(int ans){
    int need = 1;
    int curr = milk[0];
    for(int i = 1; i < n; i++){
        if(curr + milk[i] > ans){
            need++;
            curr = milk[i];
        }
        else curr += milk[i];
    }
    return need <= m;
}

int main(){
    while(cin >> n){
        cin >> m;
        int start = 0, end = 0;
        for(int i = 0; i < n; i++)
            cin >> milk[i], start = max(start, milk[i]), end += milk[i];
        while(start < end){
            int mid = (start + end) / 2;
            if(judge(mid))
                end = mid;
            else start = mid + 1;
        }
        cout << start << endl;
    }
}