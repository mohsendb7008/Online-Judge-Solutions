#include <bits/stdc++.h>
using namespace std;

const int inf = INT_MAX;

int n, xb[103], yb[103], xp[103], yp[103], zb[103], xs, ys, zs, xd, yd, zd, x[203], y[203], z[103], xcnt, ycnt, zcnt, dis[203][203][103];
set<int> X, Y, Z, adj[203][203][103];
priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> dij;
int adjR[6]{0, 0, 0, 0, 1, -1};
int adjC[6]{0, 0, 1, -1, 0, 0};
int adjH[6]{1, -1, 0, 0, 0, 0};

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %d %d %d", xb+i, yb+i, xp+i, yp+i, zb+i);
    scanf("%d %d %d", &xs, &ys, &zs);
    scanf("%d %d %d", &xd, &yd, &zd);
    Z.insert(0);
    for(int i = 0; i < n; i++){
        X.insert(xb[i]), X.insert(xp[i]);
        Y.insert(yb[i]), Y.insert(yp[i]);
        Z.insert(zb[i]);
    }
    X.insert(xs), X.insert(xd);
    Y.insert(ys), Y.insert(yd);
    Z.insert(zs), Z.insert(zd);
    xcnt = 0;
    for(int it : X)
        x[xcnt++] = it;
    ycnt = 0;
    for(int it : Y)
        y[ycnt++] = it;
    zcnt = 0;
    for(int it : Z)
        z[zcnt++] = it;
    for(int i = 0; i < xcnt; i++)
        for(int j = 0; j < ycnt; j++)
            for(int k = 0; k < zcnt; k++){
                dis[i][j][k] = inf;
                for(int a = 0; a < 6; a++)
                    adj[i][j][k].insert(a);
            }
    for(int b = 0; b < n; b++){
        int itxb = lower_bound(x, x + xcnt, xb[b]) - x;
        int itxp = lower_bound(x, x + xcnt, xp[b]) - x;
        int ityb = lower_bound(y, y + ycnt, yb[b]) - y;
        int ityp = lower_bound(y, y + ycnt, yp[b]) - y;
        int itzb = lower_bound(z, z + zcnt, zb[b]) - z;
        for(int j = ityb + 1; j < ityp; j++)
            for(int k = 0; k < itzb; k++)
                adj[itxb][j][k].erase(4), adj[itxp][j][k].erase(5);
        for(int i = itxb + 1; i < itxp; i++)
            for(int k = 0; k < itzb; k++)
                adj[i][ityb][k].erase(2), adj[i][ityp][k].erase(3);
        for(int i = itxb + 1; i < itxp; i++)
            for(int j = ityb + 1; j < ityp; j++)
                adj[i][j][itzb].erase(1);
    }
    for(int i = 0; i < xcnt; i++)
        for(int j = 0; j < ycnt; j++)
            for(int k = 0; k < zcnt; k++)
                if(xs == x[i] && ys == y[j] && zs == z[k]){
                    xs = i, ys = j, zs = k;
                    break;
                }
    for(int i = 0; i < xcnt; i++)
        for(int j = 0; j < ycnt; j++)
            for(int k = 0; k < zcnt; k++)
                if(xd == x[i] && yd == y[j] && zd == z[k]){
                    xd = i, yd = j, zd = k;
                    break;
                }
    dis[xs][ys][zs] = 0;
    dij.push({0, {xs, {ys, zs}}});
    while(!dij.empty()){
        int w = dij.top().first;
        int ux = dij.top().second.first;
        int uy = dij.top().second.second.first;
        int uz = dij.top().second.second.second;
        dij.pop();
        if(ux == xd && uy == yd && uz == zd)
            break;
        if(dis[ux][uy][uz] < w)
            continue;
        for(int k : adj[ux][uy][uz]){
            int vx = ux + adjR[k], vy = uy + adjC[k], vz = uz + adjH[k];
            if(vx >= 0 && vx < xcnt && vy >= 0 && vy < ycnt && vz >= 0 && vz < zcnt){
                int cost = abs(x[vx] - x[ux]) + abs(y[vy] - y[uy]) + abs(z[vz] - z[uz]);
                if(w + cost < dis[vx][vy][vz])
                    dis[vx][vy][vz] = w + cost, dij.push({w + cost, {vx, {vy, vz}}});
            }
        }
    }
    printf("%d\n", dis[xd][yd][zd]);
}