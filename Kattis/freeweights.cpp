#include <bits/stdc++.h>
using namespace std;

// Free Weights

int n;
int maxw;
int a[1000003], b[1000003];
vector<int> v1, v2;

bool judge(int m){
    v1.clear();
    v2.clear();
    for(int i = 0; i < n; i++){
        if(a[i] <= m)
            continue;
        v1.push_back(a[i]);
    }
    if(v1.size() % 2)
        return false;
    for(int i = 0; i < v1.size(); i += 2)
        if(v1[i] != v1[i + 1])
            return false;
    for(int i = 0; i < n; i++){
        if(b[i] <= m)
            continue;
        v2.push_back(b[i]);
    }
    if(v2.size() % 2)
        return false;
    for(int i = 0; i < v2.size(); i += 2)
        if(v2[i] != v2[i + 1])
            return false;

    return true;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxw = max(maxw, a[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        maxw = max(maxw, b[i]);
    }
    int l = 0, r = maxw;
    while(l < r){
        int mid = (l + r) / 2;
        if(judge(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}