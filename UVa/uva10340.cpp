#include <bits/stdc++.h>
using namespace std;

// All in All

inline bool isSub(string main, string sub){
    int ptr = 0, m_end = main.size();
    for(char c : sub){
        bool flag = false;
        while(ptr != m_end){
            if(main[ptr] == c){
                flag = true;
                ptr++;
                break;
            }
            else ptr++;
        }
        if(!flag) return false;
    }
    return true;
}

int main(){
    string sub, main;
    while(cin >> sub){
        cin >> main;
        cout << (isSub(main, sub) ? "Yes" : "No") << endl;
    }
}