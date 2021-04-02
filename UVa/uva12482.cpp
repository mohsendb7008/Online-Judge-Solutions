#include <bits/stdc++.h>
using namespace std;

// Short Story Competition

int n, L, C;
int page, line, ptr;

inline void increaseLine(){
    ptr = 0;
    line++;
    if(line == L+1){
        line = 1;
        page++;
    }
}

inline void processWord(int wsize){
    if(ptr >= C)
            increaseLine();
    if(wsize <= C - ptr){
        ptr += wsize;
        ptr++;
    }
    else{
        increaseLine();
        processWord(wsize);
    }
}

int main(){
    while(cin >> n){
        cin >> L >> C;
        page = 1, line = 1, ptr = 0;
        string tmp;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            processWord(tmp.size());
        }
        cout << page << endl;
    }
}