#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, t, m, ans[10000];
queue<pair<int, int>> leftSide, rightSide;
int now, side, cap;

void populate() {
    cin >> n >> t >> m;
    for (int i = 0; i < m; i++) {
        int arrival;
        string s;
        cin >> arrival >> s;
        if (s == "left")
            leftSide.emplace(arrival, i);
        if (s == "right")
            rightSide.emplace(arrival, i);
    }
    now = 0;
    side = 0;
    cap = n;
}

bool load () {
    if (!cap)
        return false;
    if (side == 0 && !leftSide.empty()) {
        if (leftSide.front().first <= now) {
            ans[leftSide.front().second] = now + t;
            leftSide.pop();
            cap--;
            return true;
        }
    }
    if (side == 1 && !rightSide.empty()) {
        if (rightSide.front().first <= now) {
            ans[rightSide.front().second] = now + t;
            rightSide.pop();
            cap--;
            return true;
        }
    }
    return false;
}

void sailLeft() {
    now = max(now, leftSide.front().first);
    if (side != 0)
        now += t;
    side = 0;
}

void sailRight() {
    now = max(now, rightSide.front().first);
    if (side != 1)
        now += t;
    side = 1;
}

void sail() {
    if (!leftSide.empty() && !rightSide.empty()) {
        if (leftSide.front().first < rightSide.front().first) {
            sailLeft();
        }
        else if (rightSide.front().first < leftSide.front().first) {
            sailRight();
        }
        else {
            now = leftSide.front().first;
        }
    }
    else if (!leftSide.empty()) {
        sailLeft();
    }
    else if (!rightSide.empty()) {
        sailRight();
    }
}

void simulate() {
    while (!leftSide.empty() || !rightSide.empty()) {
        if (!load()) {
            sail();
        }
        while (load()) {}
        now += t;
        side = 1 - side;
        cap = n;
    }
}

void show() {
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}

void solve() {
    populate();
    simulate();
    show();
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        solve();
        cout << endl;
    }
}