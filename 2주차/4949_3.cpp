#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (stk.size()) {
            if (stk.top() == '(' && s[i] == ')') stk.pop();
            else if (stk.top() == '[' && s[i] == ']') stk.pop();
            else if (s[i] == '(' || s[i] == '[' || s[i] == ')' || s[i] == ']') stk.push(s[i]);
        } else {
            if (s[i] == ')' || s[i] == ']') return false;
            else if (s[i] == '(' || s[i] == '[' || s[i] == ')' || s[i] == ']') stk.push(s[i]);
        }
    }

    return stk.empty();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while (true) {
        getline(cin, s);
        if (s.size() == 1 && s[0] == '.') break;

        if (check(s)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}