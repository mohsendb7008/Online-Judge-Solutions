#include <iostream>
#include <vector>
#include <set>
#include <map>
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

#define num long long int
set<num> all;
map<num, num> lefts, rights;
struct snow {
    num height, count, countL, countR;
};
vector<snow> snows;
constexpr num mod = 1000000009;

int main() {
    num n;
    cin >> n;
    while (n--) {
        num a, b;
        cin >> a >> b;
        all.insert(a);
        all.insert(b);
        lefts[a]++;
        rights[b]++;
    }
    num counter = 0;
    num max_counter = 0;
    if (!all.empty() && all.find(0) == all.end()) {
        const snow snow0 { 0, *all.begin(), 0, 0 };
        snows.push_back(snow0);
        max_counter = 0;
    }
    for (num i : all) {
        counter += lefts[i];
        max_counter = max(max_counter, counter);
        const snow snow1 { counter, 1, 0, 0 };
        snows.push_back(snow1);
        counter -= rights[i];
        auto nextCandidate = all.lower_bound(i + 1);
        if (nextCandidate != all.end() && *nextCandidate > i + 1) {
            const snow snow2 { counter, *nextCandidate - i - 1, 0, 0 };
            snows.push_back(snow2);
        }
    }
    BinaryIndexedTree<num> firsts(max_counter + 1);
    for (snow& second : snows) {
        if (second.height > 0) {
            second.countL = firsts.RangeSumQuery(second.height);
        }
        firsts.IncreaseValueAt(second.height + 1, second.count);
    }
    BinaryIndexedTree<num> thirds(max_counter + 1);
    for (auto it = snows.rbegin(); it != snows.rend(); ++it) {
        snow& second = *it;
        if (second.height < max_counter) {
            second.countR = thirds.RangeSumQuery(second.height + 2, max_counter + 1);
        }
        thirds.IncreaseValueAt(second.height + 1, second.count);
    }
    bool shovel = true;
    num ans = 0;
    for (const snow& s : snows) {
        if (s.count > 0 && s.countL > 0 && s.countR > 0) {
            shovel = false;
        }
        num triple = s.count % mod;
        triple = triple * (s.countL % mod) % mod;
        triple = triple * (s.countR % mod) % mod;
        ans = (ans + triple) % mod;
    }
    if (shovel) {
        cout << "shovel time!" << endl;
    }
    else {
        cout << ans << endl;
    }
}
