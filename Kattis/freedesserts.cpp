#include <bits/stdc++.h>
using namespace std;

// Free Desserts

#define num long long int

string c;
num dp[19][2][2][1 << 10][1 << 10];
set<int> digits{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

num cdp(int i, bool b, bool f, int s, int g){
    if(dp[i][b][f][s][g] != -1)
        return dp[i][b][f][s][g];
    if(i == c.size())
        return dp[i][b][f][s][g] = !b;
    num ans = 0;
    if(i == 0 && c[i] == '1'){
        ans += cdp(i + 1, 1, 1, s, g);
        return dp[i][b][f][s][g] = ans;
    }
    if(f){
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            int d2 = *it;
            if(!(s & (1 << d2))){
                if(d2 + 1 == c[i] - '0' + 10 && b)
                    ans += cdp(i + 1, 1, 1, s, g | (1 << d2));
                if(d2 + 1 == c[i] - '0' && !b)
                    ans += cdp(i + 1, 1, 1, s, g | (1 << d2));
            }
        }
        for(int d : digits){
            if(!d || (g & (1 << d)))
                continue;
            for(auto it = digits.rbegin(); it != digits.rend(); it++){
                int d2 = *it;
                if(i == 0 && d2 <= d)
                    continue;
                if(i == 1 && c[0] == '1' && d2 <= d)
                    continue;
                if(d2 != d && !(s & (1 << d2)))
                    for(int b2 = 1; b2 >= 0; b2--){
                        if(d + d2 + b2 == c[i] - '0' && !b)
                            ans += cdp(i + 1, b2, 0, s | (1 << d), g | (1 << d2));
                        if(d + d2 + b2 == c[i] - '0' + 10 && b)
                            ans += cdp(i + 1, b2, 0, s | (1 << d), g | (1 << d2));
                    }
            }
        }
    }
    else{
        for(int d : digits){
            if(g & (1 << d))
                continue;
            for(auto it = digits.rbegin(); it != digits.rend(); it++){
                int d2 = *it;
                if(d == d2)
                    continue;
                if(!(s & (1 << d2)))
                    for(int b2 = 1; b2 >= 0; b2--){
                        if(d + d2 + b2 == c[i] - '0' && !b)
                            ans += cdp(i + 1, b2, 0, s | (1 << d), g | (1 << d2));
                        if(d + d2 + b2 == c[i] - '0' + 10 && b)
                            ans += cdp(i + 1, b2, 0, s | (1 << d), g | (1 << d2));
                    }
            }
        }
    }
    return dp[i][b][f][s][g] = ans;
}

vector<num> nums;

void build(int i, bool b, bool f, int s, int g, num smaller){
    if(!dp[i][b][f][s][g] || nums.size() == 5000)
        return;
    if(i == c.size()){
        nums.push_back(smaller);
        return;
    }
    if(i == 0 && c[i] == '1'){
        build(i + 1, 1, 1, s, g, smaller);
        return;
    }
    if(f){
        for(auto it = digits.rbegin(); it != digits.rend(); it++){
            int d2 = *it;
            if(!(s & (1 << d2))){
                if(d2 + 1 == c[i] - '0' + 10 && b){
                    build(i + 1, 1, 1, s, g | (1 << d2), smaller);
                    if(nums.size() == 5000)
                        return;
                }
                if(d2 + 1 == c[i] - '0' && !b){
                    build(i + 1, 1, 1, s, g | (1 << d2), smaller);
                    if(nums.size() == 5000)
                        return;
                }
            }
        }
        for(int d : digits){
            if(!d || (g & (1 << d)))
                continue;
            for(auto it = digits.rbegin(); it != digits.rend(); it++){
                int d2 = *it;
                if(i == 0 && d2 <= d)
                    continue;
                if(i == 1 && c[0] == '1' && d2 <= d)
                    continue;
                if(d2 != d && !(s & (1 << d2)))
                    for(int b2 = 1; b2 >= 0; b2--){
                        if(d + d2 + b2 == c[i] - '0' && !b){
                            build(i + 1, b2, 0, s | (1 << d), g | (1 << d2), smaller * 10 + d);
                            if(nums.size() == 5000)
                                return;
                        }
                        if(d + d2 + b2 == c[i] - '0' + 10 && b){
                            build(i + 1, b2, 0, s | (1 << d), g | (1 << d2), smaller * 10 + d);
                            if(nums.size() == 5000)
                                return;
                        }
                    }
            }
        }
    }
    else{
        for(int d : digits){
            if(g & (1 << d))
                continue;
            for(auto it = digits.rbegin(); it != digits.rend(); it++){
                int d2 = *it;
                if(d == d2)
                    continue;
                if(!(s & (1 << d2)))
                    for(int b2 = 1; b2 >= 0; b2--){
                        if(d + d2 + b2 == c[i] - '0' && !b){
                            build(i + 1, b2, 0, s | (1 << d), g | (1 << d2), smaller * 10 + d);
                            if(nums.size() == 5000)
                                return;
                        }
                        if(d + d2 + b2 == c[i] - '0' + 10 && b){
                            build(i + 1, b2, 0, s | (1 << d), g | (1 << d2), smaller * 10 + d);
                            if(nums.size() == 5000)
                                return;
                        }
                    }
            }
        }
    }
}

int main(){
    cin >> c;
    for(char cc : c)
        digits.erase(cc - '0');
    for(int i = 0; i < 19; i++)
        for(int b = 0; b < 2; b++)
            for(int f = 0; f < 2; f++)
                for(int s = 0; s < (1 << 10); s++)
                    for(int g = 0; g < (1 << 10); g++)
                        dp[i][b][f][s][g] = -1;
    cout << cdp(0, 0, 1, 0, 0) << endl;
    build(0, 0, 1, 0, 0, 0);
    num total = stoll(c);
    for(num smaller : nums)
        cout << smaller << " " << total - smaller << endl;
}