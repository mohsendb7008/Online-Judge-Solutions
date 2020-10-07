#include <bits/stdc++.h>
using namespace std;

// Sticky Situation

int n;
long long int x;
vector<long long int> nums;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    bool p = false;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            auto lo = upper_bound(nums.begin() + j + 1, nums.end(), nums[j] - nums[i]);
            auto hi = prev(lower_bound(nums.begin() + j + 1, nums.end(), nums[j] + nums[i]));
            if(lo <= hi){
                p = true;
                break;
            }
        }
        if(p)
            break;
    }
    cout << (p ? "possible" : "impossible") << endl;
}