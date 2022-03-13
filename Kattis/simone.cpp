// Simone

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int n, k, freq[maxn];
vector<int> ans;

int main(){
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    freq[x-1]++;
  }
  int mn = *min_element(freq, freq + k);
  for(int i = 0; i < k; i++){
    if(freq[i] == mn){
      ans.push_back(i+1);
    }
  }
  cout << ans.size() << endl;
  for(auto it : ans){
    cout << it << " ";
  }
  cout << endl;
}
