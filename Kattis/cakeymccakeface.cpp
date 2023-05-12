#include <iostream>
#include <map>
#include <iterator>
using namespace std;

// Cakey McCakeFace

int N, M, a[2003], b[2003];
map<int, int> counter;

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < M; i++){
        cin >> b[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(b[j] >= a[i]){
                counter[b[j] - a[i]]++;
            }
        }
    }
    int target = 0;
    int ans = 0;
    for(map<int, int>::iterator it = counter.begin(); it != counter.end(); it++){
        if(it->second > target){
            target = it->second;
            ans = it->first;
        }
    }
    cout << ans << endl;
}