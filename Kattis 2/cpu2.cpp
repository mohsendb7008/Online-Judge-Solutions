#include <iostream>
#include <vector>
#include <map>
#include <set>

#define num __int128

using namespace std;

vector<bool> prime;
vector<num> primes;

inline void sieve(const num n) {
    prime.assign(n + 1, true);
    for (num i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.push_back(i);
            for (num j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

map<num, bool> cache;

inline bool isPrime(const num p) {
    if (p < prime.size())
        return prime[p];
    const auto it = cache.find(p);
    if (it != cache.end())
        return it->second;
    for (const num a : primes) {
        if (a * a > p)
            break;
        if (p % a == 0) {
            return cache[p] = false;
        }
    }
    return cache[p] = true;
}

set<num> explosive;
constexpr num maxx = 1000000000000000L;

inline void preprocess() {
    for (const num p : primes) {
        if (p > 100000)
            break;
        for (num a = 1; true; a++) {
            if (a % p == 0)
                continue;
            const num b = p - a;
            const num q = a * p + b;
            if (q > maxx || p * q > maxx)
                break;
            const num t = a * q + b;
            if (t > maxx || p * q * t > maxx)
                break;
            if (isPrime(q) && isPrime(t)) {
                num e = p * q * t;
                explosive.insert(e);
                num f = t;
                while (true) {
                    f = a * f + b;
                    if (f > maxx || e * f > maxx || !isPrime(f))
                        break;
                    e = e * f;
                    explosive.insert(e);
                }
            }
        }
    }
}

vector<num> query;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(32000000);
    preprocess();
    for (const num e : explosive) {
        query.push_back(e);
    }
    int n;
    cin >> n;
    while (n--) {
        long ll, rr;
        cin >> ll >> rr;
        const num l = ll, r = rr;
        auto it1 = upper_bound(query.begin(), query.end(), l - 1);
        auto it2 = upper_bound(query.begin(), query.end(), r);
        cout << (it2 - it1) << '\n';
    }
}