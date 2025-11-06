#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a;
    n--;
    int ans = 1;
    while(n--)
    {
        cin >> b;
        if (b <= a)
        {
            cout << ans << endl;
            return 0;
        }
        ans++;
    }
    cout << "infinity" << endl;
}