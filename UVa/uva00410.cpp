#include <bits/stdc++.h>
using namespace std;

// Station Balance

int test = 1;
int C, S;
vector<int> cha[8];
int spec[13];
double balance, ans;

int main(){
    cout << fixed << setprecision(5);
    while(cin >> C >> S){
        for(int i = 0; i < C; i++)
            cha[i].clear();
        for(int i = 0; i < S; i++)
            cin >> spec[i];
        while(S < 2 * C)
            spec[S++] = 0;
        sort(spec, spec+S);
        for(int i = 0; i < C; i++){
            if(spec[i])
                cha[i].push_back(spec[i]);
            if(spec[S-1-i])
                cha[i].push_back(spec[S-1-i]);
        }
        balance = accumulate(spec, spec+S, 0.0) / C;
        ans = 0.0;
        for(int i = 0; i < C; i++)
            ans += abs(accumulate(cha[i].begin(), cha[i].end(), 0.0) - balance);
        cout << "Set #" << test << endl;
        for(int c = 0; c < C; c++){
            cout << ' ' << c << ':';
            for(int item : cha[c])
                cout << ' ' << item;
            cout << endl;
        }
        cout << "IMBALANCE = " << ans << endl << endl;
        test++;
    }
}