#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int counter;
unordered_map<string, int> id;
string name[100001], query[31];

inline int solve(const int k) {
    int maxE = 0;
    int minN = 100000;
    for (int i = 0; i < k; i++) {
        if (query[i][0] != '!') {
            auto it = id.find(query[i]);
            if (it == id.end() || it->second >= counter || it->first != name[it->second]) {
                return -1;
            }
            maxE = max(maxE, it->second);
        }
        else {
            auto it = id.find(query[i].substr(1));
            if (it != id.end() && it->second < counter && it->first == name[it->second]) {
                minN = min(minN, it->second);
            }
        }
    }
    if (minN < 100000) {
        return minN > maxE ? counter - minN : -1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    counter = 1;
    while (n--) {
        string c;
        cin >> c;
        if (c == "E") {
            string e;
            cin >> e;
            id[e] = counter;
            name[counter] = e;
            counter++;
        }
        else if (c == "D") {
            int r;
            cin >> r;
            counter -= r;
        }
        else if (c == "S") {
            int k;
            cin >> k;
            for (int i = 0; i < k; i++) {
                cin >> query[i];
            }
            const int ans = solve(k);
            if (ans == 0) {
                cout << "Yes" << endl;
            }
            else if (ans == -1) {
                cout << "Plot Error" << endl;
            }
            else {
                cout << ans << " " << "Just A Dream" << endl;
            }
        }
    }
}