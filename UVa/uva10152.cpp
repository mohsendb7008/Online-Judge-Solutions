#include <bits/stdc++.h>
using namespace std;

// ShellSort

int t, n;
string tmp[100003], turt[100003];
map<string, int> id;
int stackk[100003];

bool first = true;
int main(){
    cin >> t;
    string str;
    getline(cin, str);
    while(t--){
        first = false;
        cin >> n;
        getline(cin, str);
        for(int i = 0; i < n; i++)
            getline(cin, tmp[i]);
        id.clear();
        for(int i = 0; i < n; i++)
            getline(cin, str), id[str] = i, turt[i] = str;
        for(int i = 0; i < n; i++)
            stackk[i] = id[tmp[i]];
        int ans = n-1;
        for(int i = n-1; i >= 0; i--)
            if(stackk[i] == ans)
                ans--;
        for(int i = ans; i >= 0; i--)
            cout << turt[i] << endl;
        cout << endl;
    }
}