#include <bits/stdc++.h>
using namespace std;

// The SetStack Computer

int cnt = 0;
map<set<int>, int> id;
int sid(set<int>& s){
    auto it = id.find(s);
    if(it == id.end())
        return id[s] = cnt++;
    return id[s];
}

int t, n;
char tmp[13];
string cmd;
set<int> emp;
stack<set<int>> st;

int main(){
    scanf("%d", &t);
    while(t--){
        cnt = 0, id.clear(), sid(emp);
        while(!st.empty())
            st.pop();
        scanf("%d", &n);
        while(n--){
            scanf("%s", tmp), cmd = string(tmp);
            if(cmd == "PUSH")
                st.push(emp);
            else if(cmd == "DUP")
                st.push(st.top());
            else if(cmd == "ADD"){
                int cp = sid(st.top());
                st.pop();
                st.top().insert(cp);
            }
            else if(cmd == "UNION"){
                set<int> s1 = st.top(), un;
                st.pop();
                set_union(s1.begin(), s1.end(), st.top().begin(), st.top().end(), inserter(un, un.begin()));
                st.pop(), st.push(un);
            }
            else if(cmd == "INTERSECT"){
                set<int> s1 = st.top(), in;
                st.pop();
                set_intersection(s1.begin(), s1.end(), st.top().begin(), st.top().end(), inserter(in, in.begin()));
                st.pop(), st.push(in);
            }
            printf("%d\n", st.top().size());
        }
        printf("***\n");
    }
}