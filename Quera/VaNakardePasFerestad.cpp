#include <bits/stdc++.h>
using namespace std;

int n;
long long int k;
int gift[63];
long long int dp[63][3603][63];

struct s{
    float mean;
    int sum, n;
    long long int c;

    s(){}
    s(int sum, int n, long long int c){
        this->mean = (float)sum / n;
        this->n = n;
        this->c = c;
        this->sum = sum;
    }

    bool operator<(const s & o) const{
        return this->mean < o.mean;
    }

    bool operator==(const s & o) const{
        return this->n == o.n && this->sum == o.sum;
    }
};

s ss[3600*60+3];

int gcd(int a, int b){
    int mx = max(a, b);
    int mi = min(a, b);
    if(mi == 0)
        return mx;
    return gcd(mi, mx % mi);
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> gift[i];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= 3600; j++)
            for(int k = 0; k <= n; k++){
                if(i == 0)
                    dp[i][j][k] = (k == 0 && j == 0);
                else{
                    dp[i][j][k] = dp[i-1][j][k];
                    if(j >= gift[i-1] && k > 0)
                        dp[i][j][k] += dp[i-1][j-gift[i-1]][k-1];
                }
            }

    int cnt = 0;
    for(int i = 1; i <= 3600; i++)
        for(int j = 1; j <= n; j++){
            long long int tmp = dp[n][i][j];
            if(tmp > 0)
                ss[cnt++] = s(i, j, tmp);
        }
    sort(ss, ss+cnt);
    int index = 0;
    while(k > 0){
        k -= ss[index].c;
        if(k > 0)
            index++;
    }
    int sum = ss[index].sum;
    int num = ss[index].n;
    cout <<  sum / gcd(sum, num) << "/" << num / gcd(sum, num) << endl;
}