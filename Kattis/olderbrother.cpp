#include <bits/stdc++.h>
using namespace std;

// Older Brother

int q;
map<int, int> factors;

int main(){
    cin >> q;
    int bound = sqrt(q);
    for(int p = 2; p <= bound && q > 1; p++)
        while(!(q % p))
            factors[p]++, q /= p;
    if(q > 1)
        factors[q]++;
    cout << (factors.size() == 1 ? "yes" : "no") << endl;
}