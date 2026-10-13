
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> count(n + 1, 0);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        count[x]++;
    }

    int pairs = 0;
    int singles = 0;

    for (int i = 1; i <= n; i++) {
        if (count[i] == 2) pairs++;
        if (count[i] == 1) singles++;
    }

    if (pairs == n - 1) {
        pairs++;
    }

    cout << pairs << '\n';

    return 0;
}
