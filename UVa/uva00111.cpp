#include <bits/stdc++.h>
using namespace std;

// History Grading

int n, n1, _, c = 1;
int event[23];
int nmap[23];
int mmap[23];
int order[23];
vector<int> lis;

int main(){
    while(1){
        string s;
        getline(cin, s);
        int r = sscanf(s.c_str(), "%d %d", &n1, &_);
        if(r == -1)
            break;
        if(r == 1){
            n = n1;
            c = 0;
        }
        else if(c == 0){
            stringstream ss(s);
            for(int i = 1; i <= n; i++){
                ss >> event[i];
                nmap[event[i]] = i;
            }
            for(int i = 1; i <= n; i++)
                mmap[nmap[i]] = i;
            c = 1;
        }
        else{
            lis.clear();
            stringstream ss(s);
            for(int i = 1; i <= n; i++){
                int rank;
                ss >> rank;
                order[rank] = i;
            }
            for(int i = 1; i <= n; i++){
                int x = mmap[order[i]];
                auto it = upper_bound(lis.begin(), lis.end(), x);
                if(it == lis.end())
                    lis.push_back(x);
                else *it = x;
            }
            cout << lis.size() << endl;
        }
    }
}