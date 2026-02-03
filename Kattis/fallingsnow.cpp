#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <climits>
using namespace std;

template <typename T>
class BinaryIndexedTree {
    int size;
    vector<T> aggregation;
public:
    explicit BinaryIndexedTree(const int n) {
        size = n + 1;
        aggregation.assign(size, 0);
    }
    T RangeSumQuery(const int endInclusive) {
        T sum = 0;
        for (int i = endInclusive; i > 0; i -= i & -i) {
            sum += aggregation[i];
        }
        return sum;
    }
    T RangeSumQuery(const int startInclusive, const int endInclusive) {
        return RangeSumQuery(endInclusive) - (startInclusive <= 1 ? 0 : RangeSumQuery(startInclusive - 1));
    }
    void IncreaseValueAt(const int index, const T value) {
        for (int i = index; i < size; i += i & -i) {
            aggregation[i] += value;
        }
    }
};

set<long long int> all;
map<long long int, long long int> lefts, rights;

struct snow {
    long long int point, height, count, countL, countR;
};

vector<snow> snows;

constexpr long long int mod = 1000000009;

int main() {
    long long int n;
    cin >> n;
    while (n--) {
        long long int a, b;
        cin >> a >> b;
        all.insert(a);
        all.insert(b);
        lefts[a]++;
        rights[b]++;
    }
    long long int counter = 0;
    long long int max_counter = -1;
    if (!all.empty() && all.find(0) == all.end()) {
        const snow snow0 { 0, 0, *all.begin(), 0, 0 };
        snows.push_back(snow0);
        max_counter = 0;
    }
    for (long long int i : all) {
        counter += lefts[i];
        if (counter > max_counter) {
            max_counter = counter;
        }
        const snow snow1 { i, counter, 1, 0, 0 };
        snows.push_back(snow1);
        counter -= rights[i];
        auto nextCandidate = all.lower_bound(i + 1);
        if (nextCandidate != all.end() && *nextCandidate > i + 1) {
            const snow snow2 { i + 1, counter, *nextCandidate - i - 1, 0, 0 };
            snows.push_back(snow2);
        }
    }
    long long int minh1 = LLONG_MAX, minh2 = LLONG_MAX;
    bool shovel = true;
    for (const snow s : snows) {
        if (s.height <= minh1) {
            minh1 = s.height;
        }
        else if (s.height <= minh2) {
            minh2 = s.height;
        }
        else {
            shovel = false;
            break;
        }
    }
    if (shovel) {
        cout << "shovel time!" << endl;
        return 0;
    }
    BinaryIndexedTree<long long int> firsts(max_counter + 1);
    for (snow& second : snows) {
        if (second.height > 0) {
            second.countL = firsts.RangeSumQuery(second.height);
        }
        firsts.IncreaseValueAt(second.height + 1, second.count);
    }
    BinaryIndexedTree<long long int> thirds(max_counter + 1);
    for (auto it = snows.rbegin(); it != snows.rend(); ++it) {
        snow& second = *it;
        if (second.height < max_counter) {
            second.countR = thirds.RangeSumQuery(second.height + 2, max_counter + 1);
        }
        thirds.IncreaseValueAt(second.height + 1, second.count);
    }
    long long int ans = 0;
    for (const snow s : snows) {
        long long int total = s.count % mod;
        total = total * (s.countL % mod) % mod;
        total = total * (s.countR % mod) % mod;
        ans = (ans + total) % mod;
    }
    cout << ans << endl;
}