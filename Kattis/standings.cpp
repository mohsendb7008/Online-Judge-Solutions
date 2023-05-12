#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Biased Standings

int a[100003];

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        for(int i = 0; i < N; i++){
            string name;
            cin >> name >> a[i];
        }
        sort(a, a + N);
        long long int ans = 0;
        for(int i = 0; i < N; i++){
            ans += abs(a[i] - (i + 1));
        }
        cout << ans << endl;
    }
}