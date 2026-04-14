#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int>> vase;
vector<pair<int, pair<int, int>>> candidates1, candidates2;
bool g[36][36];
long adjS[36], adjD[36];
int iterations;

inline vector<int> getMembers(long mask) {
    vector<int> result;
    while (mask) {
        const int member = __builtin_ctzl(mask);
        result.push_back(member);
        mask &= mask - 1;
    }
    return result;
}

bool track(const int i, const long s, const long d) {
    if (i == 0)
        return true;
    if (iterations >= 1000000)
        return false;
    if (__builtin_popcountl(s) < i || __builtin_popcountl(d) < i)
        return false;
    iterations++;
    const vector<int> sm = getMembers(s);
    const vector<int> dm = getMembers(d);
    vector<pair<int, pair<long, long>>> promising;
    for (const int l : sm) {
        for (const int r : dm) {
            if (g[l][r]) {
                long sl = s & adjD[r] ^ 1l << l;
                long dr = d & adjS[l] ^ 1l << r;
                promising.emplace_back(-min(__builtin_popcountl(sl), __builtin_popcountl(dr)), make_pair(sl, dr));
            }
        }
    }
    sort(promising.begin(), promising.end());
    for (const auto it : promising) {
        if (track(i - 1, it.second.first, it.second.second)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        vase.clear();
        candidates1.clear();
        candidates2.clear();
        for (int i = 0; i < 36; i++) {
            adjS[i] = adjD[i] = 0;
            for (int j = 0; j < 36; j++) {
                g[i][j] = false;
            }
        }
        int m;
        cin >> m;
        while (m--) {
            int s, d;
            cin >> s >> d;
            s--, d--;
            vase.emplace_back(s, d);
            adjS[s] |= 1l << d;
            adjD[d] |= 1l << s;
            g[s][d] = true;
        }
        int limitS = 0, limitD = 0;
        for (int i = 0; i < 36; i++) {
            limitS = max(limitS, __builtin_popcountl(adjS[i]));
            limitD = max(limitD, __builtin_popcountl(adjD[i]));
        }
        const int limit = min(limitS, limitD);
        for (const auto v : vase) {
            candidates1.emplace_back(-min(__builtin_popcountl(adjS[v.first]), __builtin_popcountl(adjD[v.second])), v);
        }
        sort(candidates1.begin(), candidates1.end());
        set<int> takenL, takenR;
        for (const auto c : candidates1) {
            if (takenL.find(c.second.first) == takenL.end() && takenR.find(c.second.second) == takenR.end()) {
                candidates2.push_back(c);
                takenL.insert(c.second.first);
                takenR.insert(c.second.second);
            }
        }
        int ans = 1;
        for (int i = 2; i <= limit; i++) {
            iterations = 0;
            bool can = false;
            for (const auto c : candidates2) {
                if (-c.first < i)
                    break;
                const auto v = c.second;
                can = track(i - 1, adjD[v.second] ^ 1l << v.first, adjS[v.first] ^ 1l << v.second);
                if (can) {
                    break;
                }
            }
            if (can) {
                ans = i;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }
}