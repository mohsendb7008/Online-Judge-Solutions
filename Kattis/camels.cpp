#include <bits/stdc++.h>
using namespace std;

// Guessing Camels

int n;
vector<int> a, b, c;

int arr[200003], tmp[200003];

long long int swaps(int start, int end){
    if(start == end)
        return 0;
    int mid = (start + end) / 2;
    long long int cnt = swaps(start, mid) + swaps(mid+1, end);
    int lptr = start, rptr = mid+1;
    int output = start;
    while(lptr <= mid || rptr <= end){
        if(lptr == mid+1)
            tmp[output++] = arr[rptr++];
        else if(rptr == end+1)
            tmp[output++] = arr[lptr++];
        else{
            if(arr[lptr] > arr[rptr]){
                tmp[output++] = arr[rptr++];
                cnt += mid - lptr + 1;
            }
            else tmp[output++] = arr[lptr++];
        }
    }
    copy(tmp+start, tmp+output, arr+start);
    return cnt;
}

map<int, int> mp;

long long int pairs(vector<int>& first, vector<int>& second){
    mp.clear();
    for(int i = 0; i < n; i++)
        mp[first[i]] = i;
    for(int i = 0; i < n; i++)
        arr[i] = mp[second[i]];
    return (long long int)(n) * (n-1) / 2 - swaps(0, n-1);
}

int main(){
    cin >> n;
    a.resize(n), b.resize(n), c.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    for(int i = 0; i < n; i++)
        cin >> c[i];
    long long int A = pairs(a, b) + pairs(a, c) + pairs(b, c);
    cout << (A - (long long int)(n) * (n-1) / 2) / 2 << endl;
}