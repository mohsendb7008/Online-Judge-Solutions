#include <bits/stdc++.h>
using namespace std;

// Low Power

int n, k, s, b[1000003], p[1000003];

bool judge(int d){
    if(p[1] > d)
        return false;
    int prevy = 1;
    for(int i = 1; i < n; i++){
        bool found = false;
        for(int j = prevy + 2; j <= 2 * i * k + 1; j++)
            if(p[j] <= d){
                prevy = j;
                found = true;
                break;
            }
        if(!found)
            return false;
    } 
    return true;
}

int main(){
    cin >> n >> k;
    s = 2 * n * k;
    for(int i = 0; i < s; i++)
        cin >> b[i];
    sort(b, b+s);
    adjacent_difference(b, b+s, p);
    int start = 0, end = 1000000000;
    while(start < end){
        int mid = (start + end) / 2;
        if(judge(mid))
            end = mid;
        else start = mid + 1;
    }
    cout << start << endl;
}