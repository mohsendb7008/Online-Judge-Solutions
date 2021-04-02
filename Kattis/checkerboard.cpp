#include <bits/stdc++.h>
using namespace std;

// Magic Checkerboard

#define num long long int
#define inf INT_MAX

int a[2003][2003], b[2003][2003], c[2003][2003], d[2003][2003];
bool a1 = true, b1 = true, c1 = true, d1 = true;
int n, m;
num grid[2003][2003];
num up[2003][2003], down[2003][2003], leftt[2003][2003], rightt[2003][2003];
num tu[2003][2003], td[2003][2003], tl[2003][2003], tr[2003][2003];

inline void cp(){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            tu[i][j] = up[i][j];
            td[i][j] = down[i][j];
            tl[i][j] = leftt[i][j];
            tr[i][j] = rightt[i][j];
        }
}

inline num f(int pattern[2003][2003], bool use = true){
    num sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(grid[i][j]){
                sum += grid[i][j];
                continue;
            }
            num start = 0, endd = inf;
            if(i > 0)
                start = max(start, tu[i-1][j]);
            if(j > 0)
                start = max(start, tl[i][j-1]);
            if(i < n-1)
                endd = min(endd, td[i+1][j]);
            if(j < m-1)
                endd = min(endd, tr[i][j+1]);
            bool fd = false;
            num found;
            for(num cand = start + 1; cand < endd; cand++){
                if(!use || (cand % 2 == pattern[i][j])){
                    fd = true;
                    found = cand;
                    break;
                }
            }
            if(!fd)
                return LLONG_MAX;
            sum += found;
            tu[i][j] = td[i][j] = tl[i][j] = tr[i][j] = found;
        }
    return sum;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    for(int j = 0; j < m; j++){
        up[0][j] = grid[0][j];
        for(int i = 1; i < n; i++){
            if(!grid[i][j])
                up[i][j] = up[i-1][j];
            else{
                if(grid[i][j] <= up[i-1][j]){
                    cout << -1 << endl;
                    return 0;
                }
                up[i][j] = grid[i][j];
            }
        }
    }
    for(int j = 0; j < m; j++){
        down[n-1][j] = !grid[n-1][j] ? inf : grid[n-1][j];
        for(int i = n-2; i >= 0; i--){
            if(!grid[i][j])
                down[i][j] = down[i+1][j];
            else{
                if(grid[i][j] >= down[i+1][j]){
                    cout << -1 << endl;
                    return 0;
                }
                down[i][j] = grid[i][j];
            }
        }       
    }
    for(int i = 0; i < n; i++){
        leftt[i][0] = grid[i][0];
        for(int j = 1; j < m; j++){
            if(!grid[i][j])
                leftt[i][j] = leftt[i][j-1];
            else{
                if(grid[i][j] <= leftt[i][j-1]){
                    cout << -1 << endl;
                    return 0;
                }
                leftt[i][j] = grid[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        rightt[i][m-1] = !grid[i][m-1] ? inf : grid[i][m-1];
        for(int j = m-2; j >= 0; j--){
            if(!grid[i][j])
                rightt[i][j] = rightt[i][j+1];
            else{
                if(grid[i][j] >= rightt[i][j+1]){
                    cout << -1 << endl;
                    return 0;
                }
                rightt[i][j] = grid[i][j];
            }
        }
    }
    if(n == 1 || m == 1){
        cp();
        num ans = f(a, false);
        cout << (ans == LLONG_MAX ? -1 : ans) << endl;
        return 0;
    }
    for(int i = 0; i < 2003; i += 2)
        for(int j = 0; j < 2003; j++){
            a[i][j] = 1;
            b[i][j] = 0;
        }
    for(int i = 1; i < 2003; i += 2)
        for(int j = 0; j < 2003; j++){
            a[i][j] = 0;
            b[i][j] = 1;
        }
    for(int j = 0; j < 2003; j += 2)
        for(int i = 0; i < 2003; i++){
            c[i][j] = 1;
            d[i][j] = 0;
        }
    for(int j = 1; j < 2003; j += 2)
        for(int i = 0; i < 2003; i++){
            c[i][j] = 0;
            d[i][j] = 1;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 0) 
                continue;
            if((grid[i][j] % 2 != a[i][j]) && a1)
                a1 = false;
            if((grid[i][j] % 2 != b[i][j]) && b1)
                b1 = false;
            if((grid[i][j] % 2 != c[i][j]) && c1)
                c1 = false;
            if((grid[i][j] % 2 != d[i][j]) && d1)
                d1 = false;
        }
    num ans = LLONG_MAX;
    if(a1){
        cp();
        ans = min(ans, f(a));
    }
    if(b1){
        cp();
        ans = min(ans, f(b));
    }
    if(c1){
        cp();
        ans = min(ans, f(c));
    }
    if(d1){
        cp();
        ans = min(ans, f(d));
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
}