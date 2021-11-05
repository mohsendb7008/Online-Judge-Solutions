#include <bits/stdc++.h>
using namespace std;

struct ant {

    int x, y;
    char dir;

    ant(int x, int y, char dir){
        this->x = x - 1;
        this->y = y - 1;
        this->dir = dir;
    }

    void toggle(){
        switch(this->dir){
        case 'L':
            this->dir = 'R';
            break;
        case 'R':
            this->dir = 'L';
            break;
        case 'D':
            this->dir = 'U';
            break;
        case 'U':
            this->dir = 'D';
            break;
        }
    }

    bool move(){
        switch(this->dir){
        case 'L':
            this->x = this->x - 1;
            break;
        case 'R':
            this->x = this->x + 1;
            break;
        case 'D':
            this->y = this->y - 1;
            break;
        case 'U':
            this->y = this->y + 1;
            break;
        }
        return this->x >= 0 && this->x < 100 && this->y >= 0 && this->y < 100;
    }

};

vector<ant> ants;
map<pair<int, int>, vector<int>> collide;

int main(){
    int n;
    cin >> n;
    while(n--){
        int x, y;
        char dir;
        cin >> x >> y >> dir;
        ants.push_back(ant(x, y, dir));
    }
    int ans = 0;
    while(!ants.empty() && ans <= 100000){
        ans++;
        for(auto it = ants.begin(); it != ants.end();){
            if(!it->move()){
                ants.erase(it);
            }
            else{
                it++;
            }
        }
        collide.clear();
        for(int i = 0; i < ants.size(); i++){
            collide[{ants[i].x, ants[i].y}].push_back(i);
        }
        for(auto it : collide){
            if(it.second.size() > 1){
                for(auto i : it.second){
                    ants[i].toggle();
                }
            }
        }
    }
    cout << (ants.empty() ? ans : -1) << endl;
}