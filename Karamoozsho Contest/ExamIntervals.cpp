#include <bits/stdc++.h>

using namespace std;

int main() 
{
    int s, f, l, x;
    cin >> s >> f >> l >> x;
    if(x < s)
        cout << "exam did not started!" << endl;
    else if(x >= f)
        cout << "exam finished!" << endl; 
    else
        cout << min(l, f - x) << endl;
    return 0;
}