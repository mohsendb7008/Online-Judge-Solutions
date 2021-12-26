#include <bits/stdc++.h>
using namespace std;

int a[5], b[5];

int main(){
    for(int i = 0; i < 5; i++)
        cin >> a[i];
    for(int i = 0; i < 5; i++)
        cin >> b[i];
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++){
            int num = ((a[i] + b[j]) % 10) * 100 + ((a[(i+1)%5] + b[(j+1)%5]) % 10) * 10 + ((a[(i+2)%5] + b[(j+2)%5]) % 10);
            if(!(num % 6)){
                cout << "Boro joloo :)" << endl;
                return 0;
            }
        }
    cout << "Gir oftadi :(" << endl;
}