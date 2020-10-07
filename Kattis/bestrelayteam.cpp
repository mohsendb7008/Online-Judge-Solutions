#include <bits/stdc++.h>
using namespace std;

// Best Relay Team

int n;
string names[503];
pair<double, double> legs[503];
vector<pair<double, int>> legs234;
int leg2[503];
int leg3[503];
int leg4[503];

int main(){
    cout << fixed << setprecision(10);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> names[i] >> legs[i].first >> legs[i].second;
    double ans = INT_MAX;
    int ind;
    for(int i = 0; i < n; i++){
        legs234.clear();
        for(int j = 0; j < n; j++)
            if(j != i)
                legs234.push_back({legs[j].second, j});
        sort(legs234.begin(), legs234.end());
        leg2[i] = legs234[0].second;
        leg3[i] = legs234[1].second;
        leg4[i] = legs234[2].second;
        double curr = legs[i].first + legs234[0].first + legs234[1].first + legs234[2].first;
        if(curr < ans){
            ans = curr;
            ind = i;
        }       
    }
    cout << ans << endl;
    cout << names[ind] << endl;
    cout << names[leg2[ind]] << endl;
    cout << names[leg3[ind]] << endl;
    cout << names[leg4[ind]] << endl;     
}