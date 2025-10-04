#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()){
        if (a[i] < b[j])
            cout << a[i++];
        else
            cout << b[j++];
    }
    while(i < a.size())
        cout << a[i++];
    while(j < b.size())
        cout << b[j++];
    cout << endl;
}