#include <bits/stdc++.h>
using namespace std;

// Bingo Ties

int n, x;
set<int> card[103][5+3], in, un, di;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 5; j++)
            for(int k = 0; k < 5; k++)
                scanf("%d", &x), card[i][j].insert(x);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int ri = 0; ri < 5; ri++)
                for(int rj = 0; rj < 5; rj++){
                    in.clear();
                    set_intersection(card[i][ri].begin(), card[i][ri].end(), card[j][rj].begin(), card[j][rj].end(), inserter(in, in.begin()));
                    if(in.empty())
                        continue;
                    if(in.size() == 5){
                        printf("%d %d", i + 1, j + 1);
                        return 0;
                    }
                    un.clear();
                    set_union(card[i][ri].begin(), card[i][ri].end(), card[j][rj].begin(), card[j][rj].end(), inserter(un, un.begin()));
                    for(int last : in){
                        un.erase(last);
                        x = 1;
                        for(int k = 0; k < n; k++){
                            if(!x)
                                break;
                            if(k == i || k == j)
                                continue;
                            for(int rk = 0; rk < 5; rk++){
                                di.clear();
                                set_difference(card[k][rk].begin(), card[k][rk].end(), un.begin(), un.end(), inserter(di, di.begin()));
                                if(di.empty()){
                                    x = 0;
                                    break;
                                }
                            }
                        }
                        if(x){
                            printf("%d %d", i + 1, j + 1);
                            return 0;
                        }
                        un.insert(last);
                    }
                }
    printf("no ties");
}