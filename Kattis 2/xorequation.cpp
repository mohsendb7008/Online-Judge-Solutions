#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct number {
    string pattern;
    int numQuestionMarks;

    explicit number(const string &pattern) {
        this->pattern = pattern;
        this->numQuestionMarks = count(pattern.begin(), pattern.end(), '?');
    }

    bool operator <(const number& other) const {
        return this->numQuestionMarks < other.numQuestionMarks;
    }

    bool isMatch(const int value) const {
        const string str = to_string(value);
        if (str.size() != this->pattern.size())
            return false;
        for (int i = 0; i < str.size(); i++) {
            if (this->pattern[i] != '?' && this->pattern[i] != str[i]) {
                return false;
            }
        }
        return true;
    }

    void generate(const int i, const string &soFar, vector<int> &result) {
        if (i == this->pattern.size()) {
            result.push_back(stoi(soFar));
            return;
        }
        if (this->pattern[i] == '?') {
            for (int d = 0; d < 10; d++) {
                if (this->pattern.size() > 1 && i == 0 && d == 0)
                    continue;
                generate(i + 1, soFar + static_cast<char>(d + '0'), result);
            }
        } else {
            generate(i + 1, soFar + this->pattern[i], result);
        }
    }

    vector<int> getAll() {
        vector<int> result;
        generate(0, "", result);
        return result;
    }
};

int main() {
    string a, b, c;
    cin >> a >> b >> b >> c >> c;
    vector<number> l{number(a), number(b), number(c)};
    sort(l.begin(), l.end());
    int ans = 0;
    for (const int x : l[0].getAll()) {
        for (const int y : l[1].getAll()) {
            const int z = x ^ y;
            if (l[2].isMatch(z)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}