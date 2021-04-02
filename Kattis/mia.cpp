#include <bits/stdc++.h>
using namespace std;

// Mia

map<int, int> score;
int h[7]{21, 66, 55, 44, 33, 22, 11};
int a, b, c, d;

int main(){
    for(int i = 0; i < 7; i++)
        score[h[i]] = i;
    int cnt = 7;
    for(int i = 6; i >= 3; i--)
        for(int j = i-1; j >= 1; j--)
            score[i * 10 + j] = cnt++;
    while(cin >> a >> b >> c >> d){
        if(a + b + c + d == 0)
            break;
        int a1 = max(a, b) * 10 + min(a, b);
        int b1 = max(c, d) * 10 + min(c, d);
        if(a1 == b1)
            cout << "Tie." << endl;
        else if(score[a1] < score[b1])
            cout << "Player 1 wins." << endl;
        else cout << "Player 2 wins." << endl;
    }
}