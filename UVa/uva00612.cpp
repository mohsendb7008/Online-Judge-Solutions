#include <bits/stdc++.h>
using namespace std;

// DNA Sorting

int arr[53];
int tmp[53];

int swaps(int start, int end){
    if(start == end)
        return 0;
    int mid = (start + end) / 2;
    int cnt = swaps(start, mid) + swaps(mid+1, end);
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

bool first = true;

int m, n;
string strings[103];
pair<int, int> ans[103];

int main(){
    int t;
    cin >> t;
    while(t--){
        if(!first)
            cout << endl;
        first = false;
        cin >> m >> n;
        for(int i = 0; i < n; i++){
            cin >> strings[i];
            for(int j = 0; j < m; j++)
                arr[j] = strings[i][j];
            ans[i] = {swaps(0, m-1), i};
        }
        sort(ans, ans+n);
        for(int i = 0; i < n; i++)
            cout << strings[ans[i].second] << endl;
    }
}