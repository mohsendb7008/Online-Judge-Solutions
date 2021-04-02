#include <bits/stdc++.h>
using namespace std;

// Scaling Recipes

int n;
string names[23];
double p, d, weight[23], per[23], ans[23];

int main(){
    cout << fixed << setprecision(1);
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n >> p >> d;
        int m;
        for(int i = 0; i < n; i++){
            cin >> names[i] >> weight[i] >> per[i];
            if(per[i] == 100.0)
                m = i;
        }
        double sf = d / p;
        ans[m] = weight[m] * sf;
        for(int i = 0; i < n; i++)
            if(i != m)
                ans[i] = ans[m] * per[i] / 100.0;
        cout << "Recipe # " << test << endl;
        for(int i = 0; i < n; i++)
            cout << names[i] << " " << ans[i] << endl;
        for(int i = 0; i < 40; i++)
            cout << "-";
        cout << endl;
    }
}