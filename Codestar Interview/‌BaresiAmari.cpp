#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main(){
    while(1){
        string s;
        cin >> s;
        if(s == "---")
            break;
        a.push_back(stoi(s));
    }
    int mina = *min_element(a.begin(), a.end());
    int maxa = *max_element(a.begin(), a.end());
    int avg = 0, cnt = 0;
    for(int i : a)
        if(i != mina && i != maxa)
            avg += i, cnt++;
    if(!cnt)
        avg = 100;
    else
        avg = avg / cnt + ((avg % cnt) ? 1 : 0);
    int happy = 0;
    int sad = 0;
    for(int i : a){
        if(i < avg)
            happy++;
        else if(i > avg)
            sad++;
    }
    for(int i = 1; i <= happy; i++){
        cout << ":";
        for(int j = 1; j <= i; j++)
            cout << ")";
        cout << " ";
    }
    cout << endl;
    for(int i = 1; i <= sad; i++){
        cout << ":";
        for(int j = 1; j <= i; j++)
            cout << "(";
        cout << " ";
    }
    cout << endl;
}