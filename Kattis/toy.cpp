#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> point;

point nowhere = {-1, -1};
pair<point, point> none = {nowhere, nowhere};

int n, segments[10], unused, ori[2]{-1, 1};
pair<point, point> drawing[100];
vector<int> trs[10000];
double best = 0.0;

inline bool check_triangle(const int& a, const int& b, const int& c){
  return a + b > c && a + c > b && b + c > a;
}

inline point third_point(const double& a, const double& b, const double& c){
  double x = (c * c - b * b + a * a) / (2 * a);
  double y = sqrt(c * c - x * x);
  return {x, y};
}

inline point rotate(const double& x, const double& y, const double& m){
  double cos2 = 1.0 / (m * m + 1);
  double cos = sqrt(cos2);
  double sin = sqrt(1.0 - cos2);
  if (m < 0){
    sin *= -1;
  }
  return {x * cos - y * sin, x * sin + y * cos};
}

void explore(bool first){
  if (unused < 2){
    return;
  }
  for(int i = 0; i < n; i++){
    int b = segments[i];
    if (drawing[b] == none){
      int sj = first ? i + 1 : 0;
      for(int j = sj; j < n; j++){
        int c = segments[j];
        if (b != c && drawing[c] == none){
          for(int a: trs[b * 100 + c]){
            if (drawing[a] != none){
              point A = drawing[a].first;
              point B = drawing[a].second;
              for(int orientation: ori){
                point C = third_point(a, b, c);
                C.second *= orientation;
                double dy = B.second - A.second;
                double dx = B.first - A.first;
                if (fabs(dx) < 1e-7) {
                  C = {-C.second, C.first};
                } else {
                  double m = dy / dx;
                  C = rotate(C.first, C.second, m);
                }
                C.first += A.first;
                C.second += A.second;
                if (C.second < 0) {
                  continue;
                }
                if (C.second > best) {
                  best = C.second;
                }
                pair<point, point> con1 = {min(A, C), max(A, C)};
                pair<point, point> con2 = {min(C, B), max(C, B)};
                drawing[c] = con1;
                drawing[b] = con2;
                unused -= 2;
                explore(false);
                unused += 2;
                drawing[b] = none;
                drawing[c] = none;
              }
            }
          }
        }
      }
    }
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> segments[i];
  }
  unused = n;
  for(int a: segments){
    for(int b: segments){
      for(int c: segments){
        if(a != b && b != c && check_triangle(a, b, c)){
          trs[a * 100 + b].push_back(c);
        }
      }
    }
  }
  for(int i = 0; i < n; i++){
    drawing[segments[i]] = none;
  }
  for(int i = 0; i < n; i++){
    drawing[segments[i]] = {{0, 0}, {segments[i], 0}};
    unused--;
    explore(true);
    unused++;
    drawing[segments[i]] = none;
  }
  cout << best << endl;
}