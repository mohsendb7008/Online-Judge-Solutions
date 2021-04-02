#include <bits/stdc++.h>
using namespace std;

// Nice Numbers

vector<string> splitb(string in, char delim){
    vector<string> ans;
    int i = 0, j = 0;
    while(j < in.size()){
        if(in[j] != delim)
            j++;
        else{
            if(i < j)
                ans.push_back(in.substr(i, j - i));
            ans.push_back(to_string(delim - '0'));
            j++;
            i = j;
        }
    }
    if(i < j)
        ans.push_back(in.substr(i, j - i));
    return ans;
}

pair<string, int> twos(string in){
    return {(in.size() % 2) ? ("2" + in) : in, (in.size() + 1) / 2};
}

pair<string, int> fours(string in){
    int cnt = 0;
    string u = "";
    vector<string> sp = splitb(in, '4');
    for(string s : sp){
        if(s == "4")
            cnt++, u += s;
        else{
            pair<string, int> two = twos(s);
            cnt += two.second, u += two.first;
        }
    }
    return {(cnt % 2) ? ("4" + u) : u, (cnt + 1) / 2};
}

vector<int> po2;

string eights(string in){
    int cnt = 0;
    string u = "";
    vector<string> sp = splitb(in, '8');
    for(string s : sp){
        if(s == "8")
            cnt++, u += s;
        else{
            pair<string, int> four = fours(s);
            cnt += four.second, u += four.first;
        }
    }
    string pref = "";
    int prefc = (*lower_bound(po2.begin(), po2.end(), cnt)) - cnt;
    while(prefc--)
        pref += "8";
    return pref + u;
}

int main(){
    for(int i = 0; i <= 30; i++)
        po2.push_back(1 << i);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s == "2" || s == "4" || s == "22"){
            cout << s << endl;
            continue;
        }
        reverse(s.begin(), s.end());
        string ans = eights(s);
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}