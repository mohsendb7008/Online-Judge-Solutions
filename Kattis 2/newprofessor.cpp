#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> shirts;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int c;
        cin >> c;
        shirts.push(c);
    }
    int ans = 0;
    while (shirts.size() >= 5) {
        vector<int> buffer;
        for (int i = 0; i < 5; i++) {
            int c = shirts.top() - 1;
            shirts.pop();
            if (c) {
                buffer.push_back(c);
            }
        }
        for (int c : buffer) {
            shirts.push(c);
        }
        ans += 5;
    }
    ans += static_cast<int>(shirts.size());
    cout << ans << endl;
}
