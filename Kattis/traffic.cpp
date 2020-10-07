#include <bits/stdc++.h>
using namespace std;

// Bumper-To-Bumper Traffic

const int maxn = 1e5 + 3;

int x1, x2;
bool s1, s2;
int n1, n2, t1[maxn], t2[maxn];

int prevy = 0;

int process(int t, bool who){
    int nt = t, pt = prevy, dt = nt - pt;
    prevy = nt;
    if(s1 && !s2){
        if(x2 < x1 && x2 + dt >= x1 - 4)
            return x1 - 4 - x2 + pt;
        x2 += dt;
    }
    else if(!s1 && s2){
        if(x1 < x2 && x1 + dt >= x2 - 4)
            return x2 - 4 - x1 + pt;
        x1 += dt;
    }
    if(who)
        s1 = !s1;
    else
        s2 = !s2;
    return -1;
}

int main(){
    cin >> x1 >> x2;
    cin >> n1;
    for(int i = 0; i < n1; i++)
        cin >> t1[i];
    cin >> n2;
    for(int i = 0; i < n2; i++)
        cin >> t2[i];
    int i = 0, j = 0;
    while(i < n1 || j < n2){
        int ans;
        if(i < n1 && j < n2){
            if(t1[i] <= t2[j])
                ans = process(t1[i], 0), i++;
            else
                ans = process(t2[j], 1), j++;
        }
        else if(i == n1)
            ans = process(t2[j], 1), j++;
        else if(j == n2)
            ans = process(t1[i], 0), i++;
        if(ans != -1){
            cout << "bumper tap at time " << ans << endl; 
            return 0;
        }
    }
     if(s1 && !s2){
        if(x2 < x1){
            cout << "bumper tap at time " << x1 - 4 - x2 + prevy << endl;
            return 0;
        }
    }
    else if(!s1 && s2){
        if(x1 < x2){
            cout << "bumper tap at time " << x2 - 4 - x1 + prevy << endl;
            return 0;
        }
    }
    cout << "safe and sound" << endl;
}