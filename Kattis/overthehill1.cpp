// Over the Hill, Part 1

#include <bits/stdc++.h>
using namespace std;

int** matMul(int** a, int** b, int n, int m, int k){
  int** c = new int*[n];
  for(int i = 0; i < n; i++){
    c[i] = new int[k];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++){
      c[i][j] = 0;
      for(int s = 0; s < m; s++){
        c[i][j] += a[i][s] * b[s][j];
      }
    }
  }
  return c;
}

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
map<char, int> altoin;

int main(){
  for(int i = 0; i < alphabet.size(); i++){
    altoin[alphabet[i]] = i;
  }
  int n;
  cin >> n;
  int** cov = new int*[n];
  for(int i = 0; i < n; i++){
    cov[i] = new int[n];
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> cov[i][j];
    }
  }
  cin.ignore();
  string line;
  getline(cin, line);
  for(int i = 0; i < line.size(); i += n){
    int** vec = new int*[n];
    for(int j = 0; j < n; j++){
      vec[j] = new int[1];
      int index = i + j;
      char a = (index < line.size()) ? line[index] : ' ';
      vec[j][0] = altoin[a];
    }
    int** tr = matMul(cov, vec, n, n, 1);
    for(int j = 0; j < n; j++){
      cout << alphabet[tr[j][0] % alphabet.size()];
    }
  }
  cout << endl;
}
