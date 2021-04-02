#include <bits/stdc++.h>
using namespace std;

// Bridge

int n;
vector<int> people;
vector<pair<int, int>> output;

int main(){
    int t;
    cin >> t;
    bool first = true;
    while(t--){
        if(!first)
            cout << endl;
        first = false;
        cin >> n;
        people.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            people.push_back(x);
        }
        sort(people.begin(), people.end());
        int ans = 0;
        output.clear();
        while(true){
            if(people.size() == 1){
                ans += people[0];
                output.push_back({people[0], -1});
                break;
            }
            else if(people.size() == 2){
                ans += max(people[0], people[1]);
                output.push_back({people[0], people[1]});
                break;
            }
            else if(people.size() == 3){
                ans += people[0] + people[1] + people[2];
                output.push_back({people[0], people[1]});
                output.push_back({people[0], -1});
                output.push_back({people[0], people[2]});
                break;
            }
            else{
                int a = people[0], b = people[1], c = people[people.size()-2], d = people[people.size()-1];
                if(c + a < 2 * b){
                    people.pop_back();
                    ans += a + d;
                    output.push_back({a, d});
                    output.push_back({a, -1});
                }
                else{
                    people.pop_back();
                    people.pop_back();
                    ans += b + a + d + b;
                    output.push_back({a, b});
                    output.push_back({a, -1});
                    output.push_back({c, d});
                    output.push_back({b, -1});
                }
            }
        }
        cout << ans << endl;
        for(pair<int, int> out : output){
            if(out.second == -1)
                cout << out.first << endl;
            else cout << out.first << " " << out.second << endl;
        }
        
    }   
}