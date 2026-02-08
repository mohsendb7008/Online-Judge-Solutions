#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template <typename T>
vector<int> longest_increasing_subsequence_indices(const vector<T>& a) {
    vector<int> result;
    const int n = static_cast<int>(a.size());

    if (n == 0)
        return result;

    vector<T> tail_values;
    vector<int> tail_indices;
    vector<int> predecessor(n, -1);

    tail_values.reserve(n);
    tail_indices.reserve(n);

    for (int i = 0; i < n; ++i) {
        const T& value = a[i];

        int pos = lower_bound(tail_values.begin(), tail_values.end(), value) - tail_values.begin();

        if (pos == static_cast<int>(tail_values.size())) {
            tail_values.push_back(value);
            tail_indices.push_back(i);
        } else {
            tail_values[pos] = value;
            tail_indices[pos] = i;
        }

        if (pos > 0) {
            predecessor[i] = tail_indices[pos - 1];
        }
    }

    int current = tail_indices.back();
    while (current != -1) {
        result.push_back(current);
        current = predecessor[current];
    }

    reverse(result.begin(), result.end());
    return result;
}

int n, m;
list<int> l;
list<int>::iterator pos[500001];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        l.push_back(i);
        pos[i] = prev(l.end());
    }
    while (m--) {
        char c;
        int i, j;
        cin >> c >> i >> j;
        l.erase(pos[i]);
        auto index = pos[j];
        if (c == 'A') {
            pos[i] = l.insert(index, i);
        } else if (c == 'B') {
            pos[i] = l.insert(next(index), i);
        }
    }
    vector<int> v;
    for (const int i : l)
        v.push_back(i);
    const vector<int>& lis = longest_increasing_subsequence_indices(v);
    set<int> sorted;
    for (const int i : lis)
        sorted.insert(v[i]);
    vector<string> ins;
    for (int x : v) {
        auto it = sorted.lower_bound(x);
        if (it != sorted.end() && *it == x)
            continue;
        if (it == sorted.end()) {
            string s = "B " + to_string(x) + " " + to_string(*prev(it));
            ins.push_back(s);
        }
        else {
            string s = "A " + to_string(x) + " " + to_string(*it);
            ins.push_back(s);
        }
        sorted.insert(x);
    }
    cout << ins.size() << endl;
    for (const string& s : ins)
        cout << s << endl;
}