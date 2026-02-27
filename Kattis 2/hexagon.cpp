#include "FlowNetwork.cpp"
#include <iostream>
#include <sstream>

using namespace std;

int S, counter, checker[100], weight[100], len[100], board[100][100], sp[100][10000];

inline long calculate(const vector<int>& final) {
    FlowNetwork<> fn(2 * S + 2);
    for (int i = 0; i < S; i++) {
        fn.addCapacity(0, i + 1, 1, 0);
    }
    for (int i = 0; i < S; i++) {
        for (int j = 0; j < S; j++) {
            fn.addCapacity(i + 1, S + j + 1, 1, sp[i][final[j]] * weight[i]);
        }
    }
    for (int j = 0; j < S; j++) {
        fn.addCapacity(S + j + 1, 2 * S + 1, 1, 0);
    }
    return fn.minCostMaxFlow(Node(0), Node(2 * S + 1)).second;
}

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    for (int i = 0; i < tc; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        S = 0;
        while (ss >> checker[S]) {
            S++;
        }
        getline(cin, line);
        stringstream ss2(line);
        for (int j = 0; j < S; j++) {
            ss2 >> weight[j];
        }
        int C = (S + 1) / 2;
        counter = 1;
        for (int r = 0; r < S; r++) {
            len[r] = C;
            for (int c = 0; c < C; c++) {
                board[r][c] = counter++;
            }
            if (r >= S / 2) {
                C--;
            } else {
                C++;
            }
        }
        GraphV1<int> g(counter);
        auto addEdge = [&g](const int u, const int v, const int w) -> void {
            g.addEdge(Edge<int>(Node(u), Node(v), w));
        };
        for (int r = 0; r < S; r++) {
            for (int c = 0; c < len[r]; c++) {
                if (c) {
                    addEdge(board[r][c], board[r][c-1], 1);
                }
                if (c + 1 < len[r]) {
                    addEdge(board[r][c], board[r][c+1], 1);
                }
                if (r && c < len[r-1]) {
                    addEdge(board[r][c], board[r-1][c], 1);
                }
                if (r + 1 < S && c < len[r+1]) {
                    addEdge(board[r][c], board[r+1][c], 1);
                }
                if (r <= S / 2) {
                    if (r && c - 1 >= 0 && c - 1 < len[r-1]) {
                        addEdge(board[r][c], board[r-1][c-1], 1);
                    }
                } else {
                    if (r && c + 1 < len[r-1]) {
                        addEdge(board[r][c], board[r-1][c+1], 1);
                    }
                }
                if (r < S / 2) {
                    if (r + 1 < S && c + 1 < len[r+1]) {
                        addEdge(board[r][c], board[r+1][c+1], 1);
                    }
                } else {
                    if (r + 1 < S && c - 1 >= 0 && c - 1 < len[r+1]) {
                        addEdge(board[r][c], board[r+1][c-1], 1);
                    }
                }
            }
        }
        for (int u = 0; u < S; u++) {
            auto spResult = g.dijkstra(Node(checker[u]), 0);
            for (int v = 1; v < counter; v++) {
                sp[u][v] = spResult.getMinDistance(Node(v));
            }
        }
        vector<int> path1;
        for (int c = 0; c < len[S / 2]; c++) {
            path1.push_back(board[S / 2][c]);
        }
        long ans = calculate(path1);
        vector<int> path2;
        int c = 0;
        for (int r = 0; r < S; r++) {
            path2.push_back(board[r][c]);
            if (r < S / 2)
                c++;
        }
        ans = min(ans, calculate(path2));
        vector<int> path3;
        c = 0;
        for (int r = S-1; r >=0; r--) {
            path3.push_back(board[r][c]);
            if (r > S / 2)
                c++;
        }
        ans = min(ans, calculate(path3));
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
}