#include <bits/stdc++.h>
using namespace std;

// Pharmacy

int n, t;
long long int technicians[13];
vector<pair<int, int>> prescriptions[3];
long long int ssum = 0, rsum = 0;
int scnt = 0, rcnt = 0;

int main(){
    cin >> n >> t;
    int d, f, j;
    char c;
    for(int i = 0; i < n; i++)
        cin >> d >> c >> f, prescriptions[c == 'R'].push_back({d, f});
    sort(prescriptions[0].begin(), prescriptions[0].end());
    sort(prescriptions[1].begin(), prescriptions[1].end());
    int ptr[3]{0, 0};
    while(ptr[0] < prescriptions[0].size() || ptr[1] < prescriptions[1].size()){
        long long int tech = INT_MAX;
        int tech_index;
        for(int j = 0; j < t; j++)
            if(technicians[j] < tech)
                tech = technicians[j], tech_index = j;
        int which;
        if(ptr[0] == prescriptions[0].size())
            which = 1;
        else if(ptr[1] == prescriptions[1].size())
            which = 0;
        else if(prescriptions[0][ptr[0]].first <= tech)
            which = 0;
        else if(prescriptions[0][ptr[0]].first <= prescriptions[1][ptr[1]].first)
            which = 0;
        else
            which = 1;
        if(prescriptions[which][ptr[which]].first > tech)
            tech = prescriptions[which][ptr[which]].first;
        technicians[tech_index] = tech + prescriptions[which][ptr[which]].second;
        long long int completion = tech + prescriptions[which][ptr[which]].second - prescriptions[which][ptr[which]].first;
        if(!which)
            ssum += completion, scnt++;
        else
            rsum += completion, rcnt++;
        ptr[which]++;
    }
    cout << fixed << setprecision(10);
    cout << (scnt ? (double(ssum) / scnt) : 0) << " " << (rcnt ? (double(rsum) / rcnt) : 0) << endl;
}