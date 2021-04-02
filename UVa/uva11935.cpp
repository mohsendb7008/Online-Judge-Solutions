#include <bits/stdc++.h>
using namespace std;

// Through th Desert

double lastd, tank, rate, leak;

bool reachable(double d){
    double deltax = d - lastd;
    lastd = d;
    tank -= deltax * (leak + rate);
    return tank >= 0;
}

vector<string> test;

bool judge(double ans){
    tank = ans;
    leak = 0;
    stringstream ss(test[0]);
    string str;
    ss >> lastd;
    ss >> str;
    ss >> str;
    ss >> rate, rate /= 100;
    for(int i = 1; i < test.size(); i++){
        stringstream ss(test[i]);
        int d;
        ss >> d;
        if(!reachable(d))
            return false;
        ss >> str;
        if(str == "Fuel"){
            ss >> str;
            ss >> rate, rate /= 100;
        }
        else if(str == "Leak")
            leak++;
        else if(str == "Mechanic")
            leak = 0;
        else if(str == "Gas")
            tank = ans;
    }
    return true;
}

double solve(){
    double start = 0, end = INT_MAX;
    while(fabs(end - start) > 0.000000001){
        double mid = (start + end) / 2;
        if(judge(mid))
            end = mid;
        else start = mid;
    }
    return start;
}

int main(){
    cout << fixed << setprecision(3);
    string line;
    while(true){
        getline(cin, line);
        if(line == "0 Fuel consumption 0")
            break;
        stringstream ss(line);
        int d;
        string str;
        ss >> d >> str;
        if(d == 0)
            test.clear();
        test.push_back(line);
        if(str == "Goal")
            cout << solve() << endl;
    }
}