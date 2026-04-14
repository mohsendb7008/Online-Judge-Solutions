#include <iostream>
#include <string>
#include <stack>
#include <set>

using namespace std;

string expression;
stack<int> bracketId;
int id[201];
set<string> bucket;

int main() {
    cin >> expression;
    int counter = 0;
    for (int i = 0; i < expression.size(); i++) {
        const char c = expression[i];
        if (c == '(') {
            id[i] = counter;
            bracketId.push(counter);
            counter++;
        } else if (c == ')') {
            id[i] = bracketId.top();
            bracketId.pop();
        }
    }
    for (int mask = 0; mask < (1 << counter) - 1; mask++) {
        string possibleExpression;
        for (int i = 0; i < expression.size(); i++) {
            const char c = expression[i];
            if ((c == '(' || c == ')') && !(mask & 1 << id[i]))
                continue;
            possibleExpression.push_back(c);
        }
        bucket.insert(possibleExpression);
    }
    for (const string &possibleExpression : bucket) {
        cout << possibleExpression << endl;
    }
}