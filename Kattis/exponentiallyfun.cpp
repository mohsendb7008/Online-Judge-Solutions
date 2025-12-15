#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;
static const double INF = 1e300;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++)
        if (prime[i])
            for (int j = i * i; j <= N; j += i)
                prime[j] = false;

    vector<int> primes;
    for (int i = 2; i <= N; i++)
        if (prime[i]) primes.push_back(i);

    vector<double> minLog(N + 1, INF), maxLog(N + 1, -INF);
    vector<long long> minMod(N + 1, 0), maxMod(N + 1, 0);

    minLog[0] = maxLog[0] = 0.0;
    minMod[0] = maxMod[0] = 1;

    for (int p : primes) {
        double lp = log((double)p);
        for (int s = p; s <= N; s++) {
            if (minLog[s - p] < INF) {
                double candLog = minLog[s - p] + lp;
                if (candLog < minLog[s]) {
                    minLog[s] = candLog;
                    minMod[s] = minMod[s - p] * p % MOD;
                }
            }
            if (maxLog[s - p] > -INF) {
                double candLog = maxLog[s - p] + lp;
                if (candLog > maxLog[s]) {
                    maxLog[s] = candLog;
                    maxMod[s] = maxMod[s - p] * p % MOD;
                }
            }
        }
    }

    cout << minMod[N] << " " << maxMod[N] << "\n";
}
