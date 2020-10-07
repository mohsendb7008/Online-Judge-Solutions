#include <bits/stdc++.h>
using namespace std;

// Twenty Four, Again

// encode and decode for unary - operator

string encode(string str){
    string en = "";
    en += (str[0] == '-') ? '#' : str[0];
    for(int i = 1; i < str.size(); i++){
        if(str[i] == '-' && (str[i+1] >= '0' && str[i+1] <= '9') && !(str[i-1] >= '0' && str[i-1] <= '9'))
            en += '#';
        else 
            en += str[i];
    }
    return en;
}

string decode(string str){
    string de = "";
    for(char c : str){
        if(c == '#')
            de += '-';
        else de += c;
    }
    return de;
}

vector<string> tokenize(string str, char delim){
    stringstream ss(delim == '-' ? encode(str) : str);
    string token;
    vector<string> ans;
    while(getline(ss, token, delim))
        ans.push_back(delim == '-' ? decode(token) : token);
    return ans;
}

bool ok;

int eval1(string str){ // just with * and /
    int ans = 1;
    vector<string> t1 = tokenize(str, '*');
    for(string s : t1){
        vector<string> t2 = tokenize(s, '/');
        ans *= stoi(t2[0]);
        for(int i = 1; i < t2.size(); i++){
            int tmp = stoi(t2[i]);
            if(!tmp || ans % tmp)
                ok = false;
            if(tmp)
                ans /= stoi(t2[i]);
        }
    }
    return ans;
}

int eval2(string str){ // with + - * /
    int ans = 0;
    vector<string> t1 = tokenize(str, '+');
    for(string s : t1){
        vector<string> t2 = tokenize(s, '-');
        if(t2[0] != "")
            ans += eval1(t2[0]);
        for(int i = 1; i < t2.size(); i++)
            ans -= eval2(t2[i]);
    }
    return ans;
}

int eval(string str){ // with () + - * /
    string ans = "";
    int i = 0;
    while(i < str.size()){
        if(str[i] == '('){
            int cnt = 1, j = i + 1;
            while(cnt){
                if(str[j] == '(')
                    cnt++;
                else if(str[j] == ')')
                    cnt--;
                j++;
            }
            ans += to_string(eval(str.substr(i+1, j-i-1)));
            i = j;
        }
        else
            ans += str[i], i++;
    }
    return eval2(ans);
}

char ops[4]{'+', '-', '*', '/'};
vector<string> operms;
char tmp[3];

void track(int i){
    if(i == 3){
        operms.push_back(string(tmp));
        return;
    }
    for(int k = 0; k < 4; k++)
        tmp[i] = ops[k], track(i+1);
}

int swaps(vector<int> v){
    int ans = 0;
    for(int k = 0; k < 4; k++)
        for(int i = 0; i < 3; i++)
            if(v[i] > v[i+1])
                ans++, swap(v[i], v[i+1]);
    return ans;
}

vector<string> para{
    "axbyczd",
    "(axb)yczd",
    "(axbyc)zd",
    "ax(byc)zd",
    "ax(byczd)",
    "axby(czd)",
    "(axb)y(czd)",
    "ax((byc)zd)",
    "ax(by(czd))",
    "((axb)yc)zd",
    "(ax(byc))zd"
};


int nums[4];

int check(string p, vector<int> perm, string operm){
    int score = count(p.begin(), p.end(), '(') + 2 * swaps(perm);
    string exp = "";
    for(char c : p){
        if(c >= 'a' && c <= 'd')
            exp += to_string(nums[perm[c - 'a']]);
        else if(c >= 'x' && c <= 'z')
            exp += operm[c - 'x'];
        else exp += c;
    }
    ok = true;
    int res = eval(exp);
    if(!ok || res != 24)
        return 1000;
    return score;
}


int main(){
    track(0);
    for(int i = 0; i < 4; i++)
        cin >> nums[i];
    int ans = 1000;
    vector<int> ind{0, 1, 2, 3};
    do{
        for(string p : para)
            for(string o : operms)
                ans = min(ans, check(p, ind, o));
    }while(next_permutation(ind.begin(), ind.end()));
    if(ans == 1000)
        cout << "impossible" << endl;
    else 
        cout << ans << endl;
}