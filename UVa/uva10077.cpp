#include <bits/stdc++.h>
using namespace std;

// The Stern-Brocot Number System

int main(){
    int a, b;
    while(true){
        cin >> a >> b;
        if(a == 1 && b == 1)
            break;
        double query = double(a) / b;
        int leftn = 0, leftd = 1, rightn = 1, rightd = 0;
        while(true){
            double left = double(leftn) / leftd;
            double right = double(rightn) / rightd;
            int midn = leftn + rightn, midd = leftd + rightd;
            double mid = double(midn) / midd;
            if(query == mid)
                break;
            else if(query < mid){
                cout << 'L';
                rightn = midn, rightd = midd;
            }
            else{
                cout << 'R';
                leftn = midn, leftd = midd;
            }   
        }
        cout << endl;
    }
}