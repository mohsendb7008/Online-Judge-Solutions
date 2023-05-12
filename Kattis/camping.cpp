#include <bits/stdc++.h>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (__typeof(a) i=(a); i<(b); ++i)
#define iter(it,c) for (__typeof((c).begin()) \
  it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
const int INF = ~(1<<31);

const double EPS = 1e-9;
const double pi = acos(-1);
typedef unsigned long long ull;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> T smod(T a, T b) {
  return (a % b + b) % b; }

// Camping 

int main(){
    int n, m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<char> > ground(n, vector<char>(m, '.'));
    rep(i,0,n) {
        rep(j,0,m) {
            cin >> ground[i][j];
        }
    }

    vvi hori(n, vi(m)),
        vert(n, vi(m));

    vvi ulm(n, vi(m));

    rep(i, 0, n){
        for(int j = m - 1; j >= 0; --j){
            if(ground[i][j] == '.'){
                hori[i][j] = (j < m - 1 ? hori[i][j + 1] : 0) + 1;
            }
        }
    }
    rep(j, 0, m){
        for(int i = n - 1; i >= 0; --i){
            if(ground[i][j] == '.'){
                vert[i][j] = (i < n - 1 ? vert[i + 1][j] : 0) + 1;
            }
        }
    }
    for(int i = n - 1; i >= 0; --i){
        for(int j = m - 1; j >= 0; --j){
            if(i < n - 1 && j < m - 1){
                ulm[i][j] = min(ulm[i + 1][j + 1] + 1, min(hori[i][j], vert[i][j]));
            } else {
                ulm[i][j] = (ground[i][j] == '.' ? 1 : 0);
            }
        }
    }

    rep(j, 0, m){
        priority_queue<ii> Q;
        rep(i, 0, n){
            if(ulm[i][j])
                Q.push(make_pair(ulm[i][j], i));

            while(!Q.empty()){
                ii cur = Q.top();
                if(cur.first + cur.second <= i){
                    Q.pop();
                } else {
                    break;
                }
            }

            if(!Q.empty()){
                ii best = Q.top();
                ulm[i][j] = best.first;
            }
        }
    }

    rep(i, 0, n){
        priority_queue<ii> Q;
        rep(j, 0, m){
            if(ulm[i][j])
                Q.push(make_pair(ulm[i][j], j));

            while(!Q.empty()){
                ii cur = Q.top();
                if(cur.first + cur.second <= j){
                    Q.pop();
                } else {
                    break;
                }
            }

            if(!Q.empty()){
                ii best = Q.top();
                ulm[i][j] = best.first;
            }
        }
    }

    int q;
    int a, b;
    cin >> q;
    rep(i, 0, q){
        cin >> a >> b;
        --a, --b;
        if(ground[a][b] == '.')
            cout << ulm[a][b] * ulm[a][b] << '\n';
        else 
            cout << 0 << '\n';
    }
}