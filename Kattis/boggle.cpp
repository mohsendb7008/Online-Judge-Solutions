#include <bits/stdc++.h>
using namespace std;

// Boggle

const int maxn = 3e5 + 3;

int n, l;
string words[maxn];

bool vis[4][4];
char g[4][4];

int adjR[8]{0, 0, -1, 1, -1, -1, 1, 1};
int adjC[8]{-1, 1, 0, 0, -1, 1, -1, 1};

bool track(int i, int j, int k, int ptr){
    if(ptr == words[k].size() - 1)
        return true;
    vis[i][j] = 1;
    bool ans = 0;
    for(int z = 0; z < 8; z++){
        int x = i + adjR[z], y = j + adjC[z];
        if(x >= 0 && x < 4 && y >= 0 && y < 4 && g[x][y] == words[k][ptr+1] && !vis[x][y] && track(x, y, k, ptr+1)){
            ans = 1;
            break;
        }       
    }
    vis[i][j] = 0;
    return ans;
}

int score[10]{0, 0, 0, 1, 1, 2, 3, 5, 11};

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
    cin >> l;
    while(l--){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> g[i][j];
        int nana = 0, cnt = 0;
        string longest = "";
        for(int k = 0; k < n; k++){
            bool found = 0;
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++)
                    if(g[i][j] == words[k][0] && track(i, j, k, 0)){
                        found = 1;
                        break;
                    }
                if(found)
                    break;
            }
            if(found){
                nana += score[words[k].size()], cnt++;
                if(words[k].size() > longest.size())
                    longest = words[k];
                else if(words[k].size() == longest.size() && words[k] < longest)
                    longest = words[k];
            }
        }
        cout << nana << " " << longest << " " << cnt << endl;
    }
}