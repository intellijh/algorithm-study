#include <bits/stdc++.h>
using namespace std;

string temp, s;

bool check(string s) {
    stack<char> stk;

    for (char a : s) {
        if (a == '(') stk.push(a);
        else if (a == ')') {
            if (stk.empty()) return false;
            else {
                if (stk.top() == '(') stk.pop();
                else return false;
            }
        }
        else if (a == '[') stk.push(a);
        else if (a == ']') {
            if (stk.empty()) return false;
            else {
                if (stk.top() == '[') stk.pop();
                else return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while (true) {
        getline(cin, s);
        if (s == ".") break;

        if (check(s)) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}