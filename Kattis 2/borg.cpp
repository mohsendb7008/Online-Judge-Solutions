#include <iostream>
#include "GraphV1.cpp"
using namespace std;

#define inf numeric_limits<int>::max()
int adjR[4] {0, 0, 1, -1};
int adjC[4] {1, -1, 0, 0};
int n, m;
char grid[53][53];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            for (int j = 0; j < line.size(); j++) {
                grid[i][j] = line[j];
            }
            for (int j = static_cast<int>(line.size()); j < m; j++) {
                grid[i][j] = ' ';
            }
        }
        GraphV1<int> APSP(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#')
                    continue;
                for (int k = 0; k < 4; k++) {
                    const int x = i + adjR[k];
                    const int y = j + adjC[k];
                    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '#')
                        continue;
                    APSP.addEdge(Edge<int>(Node(i * m + j), Node(x * m + y), 1));
                }
            }
        }
        vector<int> aliens;
        int source = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'S' || grid[i][j] == 'A') {
                    if (grid[i][j] == 'S') {
                        source = static_cast<int>(aliens.size());
                    }
                    aliens.push_back(i * m + j);
                }
            }
        }
        GraphV1<int> MST(aliens.size());
        for (int i = 0; i < aliens.size(); i++) {
            const int a = aliens[i];
            auto fromA = APSP.dijkstra(Node(a), 0);
            for (int j = 0; j < aliens.size(); j++) {
                if (j == i)
                    continue;
                const int b = aliens[j];
                MST.addEdge(Edge<int>(Node(i), Node(j), fromA.getMinDistance(Node(b))));
            }
        }
        cout << MST.prim(Node(source), 0) << endl;
    }
}