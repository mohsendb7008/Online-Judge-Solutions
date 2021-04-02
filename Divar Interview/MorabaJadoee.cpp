#include <bits/stdc++.h>
using namespace std;

// Check if a permutation of 123456789 (with row-major maintain) is a magical square or not:
inline bool is_magical(string& square){
    int sum = 0; // sum of first row
    for(int i = 0; i < 3; i++)
        sum += square[i]-'0';
    if(square[0]-'0'+square[4]-'0'+square[8]-'0' != sum) // sum of left to right diagonal
        return false;
    if(square[2]-'0'+square[4]-'0'+square[6]-'0' != sum) // sum of right to left diagonal
        return false;
    int tmp;
    for(int i = 0; i < 3; i++){
        tmp = 0; // sum of i-th row
        for(int j = 0; j < 3; j++)
            tmp += square[i*3+j]-'0';
        if(tmp != sum)
            return false;
    }
    for(int j = 0; j < 3; j++){
        tmp = 0; // sum of j-th column
        for(int i = 0; i < 3; i++)
            tmp += square[i*3+j]-'0';
        if(tmp != sum)
            return false;
    }
    return true;
}

vector<string> magical_squares; // All 3*3 magical squares

int main(){
    
    // Generating all 3*3 magical squares by checking all permutations of 123456789 as an square:
    // O(n! * n) is ok since n = 9
    string square = "123456789";
    do{
        if(is_magical(square))
            magical_squares.push_back(square);
    }while(next_permutation(square.begin(), square.end()));

    string input = "", tmp;
    for(int i = 0; i < 9; i++)
        cin >> tmp, input += tmp;

    // Complete searching the best cost magical square that input square can be converted to:
    int best_cost = INT_MAX;
    for(string& candidate : magical_squares){
        int cost = 0;
        for(int i = 0; i < 9; i++)
            cost += abs(candidate[i] - input[i]);
        if(cost < best_cost)
            best_cost = cost;
    }

    cout << best_cost << endl;
}