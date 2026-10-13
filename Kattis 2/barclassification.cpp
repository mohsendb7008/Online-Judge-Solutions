
#include <bits/stdc++.h>
using namespace std;

enum class Orientation {
    Horizontal,
    Vertical
};

bool isPossible(const vector<int>& rowOnes, const vector<int>& colOnes,
                int totalOnes, Orientation orientation) {
    int n = rowOnes.size();

    for (int k = 0; k < n; k++) {
        int mismatches = 0;

        if (orientation == Orientation::Horizontal) {
            mismatches += n - rowOnes[k];
            mismatches += totalOnes - rowOnes[k];
        } else {
            mismatches += n - colOnes[k];
            mismatches += totalOnes - colOnes[k];
        }

        if (mismatches <= n)
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> rowOnes(n, 0);
    vector<int> colOnes(n, 0);
    int totalOnes = 0;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < n; j++) {
            if (row[j] == '1') {
                rowOnes[i]++;
                colOnes[j]++;
                totalOnes++;
            }
        }
    }

    bool horizontal = isPossible(rowOnes, colOnes, totalOnes,
                                 Orientation::Horizontal);

    bool vertical = isPossible(rowOnes, colOnes, totalOnes,
                               Orientation::Vertical);

    if (horizontal && vertical)
        cout << "+\n";
    else if (horizontal)
        cout << "-\n";
    else
        cout << "|\n";

    return 0;
}
