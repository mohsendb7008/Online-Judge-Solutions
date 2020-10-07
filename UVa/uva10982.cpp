#include <bits/stdc++.h>
using namespace std;

// Troublemakers

int n, m;
bool bad[103][103];
vector<int> A, B;

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                bad[i][j] = false;
        int x, y;
        while(m--)
            cin >> x >> y, bad[x-1][y-1] = bad[y-1][x-1] = true;
        A.clear();
        B.clear();
        for(int i = 0; i < n; i++){
            int ca = 0, cb = 0;
            for(int j : A)
                if(bad[i][j])
                    ca++;
            for(int j : B)
                if(bad[i][j])
                    cb++;
            if(cb < ca)
                B.push_back(i);
            else A.push_back(i);
        }
        cout << "Case #" << test << ": " << A.size() << endl;
        for(int i = 0; i < A.size() - 1; i++)
            cout << A[i] + 1 << " ";
        cout << A[A.size()-1] + 1 << endl;    
    }
}