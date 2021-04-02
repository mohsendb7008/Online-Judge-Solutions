#include <bits/stdc++.h>
using namespace std;

// Eight Queens

char g[11][11];
vector<pair<int, int>> queens;

int main(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++){
            cin >> g[i][j];
            if(g[i][j] == '*')
                queens.push_back({i, j});
        }
	if(queens.size() != 8){
		cout << "invalid" << endl;
		return 0;
	}
    bool wr = false;
    for(int i = 0; i < queens.size(); i++){
        for(int j = i + 1; j < queens.size(); j++)
            if(queens[i].first == queens[j].first || queens[i].second == queens[j].second || abs(queens[i].first - queens[j].first) == abs(queens[i].second - queens[j].second)){
                wr = true;
                break;
            }
        if(wr)
            break;
    }
    if(wr)
        cout << "invalid" << endl;
    else
        cout << "valid" << endl;
}