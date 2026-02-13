#include <iostream>
#include <map>
using namespace std;

map<pair<string, pair<int, bool>>, long> memo;

long dp(const string& number, const int digitSum, const bool freeDigit) {
    if (number.empty())
        return digitSum ? 0 : 1;
    const auto key = make_pair(number, make_pair(digitSum, freeDigit));
    const auto it = memo.find(key);
    if (it != memo.end())
        return it->second;
    long ans = 0;
    const int limit = min(freeDigit ? 9 : number[0] - '0', digitSum);
    for (int digit = 0; digit <= limit; digit++) {
        ans += dp(number.substr(1), digitSum - digit, freeDigit || digit < number[0] - '0');
    }
    return memo[key] = ans;
}

int main() {
    long A, B;
    int S;
    cin >> A >> B >> S;
    const long extra = dp(to_string(A - 1), S, false);
    const long count = dp(to_string(B), S, false) - extra;
    cout << count << endl;
    long lo = A;
    long hi = B;
    while (lo < hi) {
        const long mid = (lo + hi) / 2;
        const long check = dp(to_string(mid), S, false) - extra;
        if (check) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}
