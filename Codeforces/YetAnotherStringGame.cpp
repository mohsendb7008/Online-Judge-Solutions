#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
       string s;
       cin >> s;
       for(int i = 0; i < s.size(); i++){
           if(i % 2){
                if(s[i] == 'z')
                    cout << 'y';
                else
                    cout << 'z';
           }
           else{
               if(s[i] == 'a')
                    cout << 'b';
                else
                    cout << 'a';
           }
       }
       cout << endl; 
    }
}