#include <bits/stdc++.h>
using namespace std;

// Powers of 2

#define num long long int

num n, e, lcp[21], dp[21][21][3];
string t, p;

num cdp(int i, int j, bool f){
    if(dp[i][j][f] != -1)
        return dp[i][j][f];
    if(i == t.size())
        return dp[i][j][f] = j == p.size();
    num ans = 0;
    for(char c = '0'; c <= '9'; c++){
        if(!f && c > t[i])
            continue;
        bool nf = f || (c < t[i]);
        if(j == p.size()){
            ans += cdp(i+1, j, nf);
            continue;
        }
        if(c == p[j]){
            ans += cdp(i+1, j+1, nf);
            continue;
        }
        int nj = j;
        bool found = 0;
        while(nj){
            nj = lcp[nj-1];
            if(c == p[nj]){
                ans += cdp(i+1, nj+1, nf);
                found = 1;
                break;
            }
        }
        if(!found)
            ans += cdp(i+1, nj, nf);
    }
    return dp[i][j][f] = ans;
}

int main(){
    cin >> n >> e;
    t = to_string(n);
    num po2 = 1;
    while(e--)
        po2 *= 2;
    p = to_string(po2);
    int i = 0, j = 1;
	lcp[0] = 0;
	while(j < p.size()){
		if(p[i] == p[j])
			lcp[j] = i+1, i++, j++;
		else if(i)
			i = lcp[i-1];
		else
			lcp[j] = 0, j++;
	}
    for(int i = 0; i < 21; i++)
        for(int j = 0; j < 21; j++)
            dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = -1;
    cout << cdp(0, 0, 0) << endl;
}