#include <bits/stdc++.h>

// Game Rank

inline int stars(int rank){
    if(rank <= 10)
        return 5;
    else if(rank <= 15)
        return 4;
    else if(rank <= 20)
        return 3;
    else
        return 2;
}

int rank = 25, star = 0, wins = 0, loses = 0;

void win(){
    if(!rank)
        return;
    star++;
    if(rank >= 6 && wins >= 3)
        star++;
    if(star > stars(rank))
        rank--, star -= stars(rank+1);
}

void lose(){
    if(!rank)
        return;
    if(rank == 20)
        star = std::max(star - 1, 0);
    else if(rank < 20){
        star--;
        if(star == -1)
            rank++, star = stars(rank) - 1;
    }
}

int main(){
    std::string s;
    std::cin >> s;
    for(char c : s){
        if(c == 'W'){
            if(wins)
                wins++;
            else 
                loses = 0, wins = 1;
            win();
        }
        else{
            if(loses)
                loses++;
            else
                loses = 1, wins = 0;
            lose();
        }
    }
    if(rank)
        std::cout << rank << std::endl;
    else
        std::cout << "Legend" << std::endl;   
}