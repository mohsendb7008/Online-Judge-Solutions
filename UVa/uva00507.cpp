#include <bits/stdc++.h>
using namespace std;

// Jill Rides Again

int routes[20003], n;
pair<int, int> dp[20003];

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> n;
        n--;
        for(int j = 0; j < n; j++){
            cin >> routes[j];
            if(j != 0 && dp[j-1].first >= 0)
                dp[j] = make_pair(dp[j-1].first+routes[j], dp[j-1].second);
            else
                dp[j] = make_pair(routes[j], j);
        }
        int max_value = dp[0].first, max_index = 0, ans = dp[0].second;
        for(int j = 1; j < n; j++){
            if(dp[j].first > max_value){
                max_value = dp[j].first;
                max_index = j;
                ans = dp[j].second;
            }
            else if(dp[j].first == max_value && j - dp[j].second > max_index - ans){
                max_value = dp[j].first;
                max_index = j;
                ans = dp[j].second;
            }
            else if(dp[j].first == max_value && j - dp[j].second == max_index - ans && dp[j].second < ans){
                max_value = dp[j].first;
                max_index = j;
                ans = dp[j].second;
            }
        }
        if(max_value > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", i+1, ans+1, max_index+2);
        else
            printf("Route %d has no nice parts\n", i+1);
    }
}