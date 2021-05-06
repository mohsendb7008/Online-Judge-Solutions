#include <bits/stdc++.h>
using namespace std;

#define num double

vector<string> operand1, operand2, expression;
map<string, int> operator_i;

void strip(std::string& s){
    s.erase(std::remove_if(s.begin(), s.end(), ::isspace), s.end());
}

void replace_all(std::string& str, const std::string& from, const std::string& to){
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}

string encode(string& str){
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

string decode(string& str){
    string de = "";
    for(char c : str){
        if(c == '#')
            de += '-';
        else de += c;
    }
    return de;
}

vector<string> tokenize(string& str, char delim){
    stringstream ss(delim == '-' ? encode(str) : str);
    string token;
    vector<string> ans;
    while(getline(ss, token, delim))
        ans.push_back(delim == '-' ? decode(token) : token);
    return ans;
}

num eval0(string& str){ // just with ^
    vector<string> t1 = tokenize(str, '^');
    num exp = stoll(t1.back());
    for(int i = int(t1.size()) - 2; i >= 0; i--)
        exp = pow(stoll(t1[i]), exp);
    return exp;
}

 num eval1(string& str){ // just with * and / and ^
    num ans = 1;
    vector<string> t1 = tokenize(str, '*');
    for(string s : t1){
        vector<string> t2 = tokenize(s, '/');
        ans *= eval0(t2[0]);
        for(int i = 1; i < t2.size(); i++){
            num tmp = eval0(t2[i]);
            if(tmp)
                ans /= tmp;
        }
    }
    return ans;
}

num eval2(string& str){ // with + - * / ^
    num ans = 0;
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

bool is_alpha(char c){
    if(c >= 'A' && c <= 'Z')
        return true;
    if(c >= 'a' && c <= 'z')
        return true;
    return false;
}

num eval(string str){ // with () + - * / ^
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
            ans += to_string(eval(str.substr(i+1, j-i-2)));
            i = j;
        }
        else
            ans += str[i], i++;
    }
    if(any_of(ans.begin(), ans.end(), is_alpha)){
        stringstream ss(ans);
        string op1, op2, ope;
        ss >> op1 >> ope >> op2;
        int i = operator_i[ope];
        string expr = expression[i];
        replace_all(expr, operand1[i], op1);
        replace_all(expr, operand2[i], op2);
        return eval(expr); 
    }
    strip(ans);
    return eval2(ans);
}

int main(){
    string s;
    while(1){
        getline(cin, s);
        if(s == "End")
            break;
        if(s == "Add Command"){
            getline(cin, s);
            stringstream ss(s);
            string op1, op2, ope, expr;
            ss >> op1 >> ope >> op2 >> expr;
            getline(ss, expr);
            strip(expr);
            operator_i[ope] = operand1.size();
            operand1.push_back(op1);
            operand2.push_back(op2);
            expression.push_back(expr);
        }
        else if(s == "Calculate"){
            getline(cin, s);
            cout << eval(s) << endl;
        }
    }
}