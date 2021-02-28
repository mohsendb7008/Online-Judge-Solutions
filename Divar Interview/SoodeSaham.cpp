#include <bits/stdc++.h>
using namespace std;

const int max_number_of_days = 1000;

int number_of_days;
int stocks[max_number_of_days];

int main(){
    cin >> number_of_days;
    for(int day = 0; day < number_of_days; day++)
        cin >> stocks[day];
    int best_profit = 0;
    // Complete Search: (O(n ^ 2) is good for n <= 1000)
    for(int buy_day = 0; buy_day < number_of_days; buy_day++)
        for(int sell_day = buy_day + 1; sell_day < number_of_days; sell_day++)
            if(stocks[buy_day] < stocks[sell_day]){ // If there's a significant profit
                int profit = stocks[sell_day] - stocks[buy_day];
                if(profit > best_profit)
                    best_profit = profit;
            }
    cout << best_profit << endl;
}