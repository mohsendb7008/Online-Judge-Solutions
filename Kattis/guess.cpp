#include <bits/stdc++.h>
using namespace std;

// Guess The Number

int main(){
     int start = 1, end = 1000;
     string response;
     while(1){
        int mid = (start + end) / 2;
        cout << mid << endl;
        cout.flush();
        cin >> response;
        if(response == "correct")
            break;
        else if(response == "lower")
            end = mid - 1;
        else if(response == "higher")
            start = mid + 1;
     }
}