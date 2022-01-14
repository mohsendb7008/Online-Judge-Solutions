// Grading

#include <bits/stdc++.h>
using namespace std;

int a[5], x;

int main(){
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    cin >> x;
    if(x >= a[0]){
    	cout << 'A' << endl;
    	return 0;
    }
    if(x < a[4]){
    	cout << 'F' << endl;
    	return 0;
    }
    for(int i = 1; i < 5; i++){
        if(x >= a[i] && x < a[i-1]){
            cout << char('A' + i) << endl;
            break;
        }
    }
}
