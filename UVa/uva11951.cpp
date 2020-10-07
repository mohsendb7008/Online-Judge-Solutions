#include <bits/stdc++.h>
using namespace std;

// Area

#define num long long int

int n, m, k;
int a[103][103];
num psum[103][103];

int main(){
    int t;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                psum[i][j] = a[i][j];
                if(i > 0)
                    psum[i][j] += psum[i-1][j];
                if(j > 0)
                    psum[i][j] += psum[i][j-1];
                if(i > 0 && j > 0)
                    psum[i][j] -= psum[i-1][j-1];
            }
        int max_area = 0;
        num max_price = 0;
        for(int x1 = 0; x1 < n; x1++)
            for(int y1 = 0; y1 < m; y1++)
                for(int x2 = x1; x2 < n; x2++)
                    for(int y2 = y1; y2 < m; y2++){
                        int area = (x2 - x1 + 1) * (y2 - y1 + 1);
                        int price = psum[x2][y2];
                        if(y1 > 0)
                            price -= psum[x2][y1-1];
                        if(x1 > 0)
                            price -= psum[x1-1][y2];
                        if(x1 > 0 && y1 > 0)
                            price += psum[x1-1][y1-1];
                        if(price <= k){
                            if(area > max_area){
                                max_area = area;
                                max_price = price;
                            }
                            if(area == max_area && price < max_price)
                                max_price = price;
                        }
                    }
        printf("Case #%d: %d %d\n", test, max_area, max_price);
    }
}