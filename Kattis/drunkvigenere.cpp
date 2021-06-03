#include <bits/stdc++.h>
using namespace std;

// Drunk Vigenère

int main(){
    string message, key;
    cin >> message >> key;
    for(int i = 0; i < message.size(); i++){
        if(i % 2)
            cout << (char)('A'+(message[i]-'A'+(key[i]-'A'))%26);
        else
            cout << (char)('A'+(message[i]-'A'-(key[i]-'A')+26)%26);
    }
    cout << endl;
}