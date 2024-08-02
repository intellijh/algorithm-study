#include <bits/stdc++.h>
using namespace std;

int T;
string s;

bool check(string s) {
    stack<char> stk;
    for (char a : s) {
        if (a == '(') stk.push(a);
        else {
            if (stk.empty()) return false;
            else stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> T;
    while (T--) {
        cin >> s;

        if (check(s)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}