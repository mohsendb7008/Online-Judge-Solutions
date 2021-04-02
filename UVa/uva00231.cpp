#include <bits/stdc++.h>
using namespace std;

// Testing the CATCHER

vector<int> h;
vector<int> lis;

int main(){
    int test = 1;
    bool first = true;
    int x;
    while(cin >> x){
        if(x == -1){
            if(h.empty())
                break;
            lis.clear();
            for(int i = h.size()-1; i >= 0; i--){
                auto it = upper_bound(lis.begin(), lis.end(), h[i]);
                if(it == lis.end())
                    lis.push_back(h[i]);
                else *it = h[i];
            }
            if(!first)
                cout << endl;
            first = false;
            cout << "Test #" << test++ << ":" << endl;
            cout << "  maximum possible interceptions: " << lis.size() << endl;
            h.clear();    
        }
        else h.push_back(x);
    }
}