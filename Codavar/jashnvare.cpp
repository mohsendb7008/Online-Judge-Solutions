#include <bits/stdc++.h>
using namespace std;

// Jashnvare

int n;

int solve(){
	int up = sqrt(n);
    for(int i = 2; i <= up; i++)
        if(n % i == 0)
            return i;
    return n;
}

int main(){
    cin >> n;
    cout << solve() << endl;
}