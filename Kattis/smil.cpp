#include <bits/stdc++.h>
using namespace std;

// SMIL

string s;
vector<string> smiles {":)", ";)", ":-)", ";-)"};

int main() {
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        for (string smile : smiles)
            if (s.substr(i, smile.size()) == smile) {
                cout << i << endl;
                break;
            }
    }
}