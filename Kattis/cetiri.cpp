#include <bits/stdc++.h>
using namespace std;

// Cetiri

int ap[3];

int main(){
    cin >> ap[0] >> ap[1] >> ap[2];
    sort(ap, ap + 3);
    if(ap[2] - ap[1] > ap[1] - ap[0])
        cout << (ap[1] + ap[2]) / 2 << endl;
    else if(ap[2] - ap[1] < ap[1] - ap[0])
        cout << (ap[0] + ap[1]) / 2 << endl;
    else
        cout << ap[0] - (ap[1] - ap[0]) << endl;
}