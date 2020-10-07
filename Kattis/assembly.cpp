#include <bits/stdc++.h>
using namespace std;

// Self-Assembly

bool floyd[52+3][52+3];

int main(){
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        for(int i = 0; i < 8; i += 2)
            if(s[i] != '0')
                for(int j = 0; j < 8; j += 2)
                    if(j != i && s[j] != '0')
                        floyd[s[i] - 'A' + ((s[i+1] == '+') ? 0 : 26)][s[j] - 'A' + ((s[j+1] == '-') ? 0 : 26)] = true;
    }
    for(int k = 0; k < 52; k++)
        for(int i = 0; i < 52; i++)
            for(int j = 0; j < 52; j++)
                if(floyd[i][k] && floyd[k][j])
                    floyd[i][j] = true;
    for(int i = 0; i < 52; i++)
        if(floyd[i][i]){
            cout << "unbounded" << endl;
            return 0;
        }
    cout << "bounded" << endl;
}