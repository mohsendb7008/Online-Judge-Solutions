#include <bits/stdc++.h>
using namespace std;

// Editor Nottoobad

string last;
vector<string> words;
int ans;
vector<string> order;

int choose_best(){
    int best_match = INT_MIN, best_not_match = INT_MAX, best_index = -1;
    for(int i = 0; i < words.size(); i++){
        int match = mismatch(last.begin(), last.end(), words[i].begin()).second - words[i].begin();
        int not_match = words[i].size() - match;
        if(match > best_match){
            best_match = match;
            best_not_match = not_match;
            best_index = i;
        }
        else if(match == best_match && not_match < best_not_match){
            best_not_match = not_match;
            best_index = i;
        }
    }
    ans += best_not_match;
    return best_index;
}

int main(){
    int t, n;
    string str;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> last;
        for(int i = 0; i < n-1; i++){
            cin >> str;
            words.push_back(str);
        }
        ans = last.size();
        order.clear();
        order.push_back(last);
        while(!words.empty()){
            int index = choose_best();
            last = words[index];
            order.push_back(last);
            words.erase(next(words.begin(), index));
        }
        cout << ans << endl;
        for(string word : order)
            cout << word << endl;
    }
}