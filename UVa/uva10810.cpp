#include <bits/stdc++.h>
using namespace std;

// Ultra-QuickSort

#define num long long int

int n;
num seq[500003];
num tmp[500003];

num swaps(int start, int end){
    if(start == end)
        return 0;
    int mid = (start + end) / 2;
    num cnt = swaps(start, mid) + swaps(mid+1, end);
    int lptr = start, rptr = mid+1, output = 0;
    while(lptr <= mid || rptr <= end){
        if(lptr == mid+1)
            tmp[output++] = seq[rptr++];
        else if(rptr == end+1)
            tmp[output++] = seq[lptr++];
        else{
            if(seq[rptr] < seq[lptr]){
                tmp[output++] = seq[rptr++];
                cnt += mid - lptr + 1;
            }
            else tmp[output++] = seq[lptr++];
        }
    }
    copy(tmp, tmp+output, seq+start);
    return cnt;
}

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        for(int i = 0; i < n; i++)
            cin >> seq[i];
        cout << swaps(0, n-1) << endl;
    }
}