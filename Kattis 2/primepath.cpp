#include "PrimeSieve.cpp"
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

int main() {
    const PrimeSieve sieve(10000);
    int q;
    cin >> q;
    while (q--) {
        int s, d;
        cin >> s >> d;
        queue<int> bfs;
        map<int, int> dis;
        bfs.push(s);
        dis[s] = 0;
        while (!bfs.empty()) {
            const int u = bfs.front();
            bfs.pop();
            if (u == d)
                break;
            const string str_u = to_string(u);
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i == 0 && j == 0)
                        continue;
                    string str_v = str_u;
                    str_v[i] = j + '0';
                    int v = atoi(str_v.c_str());
                    if (sieve.isPrime(v) && !dis.count(v)) {
                        dis[v] = dis[u] + 1;
                        bfs.push(v);
                    }
                }
            }
        }
        if (!dis.count(d))
            cout << "Impossible" << endl;
        else
            cout << dis[d] << endl;
    }
}