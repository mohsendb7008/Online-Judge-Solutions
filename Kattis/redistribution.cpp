#include <bits/stdc++.h>
using namespace std;

// Exam Redistribution

int n;
pair<int, int> s[33];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i].first, s[i].second = i + 1;
    sort(s, s+n);
    int sum = 0;
    for(int i = 0; i < n-1; i++)
        sum += s[i].first;
    if(sum < s[n-1].first)
        cout << "impossible" << endl;
    else{
        for(int i = n-1; i >= 0; i--)
            cout << s[i].second << " ";
        cout << endl;
    }
}