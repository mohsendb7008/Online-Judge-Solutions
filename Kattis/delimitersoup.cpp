// Delimiter Soup

#include <bits/stdc++.h>
using namespace std;

stack<char> st;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  string line;
  getline(cin, line);
  for(int i = 0; i < n; i++){
    char c = line[i];
    if (c == ' '){
      continue;
    }
    if(c == '[' || c == '{' || c == '('){
      st.push(c);
    }
    else if(st.empty()) {
        cout << c << " " << i << endl;
        return 0;
    }
    else if(c == ']'){
        if(st.top() != '['){
            cout << c << " " << i << endl;
            return 0;
        }
        st.pop();
    }
    else if(c == '}'){
        if(st.top() != '{'){
            cout << c << " " << i << endl;
            return 0;
        }
        st.pop();
    }
    else if(c == ')'){
        if(st.top() != '('){
            cout << c << " " << i << endl;
            return 0;
        }
        st.pop();
    }
  }
  cout << "ok so far" << endl;
}
