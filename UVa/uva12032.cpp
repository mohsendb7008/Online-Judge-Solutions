#include <bits/stdc++.h>
using namespace std;

// The Monkey and the Oiled Bamboo

int rungs[100003];
int diff[100003];

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> rungs[i];
        adjacent_difference(rungs, rungs+n, diff);
        int d = *max_element(diff, diff+n);
        int clone = d;
        bool can = true;
        for(int i = 0; i < n; i++){
            if(diff[i] > clone){
                can = false;
                break;
            }
            else if(diff[i] == clone)
                clone--;
        }
        cout << "Case " << test << ": " << (can ? d : d+1) << endl; 
    }
}