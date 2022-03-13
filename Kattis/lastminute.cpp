// Last Minute

#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int au, bu, ar, br;
  cin >> au >> bu >> ar >> br;
  if(ar && br){
    cout << au + bu + ar * br << endl;
  }else if(ar){
    cout << bu << endl;
  }else if(br){
    cout << au << endl;
  }else{
    cout << min(au, bu) << endl;
  }
}
