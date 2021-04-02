#include <bits/stdc++.h>
using namespace std;

// N + NOD(N)

vector<int> sequence;

inline int nod(int x){
    int cnt = 0;
    int lim = sqrt(x);
    for(int y = 1; y <= lim; y++)
        if(x % y == 0){
            if(y == x / y)
                cnt += 1;
            else cnt += 2;
        }
    return cnt;
}

int main(){
    sequence.push_back(1);
    while(11876){
        int element = sequence[sequence.size()-1] + nod(sequence[sequence.size()-1]);
        if(element > 1000000)
            break;
        sequence.push_back(element);
    }
    int t, A, B;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> A >> B;
        cout << "Case " << test << ": " << upper_bound(sequence.begin(), sequence.end(), B) - lower_bound(sequence.begin(), sequence.end(), A) << endl;   
    }
}