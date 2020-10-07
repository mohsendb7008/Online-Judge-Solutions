#include <bits/stdc++.h>
using namespace std;

// Maximum Sum (II)

vector<int> seq;
vector<int> s;

int main(){
    int n;
    while(1){
        cin >> n;
        if(!n)
            break;
        seq.clear();
        s.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            seq.push_back(x);
        }
        copy_if(seq.begin(), seq.end(), back_inserter(s), [](int x){
            return x != 0;
        });
        if(s.empty())
            cout << 0 << endl;
        else{
            for(int i = 0; i < s.size(); i++)
                cout << s[i] << (i == s.size() - 1 ? "\n" : " ");
        }
    }
}