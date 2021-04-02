#include <bits/stdc++.h>
using namespace std;

// Longest Increasing Subsequence

int n;
int arr[100003];
int parent[100003];
int l;
int lis[100003];
int lis_index[100003];
int p;
int path[100003];

int main(){
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        l = 0;
        for(int i = 0; i < n; i++){
            int it = lower_bound(lis, lis+l, arr[i]) - lis;
            if(it == l){
                lis[l] = arr[i];
                lis_index[l] = i;
                parent[i] = l >= 1 ? lis_index[l-1] : -1;
                l++;
            }
            else{
                lis[it] = arr[i];
                lis_index[it] = i;
                parent[i] = it >= 1 ? lis_index[it-1] : -1;
            }
        }
        cout << l << endl;
        p = 0;
        int it = lis_index[l-1];
        while(it != -1){
            path[p++] = it;
            it = parent[it];
        }
        for(int i = p-1; i >= 0; i--)
            cout << path[i] << " ";
        cout << endl;
    }
}