#include <bits/stdc++.h>
using namespace std;

// Stop Counting

int n;
long long int arr[1000003];
long long int psum1[1000003];
long long int psum2[1000003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    psum1[0] = arr[0];
    for(int i = 1; i < n; i++)
        psum1[i] = psum1[i-1] + arr[i];
    psum2[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        psum2[i] = psum2[i+1] + arr[i];
    double ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, max(double(psum1[i])/(i+1), double(psum2[i])/(n-i)));
    cout << fixed << setprecision(10) << ans << endl;
    
    
}