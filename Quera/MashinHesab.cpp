#include <bits/stdc++.h>
using namespace std;

#define lli long long int

string s;
vector<lli> positive;
vector<lli> negative;

int main(){
    cin >> s;
    lli num;
    int pos = -1;
    for(char c : s){
        if(c == '+'){
            if(pos != -1){
                if(pos)
                    positive.push_back(num);
                else
                    negative.push_back(num);
            }
            num = 0;
            pos = 1;
        }
        else if(c == '-'){
            if(pos != -1){
                if(pos)
                    positive.push_back(num);
                else
                    negative.push_back(num);
            }
            num = 0;
            pos = 0;
        }
        else if(c >= '0' && c <= '9'){
            num = (num * 10) + (c - '0');
        }
    }
    if(pos)
        positive.push_back(num);
    else
        negative.push_back(num);
    sort(positive.begin(), positive.end(), greater<lli>());
    sort(negative.begin(), negative.end());
    lli sum = 0;
    int ptr = min(positive.size(), negative.size());
    for(int i = 0; i < ptr; i++){
        cout << "+" << positive[i] << "-" << negative[i];
        sum += positive[i] - negative[i];
    }
    if(positive.size() > negative.size()){
        if(positive[ptr] > sum){
            cout << "-" << positive[ptr];
            sum -= positive[ptr];
            for(int i = ptr + 1; i < positive.size(); i++){
                cout << "+" << positive[i];
                sum += positive[i];
            }
        }
        else{
            for(int i = ptr; i < positive.size(); i++){
                cout << "+" << positive[i];
                sum += positive[i];
            }
        }
    } else if(negative.size() > positive.size()){
        if(sum < 0){
            cout << "+" << negative.back();
            sum += negative.back();
            for(int i = ptr; i < int(negative.size()) - 1; i++){
                cout << "-" << negative[i];
                sum -= negative[i];
            }
        }
        else{
            for(int i = ptr; i < negative.size(); i++){
                cout << "-" << negative[i];
                sum -= negative[i];
            }
        }
    }
    cout << "=" << sum << endl;
}