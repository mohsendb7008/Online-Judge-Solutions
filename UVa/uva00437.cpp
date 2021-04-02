#include <bits/stdc++.h>
using namespace std;

// The Tower of Babylon

struct block{
    int x, y, z;

    block(){

    }

    block(int x, int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    bool operator<(const block & o) const{
        if(this->x == o.x)
            return this->y > o.y;
        return this->x > o.x;
    }

    bool operator==(const block & o) const{
        return this->x == o.x && this->y == o.y && this->z == o.z;
    }
};

vector<block> blocks;
int n;
int dp[183];

int main(){
    int t = 1;
    while(true){
        cin >> n;
        if(n == 0)
            break;

        blocks.clear();
        for(int i = 0; i < n; i++){
            int x, y, z;
            cin >> x >> y >> z;
            blocks.push_back(block(x, y, z));
            blocks.push_back(block(y, x, z));
            blocks.push_back(block(x, z, y));
            blocks.push_back(block(z, x, y));
            blocks.push_back(block(y, z, x));
            blocks.push_back(block(z, y, x));
        }

        sort(blocks.begin(), blocks.end());

        // for(block b : blocks)
        //     cerr << b.x << " " << b.y << " " << b.z << endl;

        for(int i = blocks.size() - 1; i >= 0; i--){
            dp[i] = blocks[i].z;
            for(int j = i + 1; j < blocks.size(); j++)
                    if(blocks[i].x > blocks[j].x && blocks[i].y > blocks[j].y)
                        dp[i] = max(dp[i], dp[j] + blocks[i].z);
        }

        printf("Case %d: maximum height = %d\n", t++, *max_element(dp, dp+blocks.size()));
    
    }
}