#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e6 + 3;
bitset<maxn> pf;

inline num rreverse(string s){
    reverse(s.begin(), s.end());
    return stoll(s);
}

inline num shift_rightt(string s){
    if(s.size() == 1)
        return stoll(s);
    string t = to_string(s[s.size() - 1] - '0');
    for(int i = 0; i < s.size() - 1; i++)
        t += to_string(s[i] - '0');
    return stoll(t);
}

inline num shift_leftt(string s){
    if(s.size() == 1)
        return stoll(s);
    string t = "";
    for(int i = 1; i < s.size(); i++)
        t += to_string(s[i] - '0');
    t += to_string(s[0] - '0');
    return stoll(t);
}

inline num digits_sum(string s){
    num ans = 0;
    for(char c : s)
        ans += c - '0';
    return ans;
}

inline bool palindromic(string s){
    if(s.size() == 1)
        return true;
    int n = s.size();
    for(int i = 0; i < n / 2; i++)
        if(s[i] != s[n-1-i])
            return false;
    return true;
}

int n, ans = 0;
string line, tmp;
vector<string> lines;

inline num conv(string tmp, num x){
    if(tmp == "x")
        return x;
    if(tmp == "reverse(x)")
        return rreverse(to_string(x));
    else if(tmp == "shift_right(x)")
        return shift_rightt(to_string(x));
    else if(tmp == "shift_left(x)")
        return shift_leftt(to_string(x));
    else if(tmp == "digits_sum(x)")
        return digits_sum(to_string(x));
    return stoll(tmp);
}

inline bool valid(num y){
    num c;
    for(int i = 0; i < n; i++){
        stringstream ss(lines[i]);
        ss >> tmp;
        num x = conv(tmp, y);
        ss >> tmp >> tmp;
        if(tmp == "less"){
            ss >> tmp >> tmp;
            c = conv(tmp, y);
            if(x >= c)
                return false;
        }
        else if(tmp == "greater"){
            ss >> tmp >> tmp;
            c = conv(tmp, y);
            if(x <= c)
                return false;
        }
        else if(tmp == "palindromic"){
            if(!palindromic(to_string(x)))
                return false;
        }
        else if(tmp == "a"){
            ss >> tmp;
            if(!pf[x])
                return false;
        }
        else if(tmp == "not"){
            ss >> tmp;
            if(tmp == "less"){
                ss >> tmp >> tmp;
                c = conv(tmp, y);
                if(x < c)
                    return false;
            }
            else if(tmp == "greater"){
                ss >> tmp >> tmp;
                c = conv(tmp, y);
                if(x > c)
                    return false;
            }
            else if(tmp == "palindromic"){
                if(palindromic(to_string(x)))
                    return false;
            }
            else if(tmp == "a"){
                ss >> tmp;
                if(pf[x])
                    return false;
            }
        }
    }
    return true;
}

int main(){
    pf.set();
    pf[0] = pf[1] = 0;
    for(num p = 2; p < maxn; p++)
        if(pf[p])
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, line);
        lines.push_back(line);
    }
    for(num p = 1; p <= 100000; p++)
        if(valid(p))
            ans++;
    cout << ans << endl;
}