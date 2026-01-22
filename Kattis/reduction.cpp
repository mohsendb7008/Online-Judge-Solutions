#include <iostream>
#include <cstring>
using namespace std;

struct agency {
    char name[20]{};
    int a{}, b{}, cost{};
} agencies [100];

bool cmp(const agency& first, const agency& second) {
    if (first.cost == second.cost) {
        return strcmp(first.name, second.name) < 0;
    }
    return first.cost < second.cost;
}

int n, m, l;

inline void calculate(const int index) {
    const int a = agencies[index].a;
    const int b = agencies[index].b;
    int ans = 0;
    int rem = n;
    while (rem > m) {
        if (rem / 2 >= m && b < (rem - rem / 2) * a) {
            ans += b;
            rem /= 2;
        }
        else {
            ans += (rem - m) * a;
            rem = m;
        }
    }
    agencies[index].cost = ans;
}

inline void solve() {
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 0; i < l; i++) {
        scanf("%20[^:]:%d,%d", agencies[i].name, &agencies[i].a, &agencies[i].b);
    }
    for (int i = 0; i < l; i++) {
        calculate(i);
    }
    sort(agencies, agencies + l, cmp);
    for (int i = 0; i < l; i++) {
        printf("%s %d\n", agencies[i].name, agencies[i].cost);
    }
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    for (int i = 1; i <= testCases; i++) {
        printf("Case %d\n", i);
        solve();
    }
}