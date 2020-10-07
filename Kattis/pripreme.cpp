#include <bits/stdc++.h>
using namespace std;

// Pripreme

int n;
long long int arr[300003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(n == 1)
        cout << 2 * arr[0] << endl;
    else{
        sort(arr, arr+n);
        long long int sum = 0;
        for(int i = 0; i < n-1; i++)
            sum += arr[i];
        cout << sum + arr[n-1] + max(0ll, arr[n-1] - sum) << endl;
    }
}