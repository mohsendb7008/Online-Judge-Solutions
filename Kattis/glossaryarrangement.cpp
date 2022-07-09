#include <bits/stdc++.h>
using namespace std;

// Glossary Arrangement

const int maxn = 5003;

int n, w, dp[maxn], trace[maxn], pl[maxn];
string words[maxn];

int calculate(int limit){
    for(int i = 0; i < n; i++){
        dp[i] = INT_MAX;
    }
    for(int i = n-1; i >= 0; i--){
        int max_l_word = 0;
        for(int j = i; j < n; j++){
            if(j - i + 1 > limit){
                break;
            }
            max_l_word = max(max_l_word, int(words[j].size()));
            if(dp[j+1] != INT_MAX){
                int better = max_l_word + 1 + dp[j+1];
                if(better < dp[i]){
                    dp[i] = better;
                    trace[i] = j; 
                }
            }
        }
    }
    return dp[0];
}

vector<vector<string> > partitions;

int main(){
    cin >> n >> w;
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }
    int lo = 1, hi = n;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        int min_width = calculate(mid);
        if(min_width - 1 > w){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    calculate(lo);
    int i = 0;
    int p = 0;
    int rows = 0;
    while(i < n){
        vector<string> partition;
        int j = trace[i];
        for(int x = i; x <= j; x++){
            partition.push_back(words[x]);
            pl[p] = max(pl[p], int(words[x].size()));
        }
        partitions.push_back(partition);
        rows = max(rows, int(partition.size()));
        i = j + 1;
        p++;
    }
    cout << lo << " " << partitions.size() << endl;
    for(int i = 0; i < p; i++){
        cout << pl[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < p; j++){
            int max_c = pl[j];
            if(i >= partitions[j].size()){
                for(int x = 0; x < max_c; x++){
                    cout << " ";
                }
            }else{
                cout << partitions[j][i];
                int rep = max_c - int(partitions[j][i].size());
                while(rep--){
                    cout << " ";
                }
            }
            cout << " ";
        }
        cout << endl;
    }
}
