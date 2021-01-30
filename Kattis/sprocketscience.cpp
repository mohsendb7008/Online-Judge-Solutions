#include <bits/stdc++.h>
using namespace std;

// Sprocket Science

int gcd(int a, int b){
    if(a > b)
        swap(a, b);
    if(!a)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

const int limit = 10000;
const int n = 12;
int numerator[n], denominator[n];

inline int mask_ones(int mask){
    int ans = 0;
    while(mask){
        if(mask % 2)
            ans++;
        mask /= 2;
    }
    return ans;
}

int numerator1[n / 2], numerator2[n / 2];
int denominator1[n / 2], denominator2[n / 2], denominator3[n / 2];

inline bool solve(int mask){
    int ptr1 = 0, ptr2 = 0;
    for(int i = 0; i < 12; i++){
        if(mask & (1 << i)){
            numerator1[ptr1] = numerator[i]; 
            denominator1[ptr1++] = denominator[i];
        }
        else{
            numerator2[ptr2] = numerator[i];
            denominator2[ptr2++] = denominator[i];
        }
    }
    int lcm1 = 1, lcm2 = 1;
    for(int i = 0; i < n / 2; i++)
        lcm1 = lcm(lcm1, numerator1[i]);
    for(int i = 0; i < n / 2; i++)
        lcm2 = lcm(lcm2, numerator2[i]);
    if(lcm1 > limit || lcm2 > limit)
        return false;
    for(int i = 0; i < n / 2; i++){
        denominator1[i] *= lcm1 / numerator1[i];
        if(denominator1[i] > limit)
            return false;
    }
    for(int i = 0; i < n / 2; i++){
        denominator2[i] *= lcm2 / numerator2[i];
        if(denominator2[i] > limit)
            return false;
    }
    sort(denominator1, denominator1 + n / 2);
    sort(denominator2, denominator2 + n / 2);
    for(int multiplier1 = 1; multiplier1 <= limit / denominator1[n / 2 - 1]; multiplier1++){
        for(int i = 0; i < n / 2; i++)
            denominator3[i] = denominator1[i] * multiplier1;
        if(denominator3[0] % denominator2[0])
            continue;
        int multiplier2 = denominator3[0] / denominator2[0];
        bool feasible = true;
        for(int i = 1; i < n / 2; i++)
            if(denominator3[i] % denominator2[i] || denominator3[i] / denominator2[i] != multiplier2){
                feasible = false;
                break;
            }
        if(feasible){
            if(lcm1 * multiplier1 > limit || lcm2 * multiplier2 > limit)
                continue;
            cout << lcm1 * multiplier1 << " " << lcm2 * multiplier2 << endl;
            for(int i = 0; i < n / 2; i++)
                cout << denominator3[i] << " ";
            cout << endl;
            return true;
        }
    }
    return false;
}

int main(){
    for(int i = 0; i < 12; i++){
        string s;
        cin >> s;
        int slash = s.find_first_of('/');
        numerator[i] = stoi(s.substr(0, slash));
        denominator[i] = stoi(s.substr(slash + 1));
    }
    for(int mask = 0; mask < (1 << n); mask++)
        if(mask_ones(mask) == 6 && solve(mask))
            return 0;
    cout << "impossible" << endl;
}