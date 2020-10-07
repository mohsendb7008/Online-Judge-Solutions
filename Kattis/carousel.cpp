#include <bits/stdc++.h>
using namespace std;

// Carousel Rides

int n, m;

int main(){
    while(1){
        cin >> n >> m;
        if(!(n + m))
            break;
        int a, b;
        double ans = -1;
        int ma, mb;
        while(n--){
            cin >> a >> b;
            if(a > m)
                continue;
            double curr = double(a) / b;
            if(curr > ans)
                ans = curr, ma = a, mb = b;
            else if(curr == ans && a > ma)
                ma = a, mb = b;
        }
        if(ans == -1)
            cout << "No suitable tickets offered" << endl;
        else
            cout << "Buy " << ma << " tickets for $" << mb << endl;
    }
}