#include <iostream>
using namespace std;

constexpr int maxI = 100000;
int countL[maxI+1], countR[maxI+1];

inline void init() {
    fill_n(countL, maxI+1, 0);
    fill_n(countR, maxI+1, 0);
}

inline void updateL(const int l) {
    for (int i = l; i <= maxI; i += i & -i) {
        countL[i]++;
    }
}

inline void updateR(const int r) {
    for (int i = r; i <= maxI; i += i & -i) {
        countR[i]++;
    }
}

inline int queryL(const int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ans += countL[i];
    }
    return ans;
}

inline int queryR(const int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) {
        ans += countR[i];
    }
    return ans;
}

inline int findCross(const int x) {
    const int startBeforeX = queryL(x-1);
    const int finishBeforeX = queryR(x);
    return startBeforeX - finishBeforeX;
}

int cross[maxI+1];

int main() {
    int n;
    cin >> n;
    init();
    fill_n(cross, maxI+1, 0);
    while (n--) {
        int l, r;
        cin >> l >> r;
        int sc = findCross(l);
        int fc = findCross(r);
        sc -= cross[l];
        fc -= cross[r];
        cout << sc + fc << endl;
        updateL(l);
        updateR(r);
        cross[l] += sc;
        cross[r] += fc;
    }
}